#include <bits/stdc++.h>
using namespace std;

#define pb                   push_back
#define mp                   make_pair
#define ff                   first
#define ss                   second
#define INF                  2047483647
#define INFLL                9023372036854775807LL
#define PI                   acos(-1.0)
#define gcd(_1,_2)           __gcd(_1,_2)
#define lcm(_1,_2)           ((_1/gcd(_1,_2))*(_2))
#define cnt_1                __builtin_popcountll
#define eps                  1e-12

#define rep(i,a,b)           for(int i=(a);i<=(b);++i)
#define rer(i,b,a)           for(int i=(b);i>=(a);--i)
#define clr(x,_)             memset(x,_,sizeof(x))
#define feach(c,_)           for(__typeof((c).begin()) _=(c).begin();_!=(c).end();++_)
#define all(_)               _.begin(),_.end()
#define sz(_)                (int(_.size()))
#define len(_)               (int(_.length()))
#define T()                  int _;cin>>_;while(_--)
#define exist(x,_)           (((_).find(x))!=((_).end()))
#define LB(_,x)              (lower_bound(all(_),x)-(_.begin()))
#define UB(_,x)              (upper_bound(all(_),x)-(_.begin()))
#define gc                   getchar//_unlocked

#define dist(x1,y1,x2,y2)        ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define area(x1,y1,x2,y2,x3,y3)  (abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))))
#define lg(x)                    63-__builtin_clzll(x)
#define dig(x)                   (int(log10(double(x)))+1)
#define cil(a,b)                 (LL(ceil(double(a)/double(b))))
#define sin(x)                   (sin((x*PI)/180.0))
#define sq(x)                    ((x)*(x))

//traces
#define SP                   system("pause")
#define dbg1(x)              cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<endl;
#define dbg2(x,y)            cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<" | "#y" = "<<y<<endl;
#define dbg3(x,y,z)          cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
#define dbg4(a,b,c,d)        cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
#define dbg5(a,b,c,d,e)      cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
#define ds                   cerr<<__FUNCTION__<<" : "<<__LINE__<<" : ----- I am Here -----\n";

typedef long long int LL;     typedef pair<int,int> PII;       typedef vector<int> VI;          typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;      typedef vector<LL> VLL;          typedef vector<PLL> VPLL;        typedef vector<VPII> VVPII;
typedef vector<VPLL> VVPLL;   typedef map<string,int> MSI;     typedef priority_queue<int> PQ;  typedef vector<string> VS;

#define RG                   1
bool markP[RG];VI prime;
inline void sieve(){int i,j;for(i=2;i*i<=RG;++i)if(!markP[i])for(j=i<<1;j<RG;j+=i)if(!markP[j])markP[j]=1;prime.pb(2);for(i=3;i<RG;i+=2)if(!markP[i])prime.pb(i);}
//inline void inp(int &x){register int c=gc();x=0;bool neg=0;for(;((c<48||c>57)&&c!='-');c=gc());if(c=='-'){neg=1;c=gc();}for(;c>47&&c<58;c=gc()){x=(x*10)+(c-48);}if(neg)x=-x;}
inline LL modexp(LL a,LL b,const LL &mod){LL x=1;a%=mod;while(b>0){if(b&1){x*=a;if(x>=mod)x%=mod;};b>>=1;a*=a;if(a>=mod)a%=mod;}return x;}
inline LL mulmod(LL a,LL b,const LL &mod){LL x=0;a%=mod;while(b>0){if(b&1){x+=a;if(x>=mod)x-=mod;}a<<=1;if(a>=mod)a%=mod;b>>=1;}return x;}
inline LL invmod(const LL &a,const LL &mod){return modexp(a,mod-2,mod);}
inline LL Pow(LL a,LL b){LL x=1;while(b>0){if(b&1)x=(x*a);a*=a;b>>=1;}return x;}
inline LL digSum(LL n){LL s=0;n=abs(n);while(n){s+=(n%10);n/=10;}return s;}
inline LL toNum(const string &st){LL num;stringstream ss(st);ss>>num;return num;}
inline string toStr(const LL &num){ return static_cast<stringstream*>( &(stringstream()<<num))->str();}
inline LL strmod(const string &T,const LL &mod){LL mul=0;rep(i,0,len(T)-1){mul=(mul*10+T[i]-'0');if(mul>=mod)mul%=mod;}return mul;}
inline bool isPrime(const LL &x){if(x<=3)return(x<=1?0:1);if(!(x&1)||!(x%3))return 0;for(LL i=5;i*i<=x;i+=6)if(!(x%i)||!(x%(i+2)))return 0;return 1;}
inline bool isPalin(const string &st){int l=len(st);for(int i=0;(i<<1)<l;++i)if(st[i]!=st[l-i-1])return 0;return 1;}
inline LL fib(LL n,const int &mod){LL i,j,h,k,t;i=h=1;j=k=0;while(n>0){if(n&1){t=j*h%mod;j=(i*h+j*k+t)%mod;i=(i*k+t)%mod;}t=h*h%mod;h=(2*k*h+t)%mod;k=(k*k+t)%mod;n>>=1;}return j;}
inline LL comb(const LL &N,LL R,const LL &mod){if(R>N) return 0;R>(N-R)?(R=N-R):R;LL mul=1LL;rep(i,0,R-1) mul=((mul*(N-i))%mod*invmod(i+1,mod))%mod;return mul;}
inline int elePos(int *A,const int &n,const int &x){int l=0,h=n-1,m;while(l<=h){ m=(h+l)>>1;if(x==A[m])return (m+1);(x<A[m])?(h=m-1):(l=m+1);}return -1;}
inline bool cmp(const PII &X,const PII &Y) {return (X.ff!=Y.ff)?(X.ff<Y.ff):(X.ss<Y.ss);}


#define fpos adla
const int inf = 1e9;
const int maxn = 2e5+1e4;
const long long int MOD = 1000000007;
char s[maxn],inp[maxn];
map<int, int> to[maxn];
int len[maxn]={inf}, fpos[maxn], link[maxn];
int node, pos;
int sz = 1, n = 0;
//
long long int ans,val[maxn],lf[maxn];

#define LL long long 
//
int make_node(int _pos, int _len)
{
    fpos[sz] = _pos;
    len [sz] = _len;
    return sz++;
}
void go_edge()
{
    while(pos > len[to[node][s[n - pos]]])
    {
        node = to[node][s[n - pos]];
        pos -= len[node];
    }
}
void add_letter(int c)
{
    s[n++] = c;
    pos++;
    int last = 0;
    while(pos > 0)
    {
        go_edge();
        int edge = s[n - pos];
        int &v = to[node][edge];
        int t = s[fpos[v] + pos - 1];
        if(v == 0)
        {
            v = make_node(n - pos, inf);
            link[last] = node;
            last = 0;
        }
        else if(t == c)
        {
            link[last] = node;
            return;
        }
        else
        {
            int u = make_node(fpos[v], pos - 1);
            to[u][c] = make_node(n - 1, inf);
            to[u][t] = v;
            fpos[v] += pos - 1;
            len [v] -= pos - 1;
            v = u;
            link[last] = u;
            last = u;
        }
        if(node == 0)
            pos--;
        else
            node = link[node];
    }
}
void clearSuffixTree()
{
	for(int i = 0; i < sz; ++i)
		to[i].clear();
	node=0;
	pos=0;
	sz=1;
	n=0;
}
inline long long int f(long long int a, long long int d, long long int n)
{
	a%=MOD;
	d%=MOD;
	long long int v1 = (a*a - a)%MOD;
	long long int v2 = (2*a*d - d)%MOD;
	long long int v3 = (d*d)%MOD;
	long long int INV = 500000004;
	v1 = (v1*n)%MOD;
	v2 = (v2*(((n-1)*n/2)%MOD))%MOD;
	v3 = (v3*(((n-1)*n*(2*n-1)/6)%MOD))%MOD;
	long long int ret = ((v1+v2+v3)*INV)%MOD;
	return ret;
}
void dfs(int pos)
{
	val[pos] = lf[pos] = 0;
	for (map <int,int>::iterator it = to[pos].begin(); it != to[pos].end(); ++it)
	{
		if(it->first == '*')
		{
			val[pos]++;
			lf[pos]++;
			continue;
		}
		int v = it->second;
		dfs(v);
		long long int clen = min(len[v],n-fpos[v]);
		if(fpos[v]+clen == n)
		{
			val[v]++;
			lf[v]++;
			clen--;
		}
		val[pos]+=(val[v] + lf[v]*clen);
		lf[pos]+=lf[v];
		ans = (ans + f(val[v],lf[v],clen))%MOD;
	}
}

int main(){
	//ios_base::sync_with_stdio(false);
	//freopen("inp.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t,n;
	scanf("%d", &t);
	while(t--){
		scanf("%d%s",&n, inp);
		for (int i = 0; inp[i] != '\0'; ++i)
			add_letter(inp[i]);
		add_letter('*');
		ans = 0;
		dfs(0);
		clearSuffixTree();
        ans = (ans * 2)%MOD;
        LL p = 1;
        for(LL i = n; i > 0; --i){
			ans+= i*p;
			ans%=MOD;
			++p;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
