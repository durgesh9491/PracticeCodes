#include <bits/stdc++.h>
using namespace std;

#define pb                        push_back
#define mp                        make_pair
#define ff                        first
#define ss                        second
#define rep(i,a,b)                for(int i=(a);i<=(b);++i)
#define rer(i,b,a)                for(int i=(b);i>=(a);--i)
#define clr(x,_)                  memset(x,_,sizeof(x))
#define feach(c,_)                for(__typeof((c).begin()) _=(c).begin();_!=(c).end();++_)
#define all(_)                    _.begin(),_.end()
#define sz(_)                     (int(_.size()))
#define len(_)                    (int(_.length()))
#define LB(_,x)                   (lower_bound(all(_),x)-(_.begin()))
#define UB(_,x)                   (upper_bound(all(_),x)-(_.begin()))
#define sq(x)                     ((x)*(x))
#define dist(x1,y1,x2,y2)         (sqrt(sq(x1-x2)+sq(y1-y2)))
#define area(x1,y1,x2,y2,x3,y3)   (abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))))
#define PI                        acos(-1.0)
#define INF                       (1LL<<62)
#define cnt_1                      __builtin_popcountll
#define lg(x)                     (63-__builtin_clzll(x))
#define dig(x)                    (int(log10(double(x)))+1)
#define T()                       int _;cin>>_;while(_--)
#define gc                        getchar_unlocked

//traces
#define dg1(x)                cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<endl;
#define dg2(x,y)              cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<" | "#y" = "<<y<<endl;
#define dg3(x,y,z)            cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
#define dg4(a,b,c,d)          cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
#define dg5(a,b,c,d,e)        cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
#define dg6(a,b,c,d,e,f)      cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<endl;

typedef long long int LL;     typedef pair<int,int> PII;       typedef vector<int> VI;          typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;      typedef vector<LL> VLL;          typedef vector<PLL> VPLL;        typedef vector<VPII> VVPII;

//utility functions
#define RG                   1
bool markP[RG];VI prime;
inline void sieve(){int i,j;for(i=2;i*i<=RG;++i)if(!markP[i])for(j=i<<1;j<RG;j+=i)if(!markP[j])markP[j]=1;prime.pb(2);for(i=3;i<RG;i+=2)if(!markP[i])prime.pb(i);}
inline void inp(int &x){register int c=gc();x=0;bool neg=0;for(;((c<48||c>57)&&c!='-');c=gc());if(c=='-'){neg=1;c=gc();}for(;c>47&&c<58;c=gc()){x=(x*10)+(c-48);}if(neg)x=-x;}
inline void inpl(LL &x){register LL c=gc();x=0;bool neg=0;for(;((c<48||c>57)&&c!='-');c=gc());if(c=='-'){neg=1;c=gc();}for(;c>47&&c<58;c=gc()){x=(x*10)+(c-48);}if(neg)x=-x;}
inline LL modexp(LL a,LL b,const LL &mod){LL x=1;a%=mod;while(b>0){if(b&1){x*=a;if(x>=mod)x%=mod;};b>>=1;a*=a;if(a>=mod)a%=mod;}return x;}
inline LL mulmod(LL a,LL b,const LL &mod){LL x=0;a%=mod;while(b>0){if(b&1){x+=a;if(x>=mod)x-=mod;}a<<=1;if(a>=mod)a-=mod;b>>=1;}return x;}
inline LL Pow(LL a,LL b){LL x=1;while(b>0){if(b&1)x*=a;a*=a;b>>=1;}return x;}
inline LL toNum(const string &st){LL num;stringstream ss(st);ss>>num;return num;}
inline LL strmod(const string &T,const LL &mod){LL mul=0;rep(i,0,len(T)-1){mul=(mul*10+T[i]-'0');if(mul>=mod)mul%=mod;}return mul;}
inline LL fib(LL n,const int &mod){LL i,j,h,k,t;i=h=1;j=k=0;while(n>0){if(n&1){t=j*h%mod;j=(i*h+j*k+t)%mod;i=(i*k+t)%mod;}t=h*h%mod;h=(2*k*h+t)%mod;k=(k*k+t)%mod;n>>=1;}return j;}
inline LL comb(const LL &N,LL R,const LL &mod){if(R>N) return 0;R>(N-R)?(R=N-R):R;LL mul=1LL;rep(i,0,R-1) mul=((mul*(N-i))%mod*modexp(i+1,mod-2,mod))%mod;return mul;}
inline bool cmpUB(const int &v,const PII &p1){return (p1.first>v)?1:0;}
inline bool cmpLB(const PII &p1, const int &v){return (p1.first<v)?1:0;}
inline bool cmp(const PII &X,const PII &Y) {return (X.ff!=Y.ff)?(X.ff<Y.ff):(X.ss<Y.ss);}


const int L = 50003;
const int K = 26;

struct state {
	int length, link, next[K];
};

struct Tree{
	int sz, last;
	bool flag;
	struct state *st;
}tree[L];

vector<string> v;


void init(const int& p,const int& i) {
	tree[i].st = new state[2*p + 1];
	tree[i].sz = 0, tree[i].last = 0;
	tree[i].st[0].link = -1;
	tree[i].flag = true;
	memset(tree[i].st[0].next, -1, sizeof tree[i].st[0].next);
	tree[i].sz += 1;
}

void extend(const int& c, const int &idx) {
	int nlast = tree[idx].sz, p, q, clone;
	tree[idx].sz += 1;
	tree[idx].st[nlast].length = (tree[idx].st[tree[idx].last].length) + 1;
	memset(tree[idx].st[nlast].next, -1, sizeof tree[idx].st[nlast].next);
	for(p=tree[idx].last; p!=-1 && tree[idx].st[p].next[c]==-1; p=tree[idx].st[p].link) tree[idx].st[p].next[c] = nlast;
	if(p == -1) tree[idx].st[nlast].link = 0;
	else{
		q = tree[idx].st[p].next[c];
		if(tree[idx].st[p].length + 1 == tree[idx].st[q].length) tree[idx].st[nlast].link = q;
		else{
			clone = tree[idx].sz;
			tree[idx].sz += 1;
			tree[idx].st[clone].length = tree[idx].st[p].length + 1;
			memcpy(tree[idx].st[clone].next, tree[idx].st[q].next, sizeof tree[idx].st[clone].next);
			tree[idx].st[clone].link = tree[idx].st[q].link;
			for(; p!=-1 && tree[idx].st[p].next[(int)c]==q; p=tree[idx].st[p].link) tree[idx].st[p].next[c] = clone;
			tree[idx].st[q].link = tree[idx].st[nlast].link = clone;
		}
	}
	tree[idx].last = nlast;
}

void preCompute(string &a,const int& idx){
	init(len(a), idx);
	rep(i,0,len(a)-1) extend (a[i]-'a', idx);
}

int lcs(const int& a, const int& b) {
	int p, l, best;
	p = 0, l = 0, best = 0;
	if(tree[a].flag == false){
		preCompute(v[a], a);
	}
	if(tree[b].flag == false){
		preCompute(v[b], b);
	}
	int idx = a;
	rep(i,0,len(v[b])-1) {
		if(tree[idx].st[p].next[v[b][i]-'a'] == -1) {
			for(; p!=-1 && tree[idx].st[p].next[v[b][i]-'a'] == -1; p=tree[idx].st[p].link);
			if (p == -1) {
				p = l = 0;
				continue;
			}
			l = tree[idx].st[p].length;
		}
		p = tree[idx].st[p].next[v[b][i]-'a']; l++;
		if(l > best) best = l;
	}
	return best;
}

int main(){
	//ios_base::sync_with_stdio(false);
	//freopen("inp.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    int n, q, a, b;
    inp(n), inp(q);
    string s;
    rep(i,0,n-1){
		cin >> s;
		v.pb(s);
	}
    while(q--){
       inp(a), inp(b);
        if(tree[a].flag)
			printf("%d\n", lcs(a, b));
		else printf("%d\n", lcs(b, a));
	}    
    return 0;
}
