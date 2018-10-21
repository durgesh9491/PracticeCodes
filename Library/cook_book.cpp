#include<bits/stdc++.h>
using namespace std;


#define  LL    long long int

/*
 * Fast Input
 * Accepts positive and negative integers
 */
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
 * GCD and LCM
 * Complexity: O(Log(max(A,B)))
 */
LL gcd(LL a,LL b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

LL lcm(LL a,LL b){
	if(a == 0 || b == 0) return 0;
	if(a > b) swap(a, b);
	return (a / gcd(a, b)) * b;
}


/*
 * Fast Exponentiation for positive powers of base
 * Complexity: O(Log(b)) for (a ^ b) % MOD
 */
inline LL modexp(LL a, LL b, const LL &mod){
	if(b < 0) return 0;
	
	LL x = 1;
	a %= mod;
	
	while(b > 0){
		if(b & 1){
			x = (x * a) % mod;
		}
		b >>= 1;
		a  = (a * a) % mod;
	}
	
	return x;
}


/*
 * Fast Multiplication
 * Complexity: O(Log(b)) for (a * b) % MOD
 */
inline LL mulmod(LL a,LL b,const LL &mod){
	static const LL &INF = 1LL << 62;
	if(abs(a) < INF / abs(b)) return (a * b) % mod;
	
	LL x = 0;
	a %= mod;
	b %= mod;
	
	while(b > 0){
		if(b & 1){
			x += a;
			if(x >= mod){
				x -= mod;
			}
		}
		b >>= 1;
		a <<= 1;
		if(a >= mod){
			a -= mod;
		}
	}
	
	return x;
}


/*
 * Modular Multiplicative Inverse using Extended Euclidean Algorithm 
 * gcd(a,b) = 1 and b not need to be a prime Number
 * Complexity: O(Log(max(A,B)))
 */
LL extended_euclid(LL a, LL b) {
	if(gcd(a, b) != 1) return 0;
	
    LL x = 1, y = 0, t = b;
    LL xLast = 0, yLast = 1;
    LL q, r, m, n;
    
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    while(xLast < 0) xLast += t;
    
    return xLast;
}


/*
 * Lookup table
 * Inverse[A] % MOD where MOD need to be relatively prime with A
 * Proof: https://discuss.codechef.com/questions/1440/algorithm-to-find-inverse-modulo-m
 */
inline vector<LL> InverseMod(){
	static const LL &mod = 1e9 + 7;
	static const int &R  = 1e7 + 7;
	vector<LL> inverse(R);
	
	inverse[1] = 1;
	for(int i = 2; i < R; i++){
		inverse[i] = mod + ((- mod / i) * inverse[mod % i]) % mod;
	}
	
	return inverse;
}



/*
 * nCr lookup table
 * Complexity: O(M * M)
 */
inline vector<vector<int> > combination(){
	static const LL &mod = 1e9 + 7;
	static const int &M  = 1e4 + 7;
	vector<vector<int> > dp(M + 1, vector<int>(M + 1, 0));
	
	dp[0][0] = 1;
	for(register int i = 1; i < M; i++){
		for(register int j = 0; 2 * j <= i; j++){
			if(j == 0){
				dp[i][j] = dp[i][i] = 1;
			}
			else{
				dp[i][j] = dp[i][i-j] = (dp[i-1][j] + dp[i-1][j-1]);
				if(dp[i][j] >= mod){
					dp[i][j] -= mod;
					dp[i][i-j] = dp[i][j];
				}
			}
		}
	}
	
	return dp;
}


/*
 * nCr calculation
 * Complexity: O(min(N, N-R))
 */
inline LL combination(const LL &N, LL R){
	if(R > N || R <= 0 || N <= 0) return 0;
	
	const LL &mod = 1e9 + 7;
	R > (N - R) ? (R = N - R) : R;
	LL mul = 1;
	
	for(LL i = 0; i < R; i++){
		mul = ((mul * (N - i)) % mod) * modexp(i + 1, mod - 2, mod);
		if(mul >= mod){
			mul %= mod;
		}
	}
	
	return mul;
}


/*
 * Find nCr % p for huge values of n and r <= 10^9
 * Complexity:  O(p2 * Logp (n))
 */
inline LL Lucas(LL n, LL r, const LL &mod){
	if(n < 0 || r < 0) return 0;
	if(n == 0 && r == 0) return 1;
	LL x = n % mod;
	LL y = r % mod;
	if(y > x) return 0;
	return Lucas(n / mod, r / mod, mod) * combination(x, y);
}


/*
 * Lookup table
 * Catalan numbers: 2nCn / (n + 1)
 * Complexity: O(M * M)
 * Applications : Arrangement of parantheses, No of Binary Trees etc.
 */
inline vector<LL> genCat(){
	static const int &M  = 1e4 + 7;
	static const LL &mod = 1e9 + 7;
	vector<LL> catalan(M, 0);
	
	catalan[0] = catalan[1] = 1;
	for(register int i = 2; i < M; i++){
		for(register int j = 0; j < i; j++){
			catalan[i] += (catalan[j] * catalan[i - j - 1]) % mod;
			if(catalan[i] >= mod){
				catalan[i] -= mod;
			}
		}
	}
	
	return catalan;
}


/*
 * Factorial of a number % mod
 * Complexity: O(R)
 */
inline vector<LL> factorial(){
	static const LL &R = 1e8 + 7;
	static const LL &mod = 1e9 + 7;
	vector<LL> fact(R);
	
	fact[0] = 1;
	for(register int i = 1; i < R; i++){
		fact[i] = fact[i - 1] * i;
		if(fact[i] >= mod){
			fact[i] %= mod;
		}
	}
	
	return fact;
}


/*
 * Factorial of a number N <= 1000
 * Complexity: O(d ^ 2), where 'd': Number of digits in 'N'
 */
inline string fact(LL n){
	static const int &M  = 1e4 + 7;
	vector<int> F(M);
	int k = 0,c = 0;
	
	F[0] = 1;
	for(register int i = 1; i <= n; i++){
		for(register int j = 0; j <= k; j++){
			F[j] = F[j] * i + c;
			c = F[j] / 10;
			F[j] %= 10;
		}
		while(c > 0){
			++k;
			F[k] = c % 10;
			c /= 10;
		}
	}
	string ans = "";
	for(register int i = k; i >= 0; i--){
		ans += (F[i] + '0');
	}
	
	return ans;
}


/*
 * Striling's approximation
 * Length of a factorial Number N
 */
inline int fact_length(const double &x){
	double ans;
	static const double &PI = acos(-1.0);
	if(x < 3.0) ans = 1.0;
	else ans = floor((x * log(x) - x + (log(2.0 * PI * x)) / 2.0 ) / log(10.0)) + 1.0;
	return int(ans + 1e-12);
}


/*
 * Check if given number is prime
 * Complexity; O(sqrt(N))
 */
inline bool isPrime(const LL &x){
	if(x<= 3) return(x <= 1 ? 0 : 1);
	if(!(x & 1) || !(x % 3)) return 0;
	for(LL i = 5; i * i <= x; i += 6){
		if(!(x % i) || !(x % (i + 2))){
			return 0;
		}
	}
	return 1;
}


/*
 * Miller_rabbin Primality Testing
 * Complexity: O(log(N) ^ 3)
 */
inline bool miller(LL p){
	if(p == 2) return true;
	if((p & 1) == 0 || p <= 1) return false;
	
	static const int &IT = 5;
	LL s = p - 1, temp, res, a;
	
	while(s % 2 == 0) s >>= 1;
	for(register int it = 0; it < IT; ++it){
		a=(rand() % (p - 1)) + 1;
		temp = s;
		res = modexp(a, temp, p);
		while(temp != p-1 && res != 1 && res != p-1){
			res = mulmod(res, res, p);
			temp <<= 1;
		}
		if(res != p-1 && ((temp & 1) == 0))
		return false;
	}
	
	return true;
}


/*
 * Lookup table for prime numbers
 * Complexity: O(R * Log Log (R))
 */ 
inline vector<int> sieve(){
	static const int &R  = 1e8 + 7;
	vector<bool> isprime(R, false);
	vector<int> prime;
	
	for(register int i = 2; i * i <= R; ++i){
		if(!isprime[i]){
			for(register int j = i << 1; j < R; j += i){
				if(!isprime[j]){
					isprime[j] = 1;
				}
			}
		}
	}
	prime.push_back(2);
	for(register int i = 3; i < R; i += 2){
		if(!isprime[i]){
			prime.push_back(i);
		}
	}
	
	return prime;
}


/*
 * Segmented Sieve Range Marking, Applicable for N <= 10^14 and R - L <= 10^7
 * Complexity: O(R * Log Log (R)) 
 */
inline vector<LL> segmented_sieve(LL n, LL m){
	static const LL &U = 1e14 + 7;
	static const int &R  = 1e8 + 7;
	vector<LL> big_primes;
	
	if(n > U || m > U || n < 0 || m < 0 || m - n >= R) return big_primes;
	if(n == 1) n += 1;
	if(m == 1) m += 1;
	
	vector<bool> M(m - n + 1, false);
	const vector<int> &prime = sieve();

	for(register int i = 0; i < (int)prime.size() && 1LL * prime[i] * prime[i] <= m; ++i){
		for(LL j = ((prime[i] + n - 1) / prime[i]) * prime[i]; j <= m; j += prime[i]){
			if(j == prime[i]) continue;
			if(!M[j - n]) M[j - n] = true;
		}
	}
	for(register int i = 0; i <= m - n; i++)  if(!M[i]) big_primes.push_back(n + i);
	
	return big_primes;
}


/*
 * Euler Phi
 * Relative prime less than N
 * Complexity: O(R * log log (R))
 */
inline vector<LL> ETF_sieve(){
	static const int &R  = 1e8 + 7;
	vector<LL> ETF(R, 0);
	
	for(register int i = 1; i < R; ++i){
		ETF[i] = i;
	}
	for(register int i = 2; i < R; ++i){
		if(ETF[i] == i){
			ETF[i] = i - 1;
			for(register int j = i << 1; j < R; j += i){
				ETF[j]=((i - 1) * ETF[j]) / i;
			}
		}
	}
	
	return ETF;
}


/*
 * Euler Phi
 * Relative prime less than N
 * Complexity: O(sqrt(N))
 */
inline LL phi(LL n){
	if(n <= 0) return 0;
    LL res = n, i;
    
    if(!(n & 1)){
        res -= res >> 1;
        while(!(n & 1))
        n >>= 1;
    }
    for(i = 3; i * i <= n; i += 2){
		if(n % i == 0){
			res -= res / i;
			while(n % i == 0) n /= i;
		}
	}
    if(n > 1) res -= res / n;
    
    return res;
}


/*
 * matrix Exponentiation
 * Fibonacci number calculation
 * Complexity: O(log(N))
 */
inline void multiply(LL F[2][2],LL M[2][2], const LL &mod){
	LL x =  (F[0][0] * M[0][0] + F[0][1] * M[1][0]);
	LL y =  (F[0][0] * M[0][1] + F[0][1] * M[1][1]);
	LL z =  (F[1][0] * M[0][0] + F[1][1] * M[1][0]);
	LL w =  (F[1][0] * M[0][1] + F[1][1] * M[1][1]);
	
	F[0][0] = (x >= mod) ? (x %= mod) : x;
	F[0][1] = (y >= mod) ? (y %= mod) : y;
	F[1][0] = (z >= mod) ? (z %= mod) : z;
	F[1][1] = (w >= mod) ? (w %= mod) : w;
}

void matexp(LL F[2][2], int n, const LL &mod){
	if(n <= 1) return;
	LL M[2][2] = {{1, 1},{1, 0}};
	matexp(F, n >> 1, mod);
	multiply(F, F, mod);
	if(n & 1) multiply(F, M, mod);
}

inline LL Fib(const LL &n, const LL &mod){
	if(n <= 0) return n;
	LL F[2][2] = {{1, 1}, {1, 0}};
	matexp(F, n-1, mod);
    return F[0][0];
}


/*
 * Matrix Exponentiation
 * Fibonacci number calculation
 * Complexity: O(Log(N))
 * Without using extra space
 */
inline LL Fib(LL n){
	LL i, j, h, k, t;
	i = h = 1;
	j = k = 0;
	while (n > 0){
		if(n & 1){
			t = j * h;
			j = i * h + j * k + t;
			i = i * k + t;
		}
		t = h * h;
		h = 2 * k * h + t;
		k = k * k + t;
		n >>= 1;
	} 
	return j;
}


/*
 * Check Whether a number is Fibonacci Number or Not
 * Complexity: O(1)
 */
bool isFib(const LL &n){
	if(n < 0) return false;
	const LL &first = (5 * n * n + 4);
	const LL &second = (5 * n * n - 4);
	const LL &X = sqrt(first);
	const LL &Y = sqrt(second);
    return ((X * X == first) || (Y * Y == second));
}


/*
 * Merge Sort
 * Complexity: O(N * Log(N))
 */
inline bool sorted(const vector<int> &A){
	for(register int i = 1; i < (int)A.size(); i += 1){
		if(A[i] < A[i - 1]){
			return false;
		}
	}
	return true;
}

inline void merge(vector<int> &A, const int &low, const int &mid, const int &high){
	register int i = low, j = 0, m = mid + 1;
	static vector<int> temp((int)A.size());

	while(i <= mid && m <= high){
		if(A[i] <= A[m]){
			temp[j++] = A[i++];
		}
		else{
			temp[j++]=A[m++];
		}
	}
	while(i <= mid) temp[j++] = A[i++];
	while(m <= high)temp[j++] = A[m++];
	for(i = 0; i < j; ++i){
		A[i + low] = temp[i];
	}
}

void sort_partition(vector<int> &A, const int &start, const int &end){
	if(start < end){
		int mid = (start + end) / 2;
		sort_partition(A, start, mid);
		sort_partition(A, mid + 1, end);
		merge(A, start, mid, end);
	}
}

void merge_sort(vector<int> &v){
	if(sorted(v)) return;
	reverse(v.begin(), v.end());
	if(sorted(v)) return;
	
	sort_partition(v, 0, (int)v.size());
}


/*
 * Interval Merging
 * Complexity: O(N)
 */
bool cmp(const pair<int, int> &X,const pair<int, int> &Y){
	return (X.first != Y.first) ? (X.first < Y.first) : (X.second < Y.second);
}

inline vector<pair<int, int> > merge(vector<pair<int, int> > v){
	sort(v.begin(), v.end(), cmp); 
	vector<pair<int, int> > ans;
	int xx, yy, l = (int)v.size();
	
	for(register int i = 0; i < l; i++){
		xx = v[i].first;
		yy = v[i].second;
		while(i < l-1 && (v[i].second >= v[i+1].first)){
			i += 1;
			yy = max(yy, v[i].second);
		}
	    ans.push_back(make_pair(xx, yy));
    } 
    
    return ans;
}


/*
 * String tokenizing
 * Complexity: O(N)
 */
inline vector<string> tokenize(const string &s, const string &keys){
	vector<string> ans;
	int l = (int)s.length();
	string temp;
	
	for(register int i = 0; i < l; ++i){
		if(keys.find(s[i]) != std::string::npos)
		continue;
		temp = "";
		for(; i < l; ++i){
			if(keys.find(s[i]) != std::string::npos)
			break;
			temp += s[i];
		}
		if(temp[0] != ' ') ans.push_back(temp);
	}
	
	return ans;
}


/*
 * Graph Traversal
 * DFS
 * Complexity: O(|V| + |E|)
 * Parameters: 
 * 1. Graph, 
 * 2. State of the nodes
 * 3. Starting point
 * 4. Number of nodes in this subset of graph 
 */

void dfs(const vector<vector<int> > &G, vector<bool> &vis, const int &v, int &comp_cnt){
	vis[v] = true;
	comp_cnt += 1;
	
	for(register int i = 0; i < (int)G[v].size(); i++){
		const int &adj = G[v][i];
		if(vis[adj] == false){
			dfs(G, vis, adj, comp_cnt);
		}
	}
}


/*
 * BFS
 * Complexity: O(|V| + |E|)
 * 
 * Parameters:
 * 1. Graph
 * 2. Number of nodes
 * 3. Source vertex
 * 
 * Computes: 
 * 1. Visit array
 * 2. Distance vector from given source
 * 3. Parent of each node
 * 4. Level order traversal of graph
 */
void bfs(const vector<vector<int> > &G, const int &N, const int &v){
	vector<bool> vis(N + 1, false);
	vector<int> dist(N + 1, 0);
	vector<int> par(N + 1, -1);
	queue<int> Q;
	
	vis[v] = true;
	dist[v] = 0;
	par[v] = v;
	Q.push(v);
	
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		
		for(register int i = 0; i < (int)G[cur].size(); i++){
			const int &adj = G[cur][i];
			if(vis[adj] == false){
				vis[adj] = true;
				dist[adj] = dist[cur] + 1;
				par[adj] = cur;
				Q.push(adj);
			}
		}
	}
}


/*
 * Dijkstra's Algorithm
 * Complexity: O((|E| + |V|)log|v|)
 * 
 * Parameters:
 * 1. Graph
 * 2. Number of nodes
 * 3. Source vertex
 * 
 * Computes:
 * 1. Single source shortest path to all the nodes
 * 2. Doesn't work for -ve weight cycle containing Graph
 */
inline void Dij(const vector<vector<pair<int, int> > > &G, const int &N, const int &s){
	const int &INF = 1 << 30;
	set<pair<int, int> > Q;
	vector<int> dist(N + 1, INF);
	 
	dist[s] = 0;
	Q.insert(make_pair(0, s));
	
	while(!Q.empty()){
		const pair<int, int> &top = *Q.begin();
		const int &v = top.second;
		Q.erase(Q.begin());
		for(register int i = 0; i < (int)G[v].size(); i++){
			const int &adj = G[v][i].first;
			const int &cost = G[v][i].second;
			if (dist[adj] > dist[v] + cost){
				if (dist[adj] != INF){
					Q.erase(Q.find(make_pair(dist[adj], adj)));
				}
				dist[adj] = dist[v] + cost;
				Q.insert(make_pair(dist[adj], adj));
			}
		}
	}
}


/*
 * Floyed Warshall Algorithm
 * Complexity: O(N ^ 3)
 * 
 * Parameters:
 * 1. Graph(1 based indexing, pair: first -> adj, second -> distance
 * 2. Number of Nodes
 * 
 * Computes:
 * 1. All pair shortest path
 * 2. Detects cycle with some negative weighted edges
 */
vector<vector<int> > floyed(const vector<vector<pair<int, int> > > &G, const int &N){
	
	const int &INF = 1 << 30;
	vector<vector<int> > dp(N + 1, vector<int>(N + 1, INF));
	
	for(register int i = 1; i <= N; i++){
		for(register int j = 1; j <= N; j++){
			dp[i][j] = G[i][j].second;
		}
		dp[i][i] = 0;
	}
	
	for(register int i = 1; i <= N; i++){
		for(register int j = 1; j <= N; j++){
			for(register int k = 1; k <= N; k++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	
	return dp;
}



/*
 * Prim's Algorithm
 * Similar to Dijkstra's Algorithm
 * Complexity: O((|E| + |V|)log|v|)
 * 
 * Parameters:
 * 1. Graph
 * 2. Number of vertices
 * 
 * Computes:
 * 1. Minimum cost spanning tree of the given graph
 */
inline int prim(const vector<vector<pair<int, int> > > &G, const int &N, const int &s){
	const int &INF = 1 << 30;
	set<pair<int, int> > Q;
	vector<int> dist(N + 1, INF);
	int ans = 0;
	 
	dist[s] = 0;
	Q.insert(make_pair(0, s));
	
	while(!Q.empty()){
		const pair<int, int> &top = *Q.begin();
		const int &v = top.second;
		Q.erase(Q.begin());
		ans += top.first;
		for(register int i = 0; i < (int)G[v].size(); i++){
			const int &adj = G[v][i].first;
			const int &cost = G[v][i].second;
			if (dist[adj] > cost){
				if (dist[adj] != INF){
					Q.erase(Q.find(make_pair(dist[adj], adj)));
				}
				dist[adj] = cost;
				Q.insert(make_pair(dist[adj], adj));
			}
		}
	}
	
	return ans;
}



/*
 * Kruskal's Algorithm
 * Complexity: O(|E| * log|E|)
 * Using the concept of Disjoint set union
 * 
 * Parameters:
 * 1. Pair of edge cost and pair of vertices having that edge
 * 2. Number of vertices
 * 3. Number of edges
 * 
 * Computes:
 * 1. Minimum cost spanning tree of the given graph 
 */

int root(int x, vector<int> &id){
    while(id[x] != x){
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void uniun(int x, int y, vector<int> &id){
    id[root(x, id)] = id[root(y, id)];
}

int kruskal(pair <int, pair<int, int> > edges[], const int &N, const int &M){
	if(N <= 0 || M <= 0) return 0; 
	
	vector<int> id(N + 1);
	for(register int i = 0; i <= N; i++) id[i] = i;
	int min_cost = 0;
	
	sort(edges, edges + N);
    for(register int i = 0; i < M; ++i){
        int x = edges[i].second.first;
        int y = edges[i].second.second;
        if(root(x, id) != root(y, id)){
            min_cost += edges[i].first;
            uniun(x, y, id);
        }    
    }
    
    return min_cost;
}



/* 
 * Binary Indexed Tree
 * Complexity: O(N *log(N))
 * Note: i,j,b are 1 based indexed
 * 
 * Application:
 * 1. Point query: O(log N)
 * 2. Point update: O(log N)
 * 3. Range update: O(log N)
 */
class BIT{
    private:
		LL *tree;
		static const int M = 2e7 +  5;
	
	public:
		BIT(int sz = M){
			tree = new LL[sz];
		}
		
		inline LL point_query(int b){
			LL sum = 0;
			for(; b; b -= (b & (-b))) sum += tree[b];
			return sum;
		}

		inline void update(int k, const int &v, const int &N){
			   for(; k <= N; k += (k & (-k)))
			   tree[k] += v;
		}

		inline void range_update(const int& i,const int& j,const int& v, const int &N){
			update(i, v, N);
			update(j + 1, -v, N);
		}
};



int main(){
	ios_base::sync_with_stdio(false);
}
