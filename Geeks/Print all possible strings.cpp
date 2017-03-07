#include<bits/stdc++.h>
using namespace std;

#define LL   long long
#define pb   push_back
#define mp   make_pair

vector<string> ans;

void solve(string s, int idx){
	if(idx >= (int)s.length()){
		ans.pb(s);
		return;
	}
	s.insert(s.begin()+idx,' ');
	solve(s, idx+2);
	s.erase(s.begin()+idx);
	solve(s, idx+1);
}
	
	
int main(){
	int t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		ans.clear();
		solve(s, 1);
		for(int  i=ans.size()-1;i>=0;i--) cout<<ans[i]<<"$";
		cout<<endl;
	}
	return 0;
}
