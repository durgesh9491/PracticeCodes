#include<bits/stdc++.h>
using namespace std;


int main(){
	int n,t;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> v(n+5);
		long long sum=0;
		for(int i=1;i<=n;i++){
			cin>>v[i];
			sum+=v[i];
		}
		if(!(sum&1)){
			cout<<n<<endl;
			continue;
		}
		int f=1,l=1;
		for(int i=1;i<=n;i++){
			if(v[i]&1){
				f=i;
				break;
			}
		}
		for(int i=n;i>=1;i--){
			if(v[i]&1){
				l=i;
				break;
			}
		}
		cout<<max(n-f,l-1)<<endl;
	}
	return 0;
}
