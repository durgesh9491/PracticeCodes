#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};
int main()
{
    ios_base::sync_with_stdio(false);
    int n,ans=0;
    cin>>n;
    petrolPump p[n+1];
    int diff[n+1];
    for(int i=1;i<=n;i++) cin>>p[i].petrol>>p[i].distance, diff[i]=p[i].petrol-p[i].distance;
    int sum=0;
    for(int i=1;i<=n;i++){
    	sum+=diff[i];
    	if(sum<0){
    		sum=0;
    		ans=i;
    	}
    }
    cout<<ans<<endl;
    return 0;
}
