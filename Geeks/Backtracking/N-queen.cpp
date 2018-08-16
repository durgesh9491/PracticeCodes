/*
 * N-Queen problem
 * Complexity: O((n + 1)!)
 * Queens are placed from left to right in the columns
 */
 

#include<bits/stdc++.h>
using namespace std;

const int M = 1e3 + 5;
bool placed[M][M];

bool safe(int& x, const int& y, int& n){
	//check row leftwords
	for(int i = y - 1; i >= 0; i--){
		if(placed[x][i] == true){
			return false;
		}
	}
	
	//check left upper diagonal
	for(int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--){
		if(placed[i][j] == true){
			return false;
		}
	}
	
	//check left lower diagonal
	for(int i = x + 1, j = y - 1; i < n && j >= 0; i++, j--){
		if(placed[i][j] == true){
			return false;
		}
	}
	return true;
}


void tour(const int& col, int& n, vector<int> &current, vector<vector<int> > &ans){
	if((int)current.size() == n){
		ans.push_back(current);
		return;
	}	
	for(int i = 0; i < n; i++){
		if(safe(i, col, n)){
			placed[i][col] = true;
			current.push_back(i);
			tour(col + 1, n, current, ans);
			
			//backtrack
			current.pop_back();
			placed[i][col] = false;
		}
	}
}



int main(){
	int n, t;
	cin >> t;
	while(t--){
		cin >> n;
		memset(placed, 0, sizeof placed);
		vector<int> current;
		vector<vector<int> > ans;
		tour(0, n, current, ans);
		if(ans.size() > 0){
			for(int i = 0; i < (int)ans.size(); i++){
				cout << "[";
				for(int j = 0; j < (int)ans[i].size(); j++){
					cout << ans[i][j] + 1 << " ";
				}
				cout <<"] ";
			}
		}
		else cout <<"-1";
		cout << endl;
	}
}
