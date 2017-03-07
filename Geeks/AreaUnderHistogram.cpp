#include<bits/stdc++.h>
using namespace std;

int histArea(vector<int> &A){
    int ans = 0;
    int n = A.size();
    stack<int> st;
    int i = 0;
    
    while(i < n){
        if(st.empty() || A[i] >= A[st.top()]){
            st.push(i);
            i++;
            continue;
        }
        int tp = st.top();
        st.pop();
        if(!st.empty())
        ans = max(ans, A[tp] * (i - st.top() - 1));
        else 
        ans = max(ans, A[tp] * i);
    }
    while(!st.empty()){
        int tp = st.top();
        st.pop();
        if(st.empty()) ans = max(ans, A[tp] * i);
        else ans = max(ans, A[tp] * (i - st.top() - 1));
    }
    return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i = 0; i<n; i++) cin>>A[i];
	cout<< histArea(A)<<endl;
}
