#include<bits/stdc++.h>
using namespace std;

#define LL   long long
#define pb   push_back
#define mp   make_pair
#define sq(x)  ((x) * (x))
#define dist(x1,x2,y1,y2)  (sq(x1-x2) + sq(y1 - y2))

int main(){
	int t;
	cin>>t;
	LL x[4], y[4];
	while(t--){
		for(int i=0;i<4;i++) cin>>x[i]>>y[i];
		LL d2 = dist(x[0],x[1],y[0],y[1]);
		LL d3 = dist(x[0],x[2],y[0],y[2]);
		LL d4 = dist(x[0],x[3],y[0],y[3]);
		if(d2 == d4 && 2*d2 == d3){
			LL d = dist(x[1],x[2],y[1],y[2]);
			if(d == dist(x[2],x[3],y[2],y[3]) && d == d2)
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
		else if(d3 == d4 && 2*d3 == d2){
			LL d = dist(x[1],x[3],y[1],y[3]);
			if(d == dist(x[2],x[1],y[2],y[1]) && d == d3)
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
		else if(d2 == d3 && 2*d2 == d4){
			LL d = dist(x[1],x[3],y[1],y[3]);
			if(d == dist(x[2],x[3],y[2],y[3]) && d == d2)
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
		else cout<<0<<endl;
	}
		
	return 0;
}
