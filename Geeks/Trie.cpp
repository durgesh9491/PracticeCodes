#include<bits/stdc++.h>
using namespace std;


#define LL    long long 
#define M     100007
#define cap   62

struct TrieNode{
	int bit[2];
};


class Trie{
	private:
		int id;
		TrieNode node[M*cap];
	
	public:
		void init(){ 
			id=0; 
		}
		
		int newNode(){
			node[id].bit[0] = node[id].bit[1] = -1;
			return id++;
		}
			
		void insert(int root, const LL& val){
			for(int i=cap;i>=0;i--){
				bool set = val&(1LL<<i);
				if(set){
					if(node[root].bit[1] == -1){
						node[root].bit[1] = newNode();
					}
					root= node[root].bit[1];
				}
				else{
					if(node[root].bit[0]==-1){
						node[root].bit[0] = newNode();
					}
				    root= node[root].bit[0];
				}
			}
		}

		LL query(int root, const LL &val){
			LL ans=0;
			for(int i=cap;i>=0;i--){
				bool set = val&(1LL<<i);
				if(node[root].bit[1-set] !=- 1){
					root= node[root].bit[1-set];
					ans|= (1LL<<i);
				}
				else{
					root = node[root].bit[set];
				}
			}
			return ans;
		}
}Obj;



int main(){
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		LL ans = 0,pre = 0, x;
		Obj.init();
		int root = Obj.newNode();
		Obj.insert(root,0);
		for(int i = 1 ;i <= n; i++){
			cin >> x;
			pre = pre ^ x;
			ans = max(ans, Obj.query(root, pre));
			Obj.insert(root, pre); 
		}
		cout << ans << endl;
	}
	return 0;
}
			
