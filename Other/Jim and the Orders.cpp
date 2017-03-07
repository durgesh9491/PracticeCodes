#include<bits/stdc++.h>
using namespace std;

#define pb     push_back 
#define mp     make_pair
#define ff     first
#define ss     second

inline bool cmp(const pair<int,int>& X,const pair<int,int>& Y){
	return (X.ff!=Y.ff)? (X.ff<Y.ff):(X.ss<Y.ss);
}
	
int main(){
	int n,x,y;
	cin>>n;
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		v.pb(mp(x+y,i+1));
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n;i++) cout<<v[i].second<<" ";
	return 0;
}
