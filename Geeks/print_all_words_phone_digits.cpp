#include<bits/stdc++.h>
using namespace std;

#define dbg1(x)              cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<endl;
#define dbg2(x,y)            cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<" | "#y" = "<<y<<endl;
#define dbg3(x,y,z)          cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;


vector<int> v;
int sz,g_ans=0;
string hashi[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void solve(int curr_ind, string ans){
	//dbg2(curr_ind, ans);
	if(curr_ind==sz){
		++g_ans;
		cout<<ans<<" ";
		return;
	}
	for(int i=0;i<(int)hashi[v[curr_ind]].size();i++){
		ans+= hashi[v[curr_ind]][i];
		solve(curr_ind+1,ans);
		ans.erase(ans.end()-1);
	}
}
		
	
	
int main(){
    int x,t;
    cin>>t;
    while(t--){
		cin>>sz;
		v.clear();
		for(int i=0;i<sz;i++){
			cin>>x; 
			v.push_back(x);
		}
		solve(0,"");
		cout<<endl;
	}
	//cout<<g_ans<<endl;
	return 0;
}
	
