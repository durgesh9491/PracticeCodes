/*
 * Code author      : Durgesh Soni
 * Problem link     : https://www.geeksforgeeks.org/ugly-numbers/
 * Statement        : Ugly numbers are numbers whose only prime factors are 2, 3 or 5
 * To obtain        : Nth ugly number
 * Time Complexity  : O(n)
 * Space Complexity : O(n)
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

const LL  INF       =                    1LL << 62;
const int MOD       =                    1e9 + 7;
const int M         =                    1e3 + 7;


inline vector<int> precompute(const int &n){
	vector<int> dp(n + 1, 0);
	int i2, i3, i5, next_2, next_3, next_5, next;
	
	i2 = i3 = i5 = 0;
	dp[0] = 1;
	next_2 = dp[0] * 2;
	next_3 = dp[0] * 3;
	next_5 = dp[0] * 5;
	
	rep(i,1,n){
		next = min(next_2, min(next_3, next_5));
		dp[i] = next;
		if(next == next_2){
			i2 += 1;
			next_2 = dp[i2] * 2;
		}
		if(next == next_3){
			i3 += 1;
			next_3 = dp[i3] * 3;
		}
		if(next == next_5){
			i5 += 1;
			next_5 = dp[i5] * 5;
		}
	}
	return dp;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t, m;
	cin >> t;
	const vector<int>& dp = precompute(M);
	while(t--){
		cin >> m;
		cout << dp[m-1] << endl;
	}
    return 0;
}



/*
 * Input            : 2 15 150
 * Output           : 24 5832
 */

