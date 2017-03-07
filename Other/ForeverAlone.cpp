#include<bits/stdc++.h>
using namespace std;

#define LL    	long long 
#define ff    	first 
#define ss    	second
#define pb    	push_back
#define mp    	make_pair 
#define len(x)  ((int)x.length())
#define sz(x)   ((int)x.size())

const int M = 100007;
const int MOD = 1000000000 + 7;

vector<string> v;
bool m[M];
int main(){ 
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		v.pb(s);
	}
	sort(v.begin(),v.end());
	int ans=0;
	for(int i=0;i<sz(v);i++){
		if(m[i]) continue;
		for(int j=i+1;j<sz(v);j++){
			if(m[j] || len(v[i])!=len(v[j])) continue;
			int f=0;
			for(int k=0;k<len(v[i])-1;k++){
				if(v[i][k]!=v[j][k]){
					f=1;
					break;
				}
			}
			if(!f){
				if(v[i][len(v[i])-1]!='a' || v[j][len(v[j])-1]!='i'){
					f=1;
				}
			}	
			if(!f){
				m[i]=1;
				m[j]=1;
				++ans;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
