/*
 * Night's tour Problem
 * Backtracking(Try every solution)
 * Time Complexity: O(k^n), where k is samll constant and n is the number of squares on the chess board.
 * Computation depends on dx and dy vector.
 */
 
#include<bits/stdc++.h>
using namespace std;

const int M = 1e3 + 5;
const int dxy = 8;
int visit[M][M];

bool valid(int &x, int &y, int &sz){
	return (x >= 0 && y >= 0 && x < sz && y < sz && visit[x][y] == -1);
}

int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
	
bool tour(int x, int y, int cnt, int sz){
    if(cnt == sz * sz) return true;
	int nx, ny;
	for(int i = 0; i < dxy; i++){
		nx = x + dx[i];
		ny = y + dy[i];
		if(valid(nx, ny, sz)){
			visit[nx][ny] = cnt;
			if(tour(nx, ny, cnt + 1, sz) == true)
				return true;
			else
				visit[nx][ny] = -1;
		 }
	 }
	 return false;
}

int main(){
	int board_size;
	cin >> board_size;
	memset(visit, -1, sizeof visit);
	visit[0][0] = 0;
	if(tour(0, 0, 1, board_size) == true){
		cout << "Tour successful" << endl;
		for(int i = 0; i < board_size; i++){
			for(int j = 0; j < board_size; j++){
				printf(" %2d ", visit[i][j]);
			}
			cout << endl;
		}
	}
	else{
		cout << "Not possible !" << endl;
	}
}
