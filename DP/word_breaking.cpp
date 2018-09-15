/*
 * Code author      : Durgesh Soni
 * Problem link     : https://practice.geeksforgeeks.org/problems/word-break/0
 * Statement        : Check whether can we break the word in multiple tokens, such that each token is present in the given dictionary
 * To obtain        : Boolean result
 * Time Complexity  : DP: O(n ^ 3 * log(M)), Recursion: O(2 ^ n)
 * Space Complexity : O(M), M: Size of Dictionary
 */


#include<bits/stdc++.h>
using namespace std;

#define             pb                   push_back
#define             mp                   make_pair
#define             ff                   first
#define             ss                   second
#define             all(_)               _.begin(),_.end()
#define             sq(x)                ((x)*(x))
#define             sz(_)                int(_.size())
#define             len(_)               int(_.length())
#define             rep(i,a,b)           for(int i=(a);i<=(b);++i)
#define             rer(i,b,a)           for(int i=(b);i>=(a);--i)
#define             clr(x,_)             memset(x,_,sizeof(x))
#define             exist(x,_)           (((_).find(x))!=((_).end()))
#define             feach(c,_)           for(__typeof((c).begin()) _=(c).begin();_!=(c).end();++_)

#define             dbg1(x)              cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<endl;
#define             dbg2(x,y)            cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<" | "#y" = "<<y<<endl;
#define             dbg3(x,y,z)          cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
#define             dbg4(a,b,c,d)        cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
#define             dbg5(a,b,c,d,e)      cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;

typedef             long long int        LL;
typedef             pair<int,int>        PII;
typedef             vector<PII>          VPII;
typedef             vector<int>          VI;
typedef             vector<VI>           VVI;
typedef             vector<string>       VS;
typedef             priority_queue<int>  PQ;

const LL  INF       =                    1LL << 62;
const int MOD       =                    1e9 + 7;
const int M         =                    1e3 + 7;

int dp[M]; 
unordered_map<string, bool> dic;

bool inDictionary(const string &s){
	return dic.find(s) != dic.end();
}

bool word_break_dp(const string &s, int pos){
	if(pos == len(s)) return true;
	int &ret = dp[pos];
	if(ret != -1){
		return ret;
	}
	rep(k, pos, len(s)-1){
		if(inDictionary(s.substr(pos, k - pos + 1)) && word_break_dp(s, k + 1)){
			return (ret = true);
		}
	}
	return (ret = false);
}

bool word_break(const string &s){
	if(len(s) == 0) return true;
	rep(i, 1, len(s)){
		if(inDictionary(s.substr(0, i)) && word_break(s.substr(i, len(s) - i))){
			return true;
		}
	}
	return false ;
}

VS tokenize(const string &s){
	VS res;
	int i = 0;
	while(i < len(s)){
		int j = i;
		while(s[j] != ' ') j++;
		res.pb(s.substr(i, j - i));
		i = j + 1;
	}
	return res;
}

int main(){
	int n, t;
	string w;
	cin >> t;
	while(t--){
		cin >> n;
		getline(cin, w);
		getline(cin, w);
		VS words = tokenize(w);
		
		dic.clear();
		memset(dp, -1, sizeof dp);
		
		for(int i = 0; i < n; i++){
			dic[words[i]] = true;
		}
		cin >> w;
		word_break_dp(w, 0) ? cout << "Yes\n" : cout << "No\n";
	}	
}

/*
 * Input            :
2
12
i like sam sung samsung mobile ice cream icecream man go mango
ilike
12
i like sam sung samsung mobile ice cream icecream man go mango
idontlike
 
 * Output           : Yes No 
 */





