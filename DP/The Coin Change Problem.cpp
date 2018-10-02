#include<bits/stdc++.h>
using namespace std;

#define LL        long long
#define pb        push_back
#define mp        make_pair
#define sz(_)     (int(_.size()))
#define len(_)    (int(_.length()))


const int MX = 100005;

int A[MX];
long long dp[MX];
int main(){
	int n, m;
	cin>>n>>m;
	for(int i=0;i<m;i++) cin>>A[i];
	dp[0]=1;
	for(int i=0;i<m;i++){
		for(int j=A[i];j<=n;j++){
				dp[j] += dp[j-A[i]];
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}

