#include<bits/stdc++.h>
using namespace std;

#define LL     long long int
#define ff     first
#define ss     second
#define pb     push_back
#define sz(_)  (int(_.size()))
#define len(_) (int(_.length()))


typedef pair<int, int> PI;
typedef vector<int> VI;

const int M = 1e5;
const int MOD = 1e9 + 7;

VI G[M];

void printDFS(int &s, int &d, VI &visit, VI &path, vector<VI> &ans){
	if(s == d){
		ans.pb(path);
		return;
	}
	for(int i = 0; i < sz(G[s]); i++){
		if(visit[G[s][i]] == false){
			path.pb(G[s][i]);
			visit[G[s][i]] = true;
			printDFS(G[s][i], d, visit, path, ans);	
			
			//backtrack
			path.pop_back();
			visit[G[s][i]] = false;	
		}
	}		
}
int main(){
	int t, v, e, s, d;
	cin >> t;
	while(t--){
		cin >> v >> e;
		for(int i = 0; i < v; i++){
			G[i].clear();
		}
		
		VI inp(2*e);
		for(int i = 0; i < 2 * e; i++){
			cin >> inp[i];
		}
		for(int i = 0; i < 2 * e; i += 2){
			G[inp[i]].pb(inp[i + 1]);
		}		
		cin >> s >> d;
		vector<VI> ans;
		VI path, visit(v, 0);
		path.pb(s);
		visit[s] = true;
		printDFS(s, d, visit, path, ans);
		cout << sz(ans) << endl;
	} 
}


