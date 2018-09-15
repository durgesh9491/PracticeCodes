/*
 * Quick Sort
 * Average case: O(n * logn)
 * Worst case: O(n^2)
 */
 
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int st, int end){
	int p_idx = st;
	int pivot = v[end];
	for(int i = st; i < end; i++){
		if(v[i] < pivot){
			swap(v[p_idx++], v[i]);
		}
	}
	swap(v[p_idx], v[end]);
	return p_idx;
}
			

void quickSort(vector<int> &v, int st, int end){
	if(st <= end){
		int pivot = partition(v, st, end);
		quickSort(v, st, pivot - 1);
		quickSort(v, pivot + 1, end);
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
		quickSort(v, 0, n - 1);
		for(int i = 0; i < n; i++){
			cout << v[i] << " ";
		}
		cout << endl;
	}
}
