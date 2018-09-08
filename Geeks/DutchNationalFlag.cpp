/*
 * Sort an array of 0s, 1s and 2s
 * Time complexity: O(n) 
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
		for(int l = 0, m = 0, h = n - 1; m <= h;){
			switch(v[m]){
				case 0:
					swap(v[m++], v[l++]);
					break;
					
				case 1:
					m++;
					break;
					
				case 2:
					swap(v[m], v[h--]);
					break;
			}
		}  
		for(int i = 0; i < n; i++){
			cout << v[i] << " ";
		}		
		cout << endl;
	}
}
		
