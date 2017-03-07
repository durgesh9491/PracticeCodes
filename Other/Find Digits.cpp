#include<bits/stdc++.h>
using namespace std;

#define LL long long int

//array of Integer 
vector<int> vec;

int main(){
    int t;
    cin>>t;
    LL n,x;
    while(t--){
        vec.clear();
        cin>>n;
        x=n;
        // storing each digit of n in reverse order
        while(x>0){
            vec.push_back(x%10);
            x/=10;
        }
        reverse(vec.begin(),vec.end());
        
        //running time complexity: O(no of digits * no of digits)
        LL ans=0;
        for(int i=0;i<int(vec.size());i++){
            LL mod=0;
            if(vec[i]>0){
				for(int j=0;j<int(vec.size());j++){
					mod = mod*10 + vec[j];
					if(mod>=vec[i]){
						mod%=vec[i];
					}
				}
				if(mod==0) 
				++ans;
			}
        }
        cout<<ans<<endl;
    }
    return 0;
}
