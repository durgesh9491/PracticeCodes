#include<bits/stdc++.h>
using namespace std;

#define LL   long long

class MOD{
	
	public:	
		const int M = 1e6 + 7;
		static const int NO_OF_MODS = 2;
		const vector<int> primes = {111719239, 12997781};
		const vector<int> mods = {(LL)1e9 + 7, (LL)1e9 + 21};
		vector<int> inv[NO_OF_MODS];
	
		int modexp(int a, int b, const int &mod){
			if(b < 0) return 0;
			
			int x = 1;
			a %= mod;
			
			while(b > 0){
				if(b & 1){
					x = mul(x, a, mod);
				}
				b >>= 1;
				a  = mul(a, a, mod);
			}
			return x;
		}

		int add(const int &a, const int &b, const int &mod){
			int x = a + b;
			return (x >= mod) ? (x - mod) : x;
		}

		int mul(const int &a, const int &b, const int &mod){
			LL x = (1LL * a * b);
			return (x >= mod) ? (x % mod) : x;
		}

		int sub(const int &a, const int &b, const int &mod){
			int x = a - b;
			return (x < 0) ? (x + mod) : x;
		}
		
};

	
class StringHash : public MOD{
	
	private:
		vector<int> pre[NO_OF_MODS], suf[NO_OF_MODS];
		int len;

	public:
		StringHash(const string &inp){
			len = (int)inp.length();
			for(int i = 0; i < NO_OF_MODS; i++){
				inv[i].resize(len + 1);
				pre[i].resize(len + 1);
				suf[i].resize(len + 1);
			}
			
			for(int i = 0; i < NO_OF_MODS; i++){
				for(int j = 0; j <= len; j++){
					inv[i][j] = modexp(primes[i], mods[i] - j - 1, mods[i]);
				}
			}
			calHash(inp);
		}

		void calHash(const string &s){
			vector<int> prod(primes);
				
			for(int i = 0; i < NO_OF_MODS; i++){
				for(int j = 1; j <= len; j++){ 
					pre[i][j] = add(pre[i][j-1], mul(s[j-1], prod[i], mods[i]), mods[i]);
					prod[i] = mul(prod[i], primes[i], mods[i]);
				}
			} 
			
			prod = primes;
			for(int i = 0; i < NO_OF_MODS; i++){
				for(int j = len; j >= 1; j--){
					suf[i][j] = add(suf[i][j+1], mul(s[j-1], prod[i], mods[i]), mods[i]);
					prod[i] = mul(prod[i], primes[i], mods[i]);
				}
			} 	
		}

		vector<int> getForward(const int &l, const int &r){
			assert(l >= 1 && r <= len);
			vector<int> ret;
			for(int i = 0; i < NO_OF_MODS; i++){
				ret.push_back(mul(sub(pre[i][r], pre[i][l-1], mods[i]), inv[i][l-1], mods[i]));
			}
			return ret;
		}

		vector<int> getBackward(const int &l, const int &r){
			assert(l >= 1 && r <= len);
			vector<int> ret;
			for(int i = 0; i < NO_OF_MODS; i++){
				ret.push_back(mul(sub(suf[i][l], suf[i][r+1], mods[i]), inv[i][len-r], mods[i]));
			}
			return ret;
		}
};


int main(){
	string s;
	cin >> s;
	StringHash obj(s);
	while(1){
		int a, b;
		cin >> a >> b;
		const vector<int> &p = obj.getForward(a, b);
		const vector<int> &q = obj.getBackward(a, b);
		cout <<  p[0] << " | " << p[1]<< endl;
		cout <<  q[0] << " | " << q[1] << endl;
	}
}
