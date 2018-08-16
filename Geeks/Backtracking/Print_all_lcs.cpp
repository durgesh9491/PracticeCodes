/*
 * Print all lcs in lexographical order
 * Fill dp in bottum-up fashion
 * Complexity: O(26 * m * n)
 */
 
#include<bits/stdc++.h>
using namespace std;

#define LL        long long
#define pb        push_back
#define mp        make_pair
#define first     ff
#define second    ss
#define sz(_)     (int(_.size()))
#define len(_)    (int(_.length()))


const int M = 1e3 + 5;
int dp[M][M];

int LCS(string &a, string &b, const int& x, const int& y){
	if(x >= len(a) || y >= len(b)) return 0;
	int &ret = dp[x][y];
	if(ret != -1) return ret;
	
	if(a[x] == b[y]) ret = 1 + LCS(a, b, x + 1, y + 1);
	else ret = max(LCS(a, b, x + 1, y), LCS(a, b, x, y + 1));
	return ret;
}
	

void printLCS(string &a, string &b, string &current, int x, int y, int &lcs, const int &cur_lcs){
	if(cur_lcs == lcs){
		cout << current << " ";
		return;
	}
	
	for(char c = 'a'; c <= 'z'; c++){
		bool ok = false;
		for(int i = x; i < len(a); i++){
			if(c == a[i]){
				for(int j = y; j < len(b); j++){
					if(c == b[j]){
						if(LCS(a, b, i, j) == lcs - cur_lcs){
							current += c;
							printLCS(a, b, current, i + 1, j + 1, lcs, cur_lcs + 1);
							
							//backtrack
							current.pop_back();
							ok = true;
							break;
						}
					}
				}
			}
			if(ok) break;
		}
	}
}
		
	
int main(){
	int t;
	string a, b;
	cin >> t;
	while(t--){
		cin >> a >> b;
		memset(dp, -1, sizeof dp);
		int lcs = LCS(a, b, 0, 0);
		string str = "";
		printLCS(a, b, str, 0, 0, lcs, 0);
		cout << endl;
	}
}
