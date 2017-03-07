#include<bits/stdc++.h>
using namespace std;

#define LL   long long
#define pb   push_back
#define mp   make_pair

int main(){
	int t; LL n;
	cin>>t;
	while(t--){
		cin>>n;
		bool ok=0;
		for(int i=2;i*i<=n;i++){
			LL base = i;
			while(base < n){
				base *= i;
				if(base == n){
					ok =1;
					break;
				}
			}
			if(ok) break;
		}
		if(ok)cout<<"1\n";
		else cout<<"0\n";
	}
	return 0;
}
