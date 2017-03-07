#include <iostream>
#include<stdio.h>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
 int n,x,a,i,j,b,diff=0;
    cin>>n;


    for(i=0;i<n;i++){
        for(j=0;j<n;j++){

        if(i==j)
    cin>>a;
     if(j==(n-i))
        cin>>b;
    else
        cin>>x;
    }
    cout<<a<<" "<<b<<endl;
    diff= diff+(a-b);
    }
cout<<abs(diff);

return 0;
}
