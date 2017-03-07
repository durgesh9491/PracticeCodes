#include<bits/stdc++.h>
using namespace std;



#define dbg4(a,b,c,d)        cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;

#define sz    100
int M[sz][sz];

void printSpiral(int m,int n){
	int row=m,col=n, i=1,j=1;
	int up=0,down=0,left=0,right=0;
    
while(1){	
		while(j<=col-right){
			cout<<M[i][j]<<" ";
			j++;
		}
		up++;
		--j;
		++i;
		if(up+down==n || left+right==m)  break;
		//dbg2(i,j);
		while(i<=row-down){
			cout<<M[i][j]<<" ";
			i++;
		}
		right++;
		--j;
		--i;
		if(up+down==n || left+right==m)  break;
		//dbg2(i,j);
		while(j>=1 && j>left){
			cout<<M[i][j]<<" ";
			j--;
		}
		down++;
		++j;
		--i;
		if(up+down==n || left+right==m)  break;
		//dbg2(i,j);
		while(i>=1 && i>up){
			cout<<M[i][j]<<" ";
			--i;
		}
		left++;
		++i;
		++j;
		if(up+down==n || left+right==m)  break;
		//dbg2(i,j);
		//dbg4(up,down,left,right);
	}
}


int  main(){
	int m,n;
	cin>>n;
	m=n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>M[i][j];
		}
	}
	printSpiral(m,n);
	return 0;
}
