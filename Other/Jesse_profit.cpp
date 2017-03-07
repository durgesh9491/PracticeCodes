#include<bits/stdc++.h>
using namespace std;

#define LL    	long long 
#define ff    	first 
#define ss    	second
#define pb    	push_back
#define mp    	make_pair 
#define len(x)  ((int)x.length())
#define sz(x)   ((int)x.size())

const int M = 200007;
const int MOD = 1000000000 + 7;
			
			
vector<int> A(M);
map<int,vector<int> > h;	
map<int,vector<int> >::iterator it;
int main(){
	int n,d,x,diff;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		h[A[i]].pb(i);
	}
	while(d--){
		cin>>x;
		int ans=INT_MAX,xx=-1,yy=-1;
		for(int i=1;i<=n;i++){
			it = h.find(A[i]+x);
			if(it!=h.end()){
				for(int j=0;j<(int)it->ss.size();j++){
					diff = it->ss[j]-i;
					if(diff>0 && diff<ans){
						ans= diff;
						xx=i;
						yy=it->ss[j];
					}
				}
			}
		}
		if(ans!=INT_MAX)
		cout<<xx<<" "<<yy<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}
