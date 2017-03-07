#include<bits/stdc++.h>
using namespace std;

#define LL    long long 
#define ff    first 
#define ss    second
#define pb    push_back
#define mp    make_pair 

const int M = 100007;
const int MOD = 1000000000 + 7;

vector<LL> F(M); 
LL cnt[26];
int main(){
	F[0]=1;
	for(int i=1;i<M;i++){
		F[i]=F[i-1]*i;
		if(F[i]>=MOD)
		F[i]%=MOD;
	}
	int t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		memset(cnt,0,sizeof (cnt));
		for(int i=0;i<(int)s.length();i++){
			cnt[s[i]-'a']++;
		}
		LL var=0,ans=1;
		for(int i=0;i<26;i++){
			//cout<< cnt[i] <<endl;
			if(cnt[i]){
				++var;
				ans*=F[cnt[i]];
				if(ans>=MOD) 
				ans%=MOD;
			}
		}
		cout<< (ans*F[var])%MOD <<endl;
	}
	return 0;
}
