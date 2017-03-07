#include<bits/stdc++.h>
using namespace std;

#define LL   long long
#define pb   push_back
#define mp   make_pair

int main(){
	int n, t;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> v(n), ans(n);
		for(int i=0;i<n;i++)cin>>v[i], ans[i]=-1;;
		for(int i=0;i<n-1;i++){
			if(v[i]>v[i+1]){
				ans[i] = v[i+1];
			}
		}
		for(int i=0;i<n;i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}
