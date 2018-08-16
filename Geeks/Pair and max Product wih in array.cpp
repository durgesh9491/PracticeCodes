#include <bits/stdc++.h>
using namespace std;

/*
 * Complexity: O(n * sqrt(A) * log(n))
 */ 

int search(vector<int> &v, int ele, int idx){
	int res = -1;
	int l=0, h = (int)v.size(), mid;
	while(l <= h){
		mid = (l + h)/2;
		if(v[mid] == ele && mid != idx){
			res = mid;
			break;
		}
		if(v[mid] < ele)
			l = mid + 1;
		else h = mid - 1;
	}
	return res;
}

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		vector<int> A(n);
		
		for(int i = 0; i < n; i++) cin >> A[i];
		sort(A.begin(), A.end());
		
		int ans = -1;
		for(int i = n-1; i >=0; i--){
			int ele = A[i];
			for(int j = 1; j * j <= ele; j++){
				if(ele % j == 0){
					int x = search(A, j, i);
					int y = search(A, ele / j, x);
					if(x != -1 && y != -1){
						ans = A[i];
						break;
					}
				}
			}
			if(ans != -1) break;
		}
		cout << ans << endl;
	}
	return 0;
}

