/*
 * Problem Author : Tanuj Khattar
 * Solution is to check SCC with size > 1
 */
#include <bits/stdc++.h>
using namespace std;

const int M = 1e5 + 5;

typedef vector<vector<int> > VVI;
VVI G(M), revG(M);

bool visit[M];
stack<int> finish;

void DFS(int v){
	visit[v] = true;
	for(int i = 0; i < (int)G[v].size(); i++){
		if(visit[G[v][i]] == false){
			DFS(G[v][i]);
		}
	}
	finish.push(v);
}

vector<int> candidates;
void SCC(int v){
	visit[v] = true;
	candidates.push_back(v);
	for(int i = 0; i < (int)revG[v].size(); i++){
		if(visit[revG[v][i]] == false){
			SCC(revG[v][i]);
		}
	}
}

int main(){
	int m, n;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		revG[y].push_back(x);
	}
	for(int i = 1; i <= n; i++){
		if(visit[i] == false){
			DFS(i);
		}
	}
	
	vector<bool> ans(n+1 ,0);
	memset(visit, 0, sizeof visit);
	
	while(!finish.empty()){
		int top = finish.top();
		finish.pop();
		if(!visit[top]){
			candidates.clear();
			SCC(top);
			int sz = (int)candidates.size();
			if(sz > 1){
				for(int i = 0; i < sz; i++){
					ans[candidates[i]] = true;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) cout << ans[i] <<" ";
	
	return 0;
}
	
