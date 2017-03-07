#include<bits/stdc++.h>
using namespace std;

#define LL        long long
#define pb        push_back
#define mp        make_pair
#define sz(_)     (int(_.size()))
#define len(_)    (int(_.length()))


const int MX = 100005;


int main(){
	int t, n, x;
	cin>>t;
	while(t--){
		cin>>n;
		LL mod[3]={0};
		for(int i=0;i<n;i++){
			cin>>x;
			mod[x%3]++;
		}
		LL ans = (mod[0] * (mod[0]-1))/2;
		ans += mod[1] * mod[2];
		ans += (mod[0] * (mod[0]-1) * (mod[0]-2))/6;
		ans += (mod[1] * (mod[1]-1) * (mod[1]-2))/6;
		ans += (mod[2] * (mod[2]-1) * (mod[2]-2))/6;
		ans += (mod[0] * mod[1] * mod[2]);
		cout<<ans<<endl;
    }
	return 0;
}

