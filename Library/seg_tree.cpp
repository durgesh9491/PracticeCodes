#include<bits/stdc++.h>
using namespace std;

#define LL         long long int

template<typename T>
void inp(T &x){
	register T c = getchar_unlocked();
	x = 0;
	bool neg = false;
	for(;((c < '0' || c > '9') && c != '-');
	c = getchar_unlocked());
	if(c == '-'){
		neg = true;
		c = getchar_unlocked();
	}
	for(;c >= '0' && c <= '9'; c = getchar_unlocked()){
		x = (x * 10) + (c - '0');
	}
	x = neg ? -x : x;
}


/*
 * Segment Tree
 * Time complexities:
 * 1. build: O(N * log N)
 * 2. range_query: O(log N)
 * 3. range_update: O(log N)
 * 4. point_update: O(log N)
 * 
 * Space Complexity: O(4 * N)
 * 
 * Problem: https://www.spoj.com/problems/HORRIBLE/
 */
 
template <typename T>
class Node{
		
	public:		
		
		T sum, lazy;
		int cnt;
		
		Node(){
			sum = 0; 
			lazy = 0;
		}

		void leaf(const T &val, const int &range){
			sum = val;
			cnt = range;
		}
		
		void update_leaf(const T &val){
			sum = val;
		}
		
		void update(const T &val, const int &cnt){
			sum += val * cnt;
		}
		
		void merge(const Node &l,const Node &r){
			sum = l.sum + r.sum;
			cnt = l.cnt+ r.cnt;
			if(l.lazy > 0) update(l.lazy, l.cnt);
			if(r.lazy > 0) update(r.lazy, r.cnt);
		}
		
		void split(Node &l, Node &r, const LL &val){
			l.lazy += val;
			r.lazy += val;
		}
};


template <typename T>
class SegTree{
	
	private:

		static const int M = 1e5 + 3;
	
	public:
	
		Node<T> *tree;
		SegTree(int sz = M){
			tree = new Node<T> [4 * sz]; 
		}
		
		void build(const vector<T> &v, const int &root, const int &l, const int &r){
			Node<T> &ref = tree[root];
			
			if(l == r){
				ref.leaf(v[l], r - l + 1);
				return;
			}
			
			const int &mid = (l + r) / 2, &lchild = 2 * root, &rchild = lchild + 1;
			
			build(v, lchild, l, mid);
			build(v, rchild, mid + 1, r);
			ref.merge(tree[lchild], tree[rchild]);
		}

		Node<T> range_query(const int &root, const int &l, const int &r, const int &u, const int &v){
			const int &mid = (l + r) / 2, &lchild = 2 * root, &rchild = lchild + 1;
			Node<T> &ref = tree[root];
			
			if(ref.lazy > 0){
			   ref.update(ref.lazy, ref.cnt);
			   if(r != l) ref.split(tree[lchild], tree[rchild], ref.lazy);
			   ref.lazy = 0;
			}  
			
			if(l == u && r == v)
			return ref;
			
			if(u > mid)  return range_query(rchild, mid + 1, r , u, v);
			else if(v <= mid) return range_query(lchild, l, mid, u, v);
			else{
				Node<T> ret;
				ret.merge(range_query(lchild, l, mid, u, mid), range_query(rchild, mid + 1, r, mid + 1 ,v));
				return ret;
			}
		}

		void point_update(const int &root, const int &l, const int &r, const int& ind, const T& val){
			Node<T> &ref = tree[root];
			if(l == r){
				ref.update_leaf(val);
				return;
			}
			
			const int &mid = (l + r) / 2, &lchild = 2 * root, &rchild = lchild + 1;
			
			if(ind <= mid) point_update(lchild, l, mid, ind, val);
			else  point_update(rchild, mid + 1, r, ind, val);
			
			ref.merge(tree[lchild], tree[rchild]);
		}

		void range_update(const int &root, const int &l, const int &r, const int &u, const int &v,const T &val){
			const int &mid = (l + r) / 2, &lchild = 2 * root, &rchild = lchild + 1;
			
			Node<T> &ref = tree[root];
			if(ref.lazy > 0){
			   ref.update(ref.lazy, ref.cnt);
			   if(r != l) ref.split(tree[lchild], tree[rchild], ref.lazy);
			   tree[root].lazy = 0;
			}
			
			if(l == u && r == v){
			   ref.update(val, ref.cnt);
			   if(r != l) ref.split(tree[lchild], tree[rchild], val);
			   return ;
			}
			
			if(u > mid) range_update(rchild, mid + 1, r, u, v,val);
			else if(v <= mid) range_update(lchild, l, mid, u, v,val);
			else{
				range_update(lchild, l, mid, u, mid, val);
				range_update(rchild, mid + 1, r, mid + 1, v, val);
			}
			
			ref.merge(tree[lchild], tree[rchild]);
		}
};





int main(){
	int t;
	cin >> t;
	while(t--){
		int n,q,c,x,y;
		LL v;
		inp<int>(n), inp<int>(q);
		
		vector<LL> vv(n + 1, 0);
		SegTree<LL> obj(n);
		obj.build(vv, 1,1,n);
		
		while(q--){
			inp<int>(c),inp<int>(x),inp<int>(y);
			++c;
			if(c==1){
				inp<LL>(v);
				obj.range_update(1,1,n,x,y,v);
				continue;
			}
			printf("%lld\n",obj.range_query(1,1,n,x,y).sum);
		}
	}
    return 0;
}


