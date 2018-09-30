/*
 * Code author      : Durgesh Soni
 * Problem link     : https://www.geeksforgeeks.org/maximum-sum-rectangle-in-a-2d-matrix-dp-27/
 * Statement        : Maximum sum rectangle in a 2D matrix
 * Idea             : Kadane's Algorithm column wise with cumulative row sum
 * Time Complexity  : O(N * M ^ 2)
 * Space Complexity : O(N * M) + O(N)
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

const LL INF        =                    1LL << 62;
const LL MOD        =                    1e9 + 7;
const int M         =                    1e5 + 7;


pair<PII, int> Kadane(const VI &v){
	int ans = INT_MIN, cur = 0;
	int start = 0, end = 0, tmp_start = 0;
	int neg_mx = INT_MIN, neg_start = 0, neg_end = 0, neg_cnt = 0;
	
	rep(k, 0, sz(v)-1){
		if(v[k] < 0){
			neg_cnt += 1;
			if(v[k] > neg_mx){
				neg_mx = v[k];
				neg_start = neg_end = k;
			}
		}
		
		cur += v[k];
		if(cur > ans){
			start = tmp_start;
			end = k;
			ans = cur;
		}	
		if(cur < 0){
			tmp_start = k + 1;
			cur = 0;
		}
	}
	
	if(neg_cnt == sz(v)){
		ans = neg_mx;
		start = neg_start;
		end = neg_end;
	}
	return mp(mp(start, end), ans);
}


int main(){
	int t, r, c;
	cin >> t;
	while(t--){
		cin >> r >> c;
		
		VVI mat(r, VI(c));
		VI row(r, 0);
		int ans = INT_MIN;
		int c1, c2, r1, r2;
		
		rep(i,0,r-1){
			rep(j,0,c-1){
				cin >> mat[i][j];
			}
		}
		
		rep(i,0,c-1){
			fill(all(row), 0);
			rep(j,i,c-1){
				rep(k,0,r-1){
					row[k] += mat[k][j];
				}
				
				const pair<PII, int>& res = Kadane(row);
				if(res.ss > ans){
					ans = res.ss;
					c1 = i;
					c2 = j;
					r1 = res.ff.ff;
					r2 = res.ff.ss;
				}
			}
		}
		dbg5(ans, c1, c2, r1, r2);
		cout << ans << endl;
	}
	return 0;
}



/*
 * Input            : 1 4 5 1 2 -1 -4 -20 -8 -3 4 2 1 3 8 10 1 3 -4 -1 1 7 -6
 * Output           : 29
 */


