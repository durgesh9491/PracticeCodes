/*
 * Maximum sum subarray
 * Getting sum, length, start and end
 * Test cases
 * 8 -2 -3 4 -1 -2 1 5 -3
 * 11 -7 -2 -5 8 -6 5 -9 -9 7 5 4
 * 3 -1 -2 -3
 * 3 -3 1 -2
 * 3 -3 -2 -1
 * 3 -1 2 3
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	pair<int, int> p(-1,-1);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	int ans = INT_MIN, sum = 0, len = 0, st = -1, end = -1;

	for(int i = 0; i < n; i++){
		sum += v[i];
		if(st == -1) st = i;
		if(ans < sum){
			ans = sum;
			end = i;
			if(len <= (end - st + 1)){
				p.first = st;
				p.second = end;
				len = end - st + 1;
			}
		}
		if(sum < 0){
			sum = 0;
			st = -1, end = -1;
		}
	}
  cout << ans << " | " << p.first << "," << p.second << " | " << (p.second - p.first + 1) << endl;	
}


