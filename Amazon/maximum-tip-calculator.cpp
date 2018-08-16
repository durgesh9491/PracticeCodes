#include<bits/stdc++.h>
using namespace std;

const int M = 1e2 + 6;

bool comp(pair<int, int>& a, pair<int, int>& b){
	return abs(a.first - a.second) > abs(b.first - b.second);
}


int main(){
	int t, n, x, y;
	cin >> t;
	while(t--){
		cin >> n >> x >> y;
		vector<pair<int, int> > a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i].first;
		}
		for(int i = 0; i < n; i++){
			cin >> a[i].second;
		}
		sort(a.begin(), a.end(), comp);
		int ans = 0;
		for(int i = 0; i < n; i++){
			if((x > 0 && a[i].first >= a[i].second) || y == 0){
				ans += a[i].first;
				x--;
			}
			else if(y > 0 || x == 0){
				ans += a[i].second;
				y--;
			}
		}
		cout << ans << endl;
	}
}
