/*
 * Code author      : Durgesh Soni
 * Problem link     : https://www.geeksforgeeks.org/program-nth-catalan-number/
 * Statement        : Program for nth Catalan Number
 * To obtain        : 1/(n + 1) * (2n C n)
 * Time Complexity  : O(n ^ 2)
 * Space Complexity : O(n ^ 2)
 */


#include<bits/stdc++.h>
using namespace std;

#define             pb                   push_back
#define             mp                   make_pair
#define             ff                   first
#define             ss                   second
#define             all(_)               _.begin(),_.end()
#define             sq(x)                ((x)*(x))
#define             sz(_)                int(_.size())
#define             len(_)               int(_.length())
#define             rep(i,a,b)           for(int i=(a);i<=(b);++i)
#define             rer(i,b,a)           for(int i=(b);i>=(a);--i)
#define             clr(x,_)             memset(x,_,sizeof(x))
#define             exist(x,_)           (((_).find(x))!=((_).end()))
#define             feach(c,_)           for(__typeof((c).begin()) _=(c).begin();_!=(c).end();++_)
#define              gc                  getchar_unlocked

#define             dbg1(x)              cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<endl;
#define             dbg2(x,y)            cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<" | "#y" = "<<y<<endl;
#define             dbg3(x,y,z)          cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
#define             dbg4(a,b,c,d)        cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
#define             dbg5(a,b,c,d,e)      cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;

typedef             long long int        LL;
typedef             pair<int,int>        PII;
typedef             vector<PII>          VPII;
typedef             vector<int>          VI;
typedef             vector<VI>           VVI;
typedef             vector<string>       VS;
typedef             priority_queue<int>  PQ;

const LL INF        =                    1LL << 62;
const LL MOD        =                    1e9 + 7;
const int M         =                    1e4 + 7;


LL modexp(LL a, LL b, const LL &MOD){
	LL x = 1;
	while(b > 0){
		if(b & 1){
			x = (x * a) % MOD;
		}
		b >>= 1;
		a  = (a * a) % MOD;
	}
	return x;
}
	
inline VVI combination(){
	VVI dp(M + 1, VI(M + 1, 0));
	dp[0][0] = 1;
	rep(i, 1, M){
		rep(j, 0, i/2){
			if(j == 0){
				dp[i][j] = dp[i][i] = 1;
			}
			else{
				dp[i][j] = dp[i][i-j] = (dp[i-1][j] + dp[i-1][j-1]);
				if(dp[i][j] >= MOD){
					dp[i][j] -= MOD;
					dp[i][i-j] -= MOD;
				}
			}
		}
	}
	return dp;
}

int main(){
	int t, n;
	const VVI &dp = combination();
	cin >> t;
	while(t--){
		cin >> n;
		cout << (1LL * modexp(1LL * (n + 1), MOD-2, MOD) * dp[2 * n][n]) % MOD << endl;
	}
    return 0;
}



/*
 * Input            : 10 0 1 2 3 4 5 6 7 8 9
 * Output           : 1 1 2 5 14 42 132 429 1430 4862
 */

