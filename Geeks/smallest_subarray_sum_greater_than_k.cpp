#include<bits/stdc++.h>
using namespace std;

#define LL        long long
#define pb        push_back
#define mp        make_pair
#define first        ff
#define second  ss
#define sz(_)     (int(_.size()))
#define len(_)    (int(_.length()))


const int M = 100005;


int main(){
	int t;
	cin>>t;
	while(t--){
	    int n, x;
	    cin >> n >> x;
	    vector<int> v(n);
	    for(int i = 0; i < n; i++) cin >> v[i];
	    int i = 0, j = 0;
	    int sum = 0, cnt = 0, mn = INT_MAX;
	    while(j < n){
	        sum += v[j];
	        cnt += 1;
            while(i < j && sum - v[i] > x){
                sum -= v[i];
                cnt -= 1;
                i += 1;
            }
	        j += 1;
	        if(sum > x) mn = min(mn, cnt);
	    }
	    cout << mn << endl;
    }
	return 0;
}
