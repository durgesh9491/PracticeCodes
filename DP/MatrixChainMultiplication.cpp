#include <bits/stdc++.h>
using namespace std;

const int M = 1005;

int cost[M];
int dp[M][M];

int solve(int *p,int l,int r){
    int &ret= dp[l][r];
    if(ret!=-1) return ret;
	if(l==r) return 0;
	int ans= INT_MAX;
	for(int i=l;i<r;i++){
		ans = min(ans, solve(p,l,i) + solve(p,i+1,r) + p[l-1]*p[i]*p[r]);
	}
	return ret=ans;
}


int main(){
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++) cin>>cost[i];
		memset(dp,-1,sizeof dp);
		cout<<solve(cost,1,n-1)<<endl;
		
		for(int i=0;i<n;i++){
			dp[i][i]=0;
			for(int j=0;j<n;j++){
				if(i!=j) dp[i][j]=INT_MAX;
			}
		}
		
		for(int d=2;d<n;d++){
			for(int i=1;i<=n-d+1;i++){
				int j = i+d-1;
				for(int k=i;k<j;k++){
					dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+cost[i-1]*cost[k]*cost[j]);
				}
			}
		}
		cout<<dp[1][n-1]<<endl;
	}
	return 0;
}
