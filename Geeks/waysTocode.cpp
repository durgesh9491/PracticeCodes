#include<bits/stdc++.h>
using namespace std;


numDecodings(string A) {
    int n = (int)A.length();
    long long  dp[n + 5];
    memset(dp, 0, sizeof dp);
    
    if(A[0] == '0') return 0;
    dp[0] = 1;
    for(int i=1;i<n;i++){
        int num = (A[i-1]-'0') * 10 + (A[i]-'0');
        if(A[i] == '0'){
			if(num > 26) return 0;
			dp[i] = 1;
			if(i>1) dp[i] = dp[i-2];
		}
		else if(A[i-1] == '0'){
			if(i>2)
			dp[i] = dp[i-3];
			else dp[i] = 0;
		}
		else if(num < 27){
			if(i > 1) dp[i] = dp[i-2] + dp[i-1];
			else dp[i] = dp[i-1] + 1;
		}
		else dp[i] = dp[i-1];
    }
    return dp[n-1];
}


int main(){
	while(1){
		string s;
		cin>>s;
		cout<<numDecodings(s)<<endl;
	}
}

/* 
 * 2611055971756562
 * ans  = 4
 */
