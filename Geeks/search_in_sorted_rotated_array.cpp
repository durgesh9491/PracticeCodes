#include<bits/stdc++.h>
using namespace std;

#define LL     long long int
#define ff     first
#define ss     second


const int M = 1e5;
const int MOD = 1e9 + 7;


int rotatedSearch(vector<int> &v, int l, int h, int ele){
	int mid  = (l + h)/2;
	if(ele == v[mid]) return mid;
	if(v[mid] > v[mid + 1] && v[mid] > v[mid - 1]){
		if(ele < v[mid]){
			rotatedSearch(v, l, mid - 1, ele);
		}
		else{
			rotatedSearch(v, mid + 1, h, ele);
		}
	}
	else if(v[mid] < v[mid -1] && v[mid] < v[mid + 1]){
		if(ele < v[mid]){
			rotatedSearch(v, l, mid - 1, ele);
		}
		else{
			rotatedSearch(v, mid + 1, h, ele);
		}
	
	return -1;
}
int main(){
	int n, ele;
	cin >> n >> ele;
	vector<int> v(n);
	for(int i = 0; i < n; i++){ 
		cin >> v[i];
	}
	int x = rotatedSearch(v, 0, n-1, ele);
	x != -1 ? cout << x : cout << "Not found";
}

