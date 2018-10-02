#include<bits/stdc++.h>
using namespace std;


int main(){
   int t, n;
   string a, b;
   cin >> t;
   while(t--){
	   cin >> n;
	   vector<string> v(n);
	   for(int i = 0;i < n; i++){
		   cin >> v[i];
	   }
	   cin >> a >> b;
	   int ans = INT_MAX, ia = -1, ib = -1, fa = 0, fb = 0;
	   for(int i = 0; i < n; i++){
		   if(v[i].compare(a) == 0){
			   ia = i;
			   fa = 1;
		   }
		   if(v[i].compare(b) == 0){
			   ib = i;
			   fb = 1;
		   }
		   if(fa & fb) ans = min(ans, abs(ia - ib));
	   }
	   cout << ans << endl;
   }
			   
}
