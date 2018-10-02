#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const int M = 1e3 + 5;
long long dp[M];
long long chordCnt(int A){
	if(A <= 1) return 1 ;
	long long &ret = dp[A];
	if(ret != -1) return ret;
	ret = 0;
	for(int i=0;i<A;i++){
		ret = (ret + chordCnt(i) * chordCnt(A - i - 1))%MOD;
	}
	return ret;
} 


int main(){
	int n;
	memset(dp, -1, sizeof dp);
	while(1){
		cin>>n;
		cout<<chordCnt(n)<<endl;
	}
}
