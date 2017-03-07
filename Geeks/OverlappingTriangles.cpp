#include<bits/stdc++.h>
using namespace std;

#define LL   long long
#define pb   push_back
#define mp   make_pair

int main(){
	int x[4],y[4];
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<4;i++) cin>>x[i]>>y[i];
		if(x[0]>x[3] || x[1]<x[2] || y[0]<y[3] || y[1]>y[2]) cout<<0<<endl;
		else if((x[0]==x[3]) || (x[1]==x[2]) || (y[0]==y[3]) || (y[2]==y[1])) cout<<0<<endl;
		else cout<<1<<endl;
	} 
		
	return 0;
}
