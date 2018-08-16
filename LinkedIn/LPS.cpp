#include<bits/stdc++.h>
using namespace std;

const int M = 1e3 + 7;
int dp[M][M];

int LPS(string &s, int i, int j){
	if(i > j || i > (int)s.length() || j < 0) return 0;
	
	int &ret = dp[i][j];
	if(ret != -1) return ret;
	if(s[i] == s[j]){
		if(i == j)
			ret = LPS(s, i+1, j-1) + 1;
		else 
			ret = LPS(s, i+1, j-1) + 2;
	}
	else
		ret = max(LPS(s, i+1, j), LPS(s, i, j-1));
	return ret;
}
	
int main(){
	int t;
	cin >> t;
	string s;
	while(t--){
		cin >> s;
		memset(dp, -1, sizeof dp);
		cout << LPS(s, 0, s.length() - 1) << endl;
	}
}
