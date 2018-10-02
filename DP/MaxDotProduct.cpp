#include<bits/stdc++.h>
using namespace std;

#define LL long long int

LL solve(int m, int n, vector<LL> &a, vector<LL> &b, vector<vector<LL> > &dp){
	if(m < 0 || n < 0 || m < n) return 0;
	LL &ret = dp[m][n];
	if(ret != -1) return ret;
	ret = 0;
	ret = max(ret, max(a[m] * b[n] + solve(m-1, n-1, a, b, dp), solve(m-1, n, a, b, dp)));
	return ret;
}


int main(){
	int m, n, t;
	cin >> t;
	while(t--){
		cin >> m >> n;
		vector<LL> a(m), b(n); 
		for(int i = 0; i < m; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		vector<vector<LL> > dp(m, vector<LL>(n, -1));
		solve(m - 1, n - 1, a, b, dp);
		cout << dp[m-1][n-1] << endl;
	}
	return 0;
}
