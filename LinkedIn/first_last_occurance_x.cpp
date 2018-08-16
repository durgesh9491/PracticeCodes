#include<bits/stdc++.h>
using namespace std;


int Lsearch(vector<int> &v, int n, int ele){
	int ans = -1;
	int l = 0, h = n - 1, mid;
	while(l <= h){
		mid = (l + h) / 2;
		if(v[mid] == ele){
			ans = mid;
		}
		if(v[mid] >= ele)
			h = mid - 1;
		else
			l = mid + 1;
	}
	return ans;
}

int Rsearch(vector<int> &v, int n, int ele){
	int ans = -1;
	int l = 0, h = n - 1, mid;
	while(l <= h){
		mid = (l + h) / 2;
		if(v[mid] == ele){
			ans = mid;
		}
		if(v[mid] <= ele)
			l = mid + 1;
		else
			h = mid - 1;
	}
	return ans;
}


int main(){
	int n, t, ele;
	cin >> t;
	while(t--){
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++){
			cin >> v[i];
		}
		cin >> ele;
		pair<int, int> ans;
		ans.first = Lsearch(v, n, ele);
		ans.second = Rsearch(v, n, ele);
		if(ans.first != -1 && ans.second != -1)
			cout << ans.first << " " << ans.second << endl;
		else
			cout << "-1" <<endl;
	}	
}
