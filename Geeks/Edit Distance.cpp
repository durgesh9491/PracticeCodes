#include <bits/stdc++.h>
using namespace std;

int dp[105][105];
int solve(const string &a, const string& b, int m,int n){
	int &ret= dp[m][n];
	if(ret!=-1) return ret;
	if(m==0) return ret = n;
	if(n==0) return ret = m;
	if(a[m-1] == b[n-1]) return ret= solve(a,b,m-1,n-1);
	return ret = 1 + min(solve(a,b,m-1,n), min(solve(a,b,m,n-1), solve(a,b,m-1,n-1)));
}
	
int main(){
	int t, n1, n2;
	cin >> t;
	while(t--){
		memset(dp, -1, sizeof dp);
		string s1, s2;
		cin >> n1 >> n2 >> s1 >> s2;
		cout<<solve(s1, s2, n1, n2)<<endl;
	}
	return 0;
}
		
		
/*
#include <bits/stdc++.h>
using namespace std;

int dp[105][105];
int main(){
	int t, n1, n2;
	cin >> t;
	while(t--){
		memset(dp, 0, sizeof dp);
		string a,b;
		cin >> n1 >> n2 >> a >> b;
		//cout<<solve(s1, s2, n1, n2)<<endl;
		int m=n1,n=n2;
		for(int i = 0; i<=m ; i++){
			for(int j=0;j<=n;j++){
				if(i==0)
				dp[i][j] = j;
				
				else if(j==0)
				dp[i][j]=i;
				
				else if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1];
				else
				dp[i][j] = 1 + min(dp[i-1][j-1], min( dp[i-1][j], dp[i][j-1]));
			}
		}
		cout<< dp[m][n] <<endl;
	}
	return 0;
}
		
		
*/
