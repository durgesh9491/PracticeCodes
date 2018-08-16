/*
 * Program to rotate array by 'd'
 * Time complexity: O(n)
 * Space complexity: O(1)
 * 6 2 1 2 3 4 5 6
 */
 
#include<bits/stdc++.h>
using namespace std;

#define LL     long long int
#define ff     first
#define ss     second


const int M = 1e5;
const int MOD = 1e9 + 7;


void rotate(vector<int> &v, int st, int en){
	while(st < en){
		int tmp = v[st];
		v[st] = v[en];
		v[en] = tmp;
		st += 1;
		en -= 1;
	}
}

int main(){
	int n, d;
	cin >> n >> d;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}
	rotate(v, 0, d - 1);
	rotate(v, d, n - 1);
	rotate(v, 0, n - 1);
	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
}

