#include<bits/stdc++.h>
using namespace std;

#define LL        long long
#define pb        push_back
#define mp        make_pair
#define ff        first
#define ss        second
#define sz(_)     (int(_.size()))
#define len(_)    (int(_.length()))

const LL MOD = 1e9 + 7;
const int M = 1e3 + 7;

int main(){
	int t, n;
	cin>>t;
	while(t--){
	    cin >> n;
	    vector<int> v(n);
	    for(int i = 0; i < n; i++){
	        cin >> v[i];
	    }
	    
	    stack<int> st;
	    int i = 0, ans = INT_MIN;
	    while(i < n){
	        if(st.empty() || v[i] >= v[st.top()]){
	            st.push(i++);
	            continue;
	        }
	        int top = st.top();
	        st.pop();
	        ans = max(ans, v[top] * (st.empty() ? i : (i - st.top() - 1)));
	    }
	    
	    while(!st.empty()){
	        int top = st.top();
	        st.pop();
	        ans = max(ans, v[top] * (st.empty() ? i : (i - st.top() - 1)));
	    }
	    cout << ans << endl;
    }
	return 0;
}
