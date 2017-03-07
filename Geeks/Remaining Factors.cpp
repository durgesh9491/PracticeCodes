#include<bits/stdc++.h>
using namespace std;

#define LL    	long long 
#define ff    	first 
#define ss    	second
#define pb    	push_back
#define mp    	make_pair 
#define len(x)  ((int)x.length())
#define sz(x)   ((int)x.size())

const int M = 200007;
const int MOD = 1000000000 + 7;
			
			
int main(){
	LL n;
	for(n=1;n<=100;n++){
		cout<<"n = "<<n<<endl;
		int ans=0;
		for(int i=1;i<=n*n;i++){
			if((n*n)%i==0 && i<n && n%i!=0){
				cout<<i<<" ";
				++ans;
			}
		}
		cout<<" | ans = "<<ans<<endl;
	}
	return 0;
}
