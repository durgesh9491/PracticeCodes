bool valid(int x, int y, int visit[MAX][MAX], int m[MAX][MAX], int n){
    return (x >= 0 && y >= 0 && x < n && y < n && visit[x][y] == -1 && m[x][y] == 1);
}


void tour(int x, int y, string s, vector<string> &ans, int m[MAX][MAX], int visit[MAX][MAX], int n, int *dx, int *dy, map<pair<int ,int>, char > &Map){
    
    if(x == n - 1 && y == n - 1){
        ans.push_back(s);
        return;
    }
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(valid(nx, ny, visit, m, n)){
            visit[nx][ny] = 1;
            s += Map[make_pair(dx[i], dy[i])];
            tour(nx, ny, s, ans, m, visit, n, dx, dy, Map);
            visit[nx][ny] = -1;
            s.pop_back();
        }
    }
    
}

vector<string> printPath(int m[MAX][MAX], int n)
{
    int visit[MAX][MAX];
    memset(visit, -1, sizeof visit);
    visit[0][0] = 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    vector<string> ans;
    map<pair<int ,int>, char > Map;
    Map[make_pair(1, 0)]  = 'D';
    Map[make_pair(-1, 0)]  = 'U';
    Map[make_pair(0, 1)]  = 'R';
    Map[make_pair(0, -1)]  = 'L';
    tour(0, 0, "", ans, m, visit, n, dx, dy, Map);
    sort(ans.begin(), ans.end());
    return ans;
    	
}
