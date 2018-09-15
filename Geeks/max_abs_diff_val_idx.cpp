/*
 * Code author      : Durgesh Soni
 * Problem link     : https://www.geeksforgeeks.org/maximum-absolute-difference-value-index-sums/
 * Statement        : Maximum absolute difference of value and index sums
 * To obtain        : max(|A[i] - A[j]| + |i - j|) for all values of i & j
 * Time Complexity  : O(n)
 * Space Complexity : O(1)
 */
 
#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++){
			cin >> v[i];
		}
		int mx1, mx2 , mn1, mn2;
		mx1 = mx2 = INT_MIN;
		mn1 = mn2 = INT_MAX;
		
		for(int i = 0; i < n; i++){
			mx1 = max(mx1, v[i] + i);
			mn1 = min(mn1, v[i] + i);
			mx2 = max(mx2, v[i] - i);
			mn2 = min(mn2, v[i] - i);
		}
		cout << max(mx1 - mn1, mx2 - mn2) << endl;
	}
}

/*
 * Input: 1 10 -70 -64 -6 -56 64 61 -57 16 48 -98
 * Output: 167
 */
		
