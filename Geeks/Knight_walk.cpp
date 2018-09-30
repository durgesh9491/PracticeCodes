/*
 * Code author      : Durgesh Soni
 * Problem link     : https://practice.geeksforgeeks.org/problems/knight-walk/0
 * Statement        : Min distance to reach from source to destination for a knight
 * Idea             : BFS from source 
 * Time Complexity  : O(N * M)
 * Space Complexity : O(N * M)
 */
	
#include<bits/stdc++.h>
using namespace std;

#define LL        long long
#define pb        push_back
#define mp        make_pair
#define ff        first
#define ss        second
#define sz(_)     (int(_.size()))
#define len(_)    (int(_.length()))


const int M = 1e5 + 7;
const int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

bool valid(const int &x, const int &y, const int &n , const int &m){
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n, m, s1, s2, d1, d2, ans = -1;
	    cin >> n >> m >> s1 >> s2 >> d1 >> d2;
	    
	    bool vis[n + 1][m + 1];
	    memset(vis, false, sizeof vis);
	    queue<pair<pair<int, int>, int>  > Q;
	   
	    Q.push(mp(mp(s1, s2), 0));
	    vis[s1][s2] = true;
	    
	    while(!Q.empty()){
	        int x = Q.front().ff.ff;
	        int y = Q.front().ff.ss;
	        int cnt = Q.front().ss;
	        Q.pop();
	        
	        if(x == d1 && y == d2){
	            ans = cnt;
	            break;
	        }
	        
	        for(int i = 0; i < 8; i++){
	            int xx = x + dx[i];
	            int yy = y + dy[i];
	            if(valid(xx, yy, n, m) && !vis[xx][yy]){
	                vis[xx][yy] = true;
	                Q.push(mp(mp(xx, yy), cnt + 1));
	            }
	        }
	    }
	    cout << ans << endl;
    }
	return 0;
}
