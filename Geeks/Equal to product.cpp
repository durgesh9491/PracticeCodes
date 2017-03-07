#include<bits/stdc++.h>
using namespace std;

#define LL   long long
#define pb   push_back
#define mp   make_pair

const int MX = 100000;

int A[MX];
int main(){
	int t, n, prod;
	cin>>t;
	while(t--){
		cin>>n>>prod;
		set<int> Hash;
		set<int> ::iterator it;
		// can be done in avg. case find complexity O(1) using unordered_set but it becomes O(size of set) in worst case
		// so better to do it in O(N * log(N))
		bool ok = 0;
		for(int i=0;i<n;i++){
			cin>>A[i];
			if(A[i] == 0 && prod == 0) ok = 1;
			Hash.insert(A[i]);
		}
		for(int i=0;i<n;i++){
			if(A[i]>0 && prod%A[i] == 0){
				it = Hash.find(prod/A[i]);
				if(it != Hash.end()){
					ok =1;
					break;
				}
			}
		}
		if(ok) cout<<"Yes\n";
		else cout<<"No\n";
	}
			
	return 0;
}
