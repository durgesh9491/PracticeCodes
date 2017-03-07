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

vector<int> v;

void print(const vector<int>& ans){
	int i=0;
	if(ans[i]==0){
		for(int j=i;j<sz(ans);j++){
			if(ans[i]!=ans[j]){
				i=j;
				break;
			}
		}
		if(i==0) i= sz(ans)-1;
	}
	for(;i<sz(ans);i++) cout<<ans[i];
	cout<<endl;
}
			
			
int main(){ 
	int t,n,x;
	cin>>t;
	while(t--){
		v.clear();
		vector<int> ans;
		
		cin>>n;
		bool f=0;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>x;
			v.pb(x);
			if(v[i]==0){
				f=1;
			}
			sum+=v[i];
		}
		if(!f){
			cout<<"-1\n";
			continue;
		}
		sort(v.begin(),v.end(),greater<int>());
		
		int rm = sum%3;
		if(rm==0){
			for(int j=0;j<n;j++) ans.pb(v[j]);
			print(ans);
			continue;
		}
		int idx=-1;
		for(int i=n-2;i>=0;i--){
			if(v[i]%3==rm){
				idx=i;
				break;
			}
		}
		if(idx!=-1){
			for(int i=0;i<n;i++) if(i!=idx) ans.pb(v[i]);
			print(ans);
			continue;
		}
		int idx1=-1;
		for(int i=n-2;i>=0;i--){
			if(v[i]%3){
				rm-=v[i]%3;
				if(idx==-1) idx=i;
				else idx1=i;
				if(rm==0) break;
			}
		}
		if(idx!=-1 && idx1!=-1){
			for(int i=0;i<n;i++) if(i!=idx && i!=idx1) ans.pb(v[i]);
			print(ans);	
		}
		else cout<<"-1\n";
	}
	return 0;
}
