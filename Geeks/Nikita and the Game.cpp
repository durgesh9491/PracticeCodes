#include<bits/stdc++.h>
using namespace std;


const int M = (1<<15);
long long A[M];

long long sum(const int &l,const int &r){
	return A[r]-A[l-1];
}


int solve(int l,int r){
    int res=0;
	for(int i=l;i<r;i++){
		if(sum(l,i) == sum(i+1,r)){
			return max(res, max(solve(l,i), solve(i+1,r)) + 1);
		}
	}
    return 0;
}

int main(){
	int n,t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>A[i];
			A[i]+=A[i-1];
		}
		cout<<solve(1,n)<<endl;
	}
	return 0;
}
