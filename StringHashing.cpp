/*
 * Codeforces:
 * H. Queries for Number of Palindromes
 */
#include <bits/stdc++.h>
using namespace std;

#define LL   long long
#define gc   getchar
#define PII  pair<int, int>
#define ff   first
#define ss   second


inline void inp(int &x){
	register int c=gc();x=0;bool neg=0;for(;((c<48||c>57)&&c!='-');
	c=gc());if(c=='-'){neg=1;c=gc();}for(;c>47&&c<58;c=gc()){x=(x*10)+(c-48);}
	if(neg)x=-x;
}


const int M = 5e3  + 5;
const LL MOD1 = 1e9 + 7;
const LL MOD2 = 1e9 + 21;
const LL P = 111719239; 

int dp[M][M];
PII pre[M], suf[M], inv[M];
int len;

int add(const LL &a, const LL &b, const LL &MOD){
	LL x = a + b;
	return (x >= MOD) ? (x-MOD) : x;
}
int mul(const LL &a, const  LL &b, const LL &MOD){
	LL x = (a * b);
	return (x >= MOD) ? (x % MOD) : x;
}
int sub(const LL &a, const LL &b, const LL &MOD){
	int x = a - b;
	return (x < 0) ? (x  + MOD) : x;
}

		
int modexp(LL a, LL b, const LL &MOD){
	LL res = 1;
	while(b > 0){
		if(b & 1){
			res = mul(res, a, MOD);
		}
		a = mul(a, a, MOD);
		b >>= 1;
	}
	return res;
}

void calHash(char *s){
	for(int i = 0; i < M; i++){
		inv[i].ff = modexp(P, MOD1 - i - 1, MOD1);
		inv[i].ss = modexp(P, MOD2 - i - 1, MOD2);
	}
	int l = strlen(s);
	PII prod = make_pair(P, P);
	for(int i = 1; i <= l; i++){
		pre[i].ff = add(pre[i-1].ff, mul(s[i-1], prod.ff, MOD1), MOD1);
		pre[i].ss = add(pre[i-1].ss, mul(s[i-1], prod.ss, MOD2), MOD2);
		prod.ff = mul(prod.ff, P, MOD1);
		prod.ss = mul(prod.ss, P, MOD2);
	} 
	
	prod = make_pair(P, P);
	for(int i = l; i >= 1; i--){
		suf[i].ff = add(suf[i+1].ff, mul(s[i-1], prod.ff, MOD1), MOD1);
		suf[i].ss = add(suf[i+1].ss, mul(s[i-1], prod.ss, MOD2), MOD2);
		prod.ff = mul(prod.ff, P, MOD1);
		prod.ss = mul(prod.ss, P, MOD2);
	} 	
}

PII getForward(const int &l, const int &r){
	PII x;
	x.ff = mul(sub(pre[r].ff, pre[l-1].ff, MOD1), inv[l-1].ff, MOD1);
	x.ss = mul(sub(pre[r].ss, pre[l-1].ss, MOD2), inv[l-1].ss, MOD2);
	return x;
}

PII getBackward(const int &l, const int &r){
	PII x;
	x.ff = mul(sub(suf[l].ff, suf[r+1].ff, MOD1), inv[len - r].ff, MOD1);
	x.ss = mul(sub(suf[l].ss, suf[r+1].ss, MOD2), inv[len - r].ss, MOD2);
	return x;
}

char s[M];
int main(){
	scanf("%s", s);
	calHash(s);
	len = strlen(s);
	for(int i = 1; i <= len; i++){
		for(int j = i; j <= len; j++){
			PII x = getForward(i, j);
			PII y = getBackward(i, j);
			if(x.ff == y.ff && x.ss == y.ss){
				dp[i][j] = 1;
			}
		} 
	}
	for(int i = 1; i <= len; i++){
		for(int j = 1; j <= len; j++){
			dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	}

	int q, l, r;
	inp(q);
	while(q--){
		inp(l), inp(r);
		printf("%d\n", dp[r][r] - dp[l-1][r] - dp[r][l-1] + dp[l-1][l-1]);
	}
	return 0; 
}
