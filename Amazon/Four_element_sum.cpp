#include<bits/stdc++.h>
using namespace std;

#define LL     long long int
#define ff     first
#define ss     second

typedef pair<int, int> PI;
typedef vector<int> VI;

const int M = 1e5;
const int MOD = 1e9 + 7;

int main(){
	int t, n, x;
	cin >> t;
	while(t--){
		cin >> n;
		VI v(n);
		for(int i = 0; i < n; i++){
			cin >> v[i];
		}
		cin >> x;
		sort(v.begin(), v.end());
		bool flag = false;
		for(int i = 0; !flag && i < n; i++){
			for(int j = i + 1; !flag && j < n - 2; j++){
				int k = j + 1, l = n - 1;
				int sum = v[i] + v[j];
				while(k < l){
					if(sum + v[k] + v[l] > x)
						l--;
					else if(sum + v[k] + v[l] < x)
						k++;
					else{
						flag = true;
						break;
					}
				}
			}
		}
		if(flag) cout << "1\n";
		else cout << "0\n";
	}			
}
