#include<bits/stdc++.h>
using namespace std;

#define LL        long long
#define pb        push_back
#define mp        make_pair
#define sz(_)     (int(_.size()))
#define len(_)    (int(_.length()))


const int MX = 100005;

map<char, int> val;
int main(){
	int t;
	cin>>t;
	string s;
	val['I'] = 1;
	val['V'] = 5;
	val['X'] = 10;
	val['L'] = 50;
	val['C'] = 100;
	val['D'] = 500;
	val['M'] = 1000;
	while(t--){
		cin>>s;
		int ans = 0;
		for(int i=0;i<len(s);i++){
			int x = val[s[i]];
			if(i+1 <len(s)){
				int y = val[s[i+1]];
				if(x>=y) ans +=x;
				else ans += -x;
			}
			else ans+=x;
		}
		cout<<ans<<endl;			
    }
	return 0;
}
