#include <bits/stdc++.h>
using namespace std;

const int M = 105;
int val[M], wt[M];
int dp[M][M];

int main(){
	int t,n,w;
	cin>>t;
	while(t--){
		cin>>n>>w;
		for(int i=0;i<n;i++) cin>>val[i];
		for(int i=0;i<n;i++) cin>>wt[i];
		
		for(int i=0;i<=n;i++){
			for(int j=0;j<=w;j++){
				if(i==0 || j==0)
				dp[i][j]=0;
				else 
				if(wt[i-1]>j) dp[i][j] = dp[i-1][j];
				else
				dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
			}
		}
		cout<<dp[n][w]<<endl;
	}
	return 0;
} 
		
		
