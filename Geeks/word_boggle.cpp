#include<bits/stdc++.h>
using namespace std;

#define LL        long long
#define pb        push_back
#define mp        make_pair
#define sz(_)     (int(_.size()))
#define len(_)    (int(_.length()))

const int MX = 15;

char C[MX][MX];
bool vis[MX][MX];
int dx[] = {0,1,0,-1,1,1,-1,-1};
int dy[] = {1,0,-1,0,1,-1,1,-1};
int N, M, n;
string Map[MX];
map<string, bool> pref;
map<string, bool> ::iterator it;
set<string> ans;



bool matchPrefix(string &s){
	it = pref.find(s);
	if(it != pref.end()) return true;
	return false;
}

void solve(int& i, int& j, string& s){
	s += C[i][j];
	vis[i][j] = 1;
	for(int p = 0; p < n; p++){
		if(s.compare(Map[p]) == 0){
			ans.insert(s);
			break;
		}
	}
	for(int p = 0; p < 8; p++){
		int x = i + dx[p];
		int y = j + dy[p];
		if(x >= 0 && x < N && y >= 0 && y < M && !vis[x][y] && matchPrefix(s))
			solve(x, y, s);
	}
	s.erase(s.length()-1);
	vis[i][j] = 0;
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    ans.clear();
	    pref.clear();
	    string s ="";
	    
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> Map[i];
			string t = "";
			for(int j = 0; j < len(Map[i]); j++){
				t += Map[i][j];
				pref[t] = 1;
			}
		}
		cin >> N >> M;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				cin >> C[i][j];
				vis[i][j] = 0;
			}
		}
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				solve(i, j, s);
			}
		}
		if(ans.size() == 0) cout << "-1";
		else
		for(set<string>::iterator p = ans.begin(); p != ans.end(); p++){
			cout << *p << " ";
		}
		cout << endl;
    }
	return 0;
}


/*
Input:
1
4
GEEKS FOR QUIZ GO
3 3
G I Z U E K Q S E

Output:
GEEKS QUIZ
*/
