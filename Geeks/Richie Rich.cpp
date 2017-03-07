#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	string s;
	cin>>n>>k>>s;
	int cnt=0;
	bool h[int(s.length())];
	memset(h,0,sizeof(h));
	for(int i=0;i<n/2;i++){
		if(s[i]!=s[n-i-1]){
			++cnt;
			h[i]=1;
			s[i]=s[n-i-1]=max(s[i],s[n-i-1]);
		}
	}
	for(int i=0;i<n/2 && cnt<k;i++){
		if(s[i]!=9 && (h[i]>0 || cnt+2<=k)){
			s[i]=s[n-i-1]='9';
			cnt+=1;
		}
	}
	if((n%2==1) && cnt<k) s[n/2]='9';
	if(cnt<=k) cout<<s<<endl;
	else cout<<"-1";
	return 0;
}
