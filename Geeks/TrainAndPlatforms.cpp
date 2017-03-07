#include<bits/stdc++.h>
using namespace std;


#define M   10000
int A[M],D[M];

int main(){
	int n,ans=1;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>A[i]>>D[i];
	}
	sort(A,A+n);
	sort(D,D+n);
	int i=1,j=0,plat=ans;
	while(i<n && j<n){
		if(D[j]>=A[i]){
			++ans;
			plat=max(plat,ans);
			++i;
		}
		else{

			++i;++j;
		}
	}
	cout<<plat<<endl;
}
