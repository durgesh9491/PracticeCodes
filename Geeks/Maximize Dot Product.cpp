#include<bits/stdc++.h>
using namespace std;

#define LL        long long
#define pb        push_back
#define mp        make_pair
#define sz(_)     (int(_.size()))
#define len(_)    (int(_.length()))


const int MX = 1005;

LL dp[MX][MX], A[MX], B[MX];
int main(){
	int t, n, m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(dp, 0, sizeof dp);
		for(int i=1;i<=n;i++) cin>>A[i];
		for(int i=1;i<=m;i++) cin>>B[i];
		for(int i=1;i<=m;i++){
			for(int j=i;j<=n;j++){
				dp[i][j] = max(dp[i-1][j-1] + A[j] * B[i], dp[i][j-1]);
			}
		}
		cout<<dp[m][n]<<endl;
    }
	return 0;
}

