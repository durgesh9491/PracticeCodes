#include <bits/stdc++.h>
using namespace std;
 
#define gc getchar
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define MOD 1000000007
#define inf 2000000000
#define oo (ll)1e18
#define TRACE
#define _ ios_base::sync_with_stdio(0);cin.tie(0); 
 
#ifdef TRACE
 #define trace(x)            cerr<<x<<endl;
    #define trace1(x)           cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
    #define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
    #define trace3(x,y,z)       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
    #define trace4(a,b,c,d)     cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
    #define trace5(a,b,c,d,e)   cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
    #define trace6(a,b,c,d,e,f) cerr<<__FUNCTION__<<":"<<__LINE__<<": "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<endl;
 
#else
 
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
 
#endif
  
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

void scan(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
const int M=100005;
int lis[M], dad[M];
int a[M];

void printLis(int idx, vector<int> v) {
	if(lis[idx] == 1) {
		for(int i = v.size() - 1; i >= 0; i--)
		cout << v[i] << " ";
		cout << endl;
	}
	for(int i = 0; i < idx; i++) {
		if(lis[i] == lis[idx] - 1 && a[i] < a[idx]) {
			vector<int>tmp = v;
			tmp.push_back(a[i]);
			printLis(i, tmp);
		}
	}
}
int main(){
    //freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int n, mx = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		lis[i] = 1;
		for(int j = 0; j < i; j++) {
			if(a[j] < a[i] && lis[i] < lis[j] + 1)
			lis[i] = lis[j] + 1;			
		}
		mx = max(mx, lis[i]);
	}
	cout << mx << endl;
	for(int i = 0; i < n; i++) {
		if(lis[i] == mx){
			vector<int> v;
			v.push_back(a[i]);
			printLis(i, v);
		}		
	}
    return 0;
}
