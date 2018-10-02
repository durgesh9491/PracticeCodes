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
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin >> n;
	    vector<int> v(n), L(n), R(n);
	    for(int i = 0;i < n; i++) cin >> v[i];
	    
	    L[0] = v[0];
	    R[n-1] = v[n-1];
	    
	    for(int i = 1; i < n; i++) L[i] = max(L[i-1], v[i]);
	    for(int i = n-2; i >=0; i--) R[i] = max(R[i+1], v[i]);
	    
	    int ans = 0;
	    for(int i = 0; i < n; i++){
	        ans += min(L[i], R[i]) - v[i];
 	    }
	    cout << ans << endl;
    }
	return 0;
}
