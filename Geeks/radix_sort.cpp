/*
 * Radix Sort
 * Time Complexity: O(d * (n + b))
 */
 
#include<bits/stdc++.h>
using namespace std;

const int M = 10;

void radix_sort(vector<int> &v, int d){
	int n = (int)v.size();
	vector<int> count(M, 0), output(n);
	
	for(int i = 0; i < n; i++){
		count[(v[i] / d) % M] += 1;
	}

	for(int i = 1; i < M; i++){
		count[i] += count[i-1];
	}
	
	for(int i = n-1; i >= 0; i--){
		int idx = (v[i] / d) % M;
		output[count[idx] - 1] = v[i];
		count[idx] -= 1;
	}
	
	for(int i = 0; i < n ;i++){
		v[i] = output[i];
	}
}

int main(){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++){
			cin >> v[i];
		}
		int mx = *max_element(v.begin(), v.end());
		for(int d = 1; d < mx; d *= 10){ 
			radix_sort(v, d);
		}
		for(int i = 0; i < n; i++){
			cout << v[i] << " ";
		}
		cout << endl;
	}
}

/*
 * 1 7 99 170 2 34 57 108 64
 */
	
