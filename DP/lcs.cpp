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
const int M=100;
int lis[M][M];
string a, b;


void printLcs(int u, int v, string s) {
	//cout << u << " " << v << " " << s <<endl;
	if(u < 0 || v < 0)
	return;
	if(u == 0 ||  v ==0) {
		reverse(s.begin(), s.end());
		cout << s << endl;
		return;
	}
	
	if(a[u - 1] == b[v - 1]) {
		string tmp = s;
		tmp += a[u - 1];
		printLcs(u - 1, v - 1, tmp);
	}
	else {
		if(lis[u][v - 1] >= lis[u - 1][v]) {
			printLcs(u, v - 1, s);
		}
		if(lis[u - 1][v] >= lis[u][v - 1]) {
			printLcs(u - 1, v, s);
		}		
	}
}
int main(){
    //freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);

	cin >> a >> b;
	int m = a.length(), n = b.length();
	for(int i = 0; i <= (int)a.length(); i++) {
		for(int j = 0; j <= (int)b.length(); j++) {
			if(i == 0 || j == 0)
			lis[i][j] = 0;
			else if(a[i - 1] == b[j - 1])
			lis[i][j] = lis[i - 1][j -1] + 1;
			else
			lis[i][j] = max(lis[i - 1][j], lis[i][j -1]);
		}
	}
	cout << lis[m][n] << "\n";
	
	string s;
	printLcs(m, n, s);
    return 0;
}
