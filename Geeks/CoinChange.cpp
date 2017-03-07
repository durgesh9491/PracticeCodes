#include <bits/stdc++.h>
using namespace std;

const int M = 1005;
int A[M],dp[M*M*M];


int solve(int *A,int m,int sum){
	if(m==0) return 0;
	if(sum==0) return 1;
	if(sum<0) return 0;
	return solve(A,m-1,sum)+solve(A,m,sum-A[m-1]);
}

int main(){
	int n,sum;
	cin>>n;
	for(int i=0;i<n;i++) cin>>A[i];
	cin>>sum;
	cout<<solve(A,n,sum);
	
	/*dp[0]=1;
	 * check if given sum can be obtained
	for(int i=0;i<n;i++){
		for(int j=sum-A[i];j>=0;j--){
			if(dp[j]>0){
				dp[j+A[i]]+=dp[j];
			}
		}
	}
	for(int i=0;i<=sum;i++){
		cout<<i<<" "<<dp[i]<<endl;
	}
	cout<<dp[sum]<<endl;
	*/
	
	/* Number of ways to get the sum */
	dp[0]=1;
	for(int i=0;i<n;i++){
		for(int j=A[i];j<=sum;j++){
				dp[j]+=dp[j-A[i]];
		}
	}
	//cout<<dp[sum]<<endl;
	
}
