#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
	
	private:
		static const int M = 1e5 + 7;
		int *par;
		int *rank;
	
	public:
		DisjointSet(const int &N = M){
			par = new int[N];
			rank = new int[N];
			
			for(int i = 1; i <= N; i++){
				par[i] = i;
				rank[i] = 0;
			}
		}

		int findSet(int x){
			while(par[x] != x){
				par[x] = par[par[x]];
				x = par[x];
			}
			return x;
		}

		void mergeSet(const int &x, const int &y){
			const int &p_x = findSet(x);
			const int &p_y = findSet(y);
			
			if(rank[p_x] > rank[p_y])
				par[p_y] = p_x;
			else
				par[p_x] = p_y;
			
			if(rank[p_x] == rank[p_y])
				rank[p_y]++;
		}

		bool isSameSet(const int &x, const int &y){
			return (findSet(x) == findSet(y));
		}
};


int main(){
    return 0;
}
