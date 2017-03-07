#include<bits/stdc++.h>
using namespace std;


#define mp make_pair
#define ff first
#define ss second

int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> v(n+1),ans(n);
        v[n]=-1;
        for(int i=0;i<n;i++) cin>>v[i];
        stack<pair<int,int> > st;
        st.push(mp(v[0],0));
         
        pair<int,int> ele, next;
        for(int i=1;i<n;i++){
			next.ff = v[i];
			next.ss = i;
			
			if(!st.empty()){
				ele = st.top();
				st.pop();
				while(ele.ff < next.ff){
					ans[ele.ss] = next.ss;
					if(st.empty()) break;
					ele = st.top();
					st.pop();
				}
				if(ele.ff>next.ff)
				st.push(ele);
			}
			st.push(next);
		}
		while(!st.empty()){
			ele = st.top();
			st.pop();
			ans[ele.ss]=n;
		}
		for(int i=0;i<n;i++) cout<<v[ans[i]]<<" ";
		cout<<endl;
	}
}
