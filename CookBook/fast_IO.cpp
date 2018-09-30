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
#define             gc                   getchar_unlocked
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
const int M         =                    1e4 + 7;



template<typename T>
void inp(T &x){
  register T c = gc();
  x = 0;
  bool neg = 0;
  for(;((c < '0' || c > '9') && c != '-');
  c = gc());
  if(c == '-'){
    neg = 1;
    c = gc();
  }
  for(;c >= '0' && c <= '9'; c = gc()){
    x = (x * 10) + (c - '0');
  }
  if(neg){
    x = -x;
  }
}
