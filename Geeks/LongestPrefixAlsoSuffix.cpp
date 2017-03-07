#include <bits/stdc++.h>
using namespace std;

#define MAX   100007
int F[MAX];
int solve(string s){
    int i=1,j=0,n=s.length();
    F[0]=0;
    while(i<n){
        if(s[i]==s[j]){
            F[i]=j+1;
            i++;
            j++;
        }
        else if(j>0){
            j=F[j-1];
        }
        else{
            F[i]=0;
            i++;
        }
    }
    return F[n-1];
}


int main() {
    string s;
    int t;
    cin>>t;
    while(t--){
        memset(F,0,sizeof F);
        cin>>s;
        cout<<solve(s)<<endl;
    }
	return 0;
}
