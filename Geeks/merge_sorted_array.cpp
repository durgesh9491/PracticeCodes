#include<bits/stdc++.h>
using namespace std;


vector<int> merge(vector<int> &a, vector<int> &b){
	vector<int> ans;
	int i = 0, j = 0, k = a.size(), l = b.size();
	while(i < k && j < l){
		if(a[i] >= b[j])
			ans.push_back(a[i++]);
		else
			ans.push_back(b[j++]);
	}
	while(i < k) ans.push_back(a[i++]);
	while(j < l) ans.push_back(b[j++]);
	return ans;
}

int  main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> m >> n;
		vector<int> v1(m), v2(n);
		for(int i = 0; i < m; i++){
			cin >> v1[i];
		}
		for(int i = 0; i < n; i++){
			cin >> v2[i];
		}
		sort(v1.begin(), v1.end(), greater<int>());
		sort(v2.begin(), v2.end(), greater<int>());
		const vector<int>& ans = merge(v1, v2);
		for(int i = 0; i < m + n; i++){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}
