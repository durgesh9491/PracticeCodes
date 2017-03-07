#include <iostream>
using namespace std;


#define LL long long 

LL MOD = 1000000000 +7;
LL modexp(LL a,LL b,const LL &mod){
	LL x=1;a%=mod;
	while(b>0){
		if(b&1){
			x*=a;
			if(x>=mod)x%=mod;
		}
		b>>=1;a*=a;
		if(a>=mod)a%=mod;
	}
	return x;
}


LL comb(const LL &N,LL R){
	if(R>N) return 0;
	R>(N-R)?(R=N-R):R;
	LL mul=1LL;
	for(LL i=0;i<R;i++){
		mul=((mul*(N-i))%MOD)*modexp(i+1,MOD-2,MOD);
		if(mul>=MOD) mul%=MOD;
	}
	return mul;
}

LL Lucas(LL n,LL r){
	if(n==0 && r==0) return 1;
	LL x=n%MOD;
	LL y=r%MOD;
	if(y>x) return 0;
	return Lucas(n/MOD,r/MOD)*comb(x,y);
}

LL n,r;
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	
	    cin>>n>>r;	cout<<comb(n,r)<<endl;
	    cout<<Lucas(n,r)<<endl;
	}
	return 0;
}
