#include <bits/stdc++.h>
using namespace std;

const int M = 1e3 + 5;

typedef vector<vector<int> > VVI;
VVI G(M), revG(M);

bool visit[M];
stack<int> finish;
int cnt;

void DFS(VVI &g, int v){
	visit[v] = true;
	for(int i = 0; i < (int)g[v].size(); i++){
		if(visit[g[v][i]] == false){
			DFS(g, g[v][i]);
		}
	}
	finish.push(v);
}

void SCC(VVI &g, int v, int &cnt){
	visit[v] = true;
	cnt += 1;
	for(int i = 0; i < (int)g[v].size(); i++){
		if(visit[g[v][i]] == false){
			SCC(g, g[v][i], cnt);
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
			DFS(G, i);
		}
	}
	
	memset(visit, 0, sizeof visit);
	
	int c = 0, d = 0;
	/*
	 * c = Sum of number of nodes in all Strongly Connected Components with odd number of nodes.
	 * d = Sum of number of nodes in all Strongly Connected Components with even number of nodes.
	 */
	 
	while(!finish.empty()){
		int top = finish.top();
		finish.pop();
		cout << top << endl;
		if(visit[top] == false){
			cnt = 0;
			SCC(revG, top, cnt);
			if(cnt % 2) c += cnt;
			else d += cnt;
		}
	}
	//cout << c <<" | " << d << endl;
	cout<< c - d <<endl;
	return 0;
}
