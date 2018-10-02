#include<bits/stdc++.h>
using namespace std;

typedef             long long int        LL;
typedef             pair<int,int>        PII;
typedef             vector<PII>          VPII;
typedef             vector<int>          VI;
typedef             vector<VI>           VVI;
typedef             vector<string>       VS;
typedef             priority_queue<int>  PQ;

const int R  = 1e8 + 7;
const int M  = 1e4 + 7;
const LL MOD = 1e9 + 7;

template<typename T>
void inp(T &x){
	register T c = gc();
	x = 0;
	bool neg = 0;
	for(;((c < '0' || c > '9') && c != '-');
	c = gc());
	if(c == '-'){
		neg = 1;
		c = gc();
	}
	for(;c >= '0' && c <= '9'; c = gc()){
		x = (x * 10) + (c - '0');
	}
	if(neg){
		x = -x;
	}
}


inline LL modexp(LL a, LL b, const LL &MOD){
	LL x = 1;
	while(b > 0){
		if(b & 1){
			x = (x * a) % MOD;
		}
		b >>= 1;
		a  = (a * a) % MOD;
	}
	return x;
}


inline LL mulmod(LL a,LL b,const LL &mod){
	LL x = 0;
	a %= mod;
	while(b > 0){
		if(b & 1){
			x += a;
			if(x >= mod){
				x -= mod;
			}
		}
		b >>= 1;
		a <<= 1;
		if(a >= mod){
			a -= mod;
		}
	}
	return x;
}


inline vector<vector<int> > combination(){
	vector<vector<int> > dp(M + 1, VI(M + 1, 0));
	dp[0][0] = 1;
	for(register int i = 1; i < M; i++){
		for(register int j = 0; j <= i/2; j++){
			if(j == 0){
				dp[i][j] = dp[i][i] = 1;
			}
			else{
				dp[i][j] = dp[i][i-j] = (dp[i-1][j] + dp[i-1][j-1]);
				if(dp[i][j] >= MOD){
					dp[i][j] -= MOD;
					dp[i][i-j] -= MOD;
				}
			}
		}
	}
  return dp;
}


inline LL combination(const LL &N, LL R){
	if(R > N) return 0;
	R > (N - R) ? (R = N - R) : R;
	LL mul = 1;
	for(LL i = 0; i < R; i++){
		mul = ((mul * (N - i)) % MOD) * modexp(i + 1, MOD - 2, MOD);
		if(mul >= MOD){
			mul %= MOD;
		}
	}
	return mul;
}


inline LL Lucas(LL n,LL r){
	if(n == 0 && r == 0) return 1;
	LL x = n % MOD;
	LL y = r % MOD;
	if(y > x) return 0;
	return Lucas(n / MOD, r / MOD) * combination(x, y);
}


vector<LL> catalan(M, 0);
inline void genCat(){
	catalan[0] = catalan[1] = 1;
	for(register int i = 2; i < M; i++){
		for(register int j = 0; j < i; j++){
			catalan[i] += (catalan[j] * catalan[i - j - 1]) % MOD;
			if(catalan[i] >= MOD){
				catalan[i] -= MOD;
			}
		}
	}
}


vector<LL> fact(R);
inline void factorial(){
	for(int i = 1; i < R; i++){
		fact[i] = fact[i - 1] * i;
		if(fact[i] >= MOD){
			fact[i] %= MOD;
		}
	}
}


inline bool isPrime(const LL &x){
	if( x<= 3) return(x <= 1 ? 0 : 1);
	if(!(x & 1) || !(x % 3)) return 0;
	for(LL i = 5; i * i <= x; i += 6){
		if(!(x % i) || !(x % (i + 2))){
			return 0;
		}
	}
	return 1;
}


bool isprime[R];
vector<int> prime;
inline void sieve(){
	for(register int i = 2; i * i <= R; ++i){
		if(!isprime[i]){
			prime.push_back(i);
			for(register int j = i << 1; j < R; j += i){
				if(!isprime[j]){
					isprime[j] = 1;
				}
			}
		}
	}
}


int ETF[R];
inline void ETF_sieve(){
	for(register int i = 1; i < R; ++i){
		ETF[i] = i;
	}
	for(register int i = 2; i < R; ++i){
		if(ETF[i] == i){
			ETF[i] = i - 1;
			for(int j = i << 1; j < R; j += i){
				ETF[j]=((i - 1) * ETF[j]) / i;
			}
		}
	}
}


int main(){
}
