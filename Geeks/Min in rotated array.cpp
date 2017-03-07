#include<bits/stdc++.h>
using namespace std;

int main() {
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        int l=0, h=n-1,idx=-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(v[mid]>v[mid+1]){
                idx = mid;
                break;
            }
            if(v[mid]<v[mid-1]){
				idx= mid-1;
				break;
			}
			if(v[l]<=v[mid]) l=mid+1;
			else h=mid-1; 
        }
        cout<< idx <<" " << v[idx] <<endl;
        cout<<min(v[0],v[idx+1])<<endl;
    }
	return 0;
}
