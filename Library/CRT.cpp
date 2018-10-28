#include<bits/stdc++.h>
using namespace std;

#define LL    long long

class CRT{
	
	private:
		
		const int R  = 1e6 + 7;
		const LL INF = 2e18;
		vector<LL> pfactor;
		vector<pair<LL, LL> > prime_rep;
		vector<vector<LL> > prime_powers;
		vector<vector<LL> > prime_factors;

		LL EED(LL a, LL b, LL &x, LL &y) {
			LL pp = y = 0;
			LL qq = x = 1;
			LL q, t;
			
			while(b > 0){
				q = a / b;
				t = b; b = a % b; a = t;
				t = pp; pp = x - q * pp; x = t;
				t = qq; qq = y - q * qq; y = t;
			}
			
			return a;
		}
				
		pair<LL, LL> chinese_remainder_again(const LL &x, const LL &a, const LL &y, const LL &b) {
			LL s, t;
			const LL &d = EED(x, y, s, t);
			if (a % d != b % d) return make_pair(0, -1);
			const LL &m = (x * y);
			const LL &ans = add(mul(s + m, mul(b, x, m), m), mul(t + m, mul(a, y, m), m), m);
			return make_pair(ans / d, m / d);
		}

		pair<LL, LL> chinese_remainder(const vector<LL> &x, const vector<LL> &a) {
			pair<LL, LL> ret = make_pair(a[0], x[0]);
			
			int n = (int)x.size();
			for(int i = 1; i < n; i++){
				ret = chinese_remainder_again(ret.second, ret.first, x[i], a[i]);
				if(ret.second == -1) break;
			}
			
			return ret;
		}

		LL inverseMod(const LL &a, const LL &n){
			LL x, y;
			const LL &ret = EED(a, n, x, y);
			if (ret > 1) return -1;
			return x;
		}

		LL factNfact(const LL& n, const LL& m, const LL& p, const vector<LL>& ref){
			if (n <= 1) return 1;
			if (n < m) return mul(ref[n], factNfact(n / p, m, p, ref), m);
			const LL &a = ref[m - 1];
			const LL &b = ref[n % m];
			const LL &c = factNfact(n / p, m, p, ref);
			return mul(mul(modexp(a, n / m, m), b, m), c, m);
		}

		pair<LL, LL> modFact(const LL& n, const LL& p, const vector<LL>& ref) {
			if (n == 0) return make_pair(1, 0);
			const pair<LL, LL> &tmp = modFact(n / p, p, ref);
			const LL &a = tmp.first;
			LL e = tmp.second;
			e += (n / p);
			if((n / p) % 2 == 0)
				return make_pair(mul(a, ref[n % p], p), e);
			else
				return make_pair(mul(a , p - ref[n % p], p), e);
		}
		
		LL getCombinations(const LL &n, const LL &r, const LL &m, const pair<LL, LL> &ref, const vector<LL> &refFact, const vector<LL> &refTemp) {
			const LL &p = ref.first;
			const LL &a = ref.second;
			LL b = a;
			while (b > 0){
				const pair<LL, LL> &xx = modFact(n, p, refTemp);
				const pair<LL, LL> &yy = modFact(r, p, refTemp);
				const pair<LL, LL> &zz = modFact(n - r, p, refTemp);
				const LL &pp = xx.second;
				const LL &qq = yy.second;
				const LL &rr = zz.second;
				if (pp >= qq + rr + a) return 0;
				if (pp >= qq + rr + b) break;
				b -= 1;
			}
			const LL &dd = factNfact(n, m, p, refFact);
			const LL &ee = factNfact(r, m, p ,refFact);
			const LL &gg = factNfact(n - r, m, p, refFact);
			const LL &ans = mul(inverseMod(ee, m) + m, inverseMod(gg, m) + m, m);
			return  mul(ans, mul(exponent(p, b), dd, m), m);
		}

		vector<LL> factorMod(const LL &a){
			vector<LL> ret(a, 1);
			ret.push_back(1);
			for(LL i = 1; i < a; i++){
				if(__gcd(i, a) == 1){
					ret[i] = mul(ret[i-1], i, a);
				}
				else ret[i] = ret[i-1];
			}
			return ret;
		}		
		
		void factorize(int m){
		   int prev = pfactor[m], cnt = 0;
			while(m > 1){
				m /= pfactor[m];
				cnt += 1;
				if(pfactor[m] != prev){
					prime_rep.push_back(make_pair(prev, cnt));
					prime_powers.push_back(factorMod(exponent(prev, cnt)));
					prime_factors.push_back(factorMod(prev));
					prev = pfactor[m];
					cnt = 0;
				}
			}
		}
		
		LL add(const LL &a, const LL &b, const LL &mod){
			LL x = a + b;
			return (x >= mod) ? (x - mod) : x;
		}
		
		LL sub(const LL &a, const LL &b, const LL &mod){
			LL x = a - b;
			return (x < 0) ? (x + mod) : x;
		}
		
		LL mul(const LL &a, const  LL &b, const LL &mod){
			LL x = (a * b);
			return (x >= mod) ? (x % mod) : x;
		}
		
		LL modexp(LL a, LL b, const LL &mod){
			if(b < 0) return 0;
			LL x = 1;
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
		
		LL exponent(LL a, LL b){
			if(b < 0) return 0;
			LL x = 1;
			while(b > 0){
				if(b & 1){
					x *= a;
				}
				b >>= 1;
				a  *= a;
			}
			return x;
		}
		
		void factorizeMod(const LL &mod){
			prime_rep.clear();
			prime_powers.clear();
			prime_powers.clear();
			factorize(mod);
		}

	public:
		
		LL combinations(const LL &a, const LL& b, const LL& mod){
			assert(a > 0 && b > 0 && mod > 1 && mod < R && a >= b);

			factorizeMod(mod);
			const int &n = (int)prime_rep.size();
			vector<LL> x(n), y(n);
			
			for(int i = 0; i < n; i++){
				x[i] = exponent(prime_rep[i].first, prime_rep[i].second);
				y[i] = getCombinations(a, b, x[i], prime_rep[i], prime_powers[i], prime_factors[i]);
			}
			
			return add(chinese_remainder(x, y).first, mod, mod);
		}

		vector<LL> sieve(){
			pfactor.resize(R, 0);
			for(register int i = 2; i * i <= R; ++i){
				if(!pfactor[i]){
					for(register int j = i << 1; j < R; j += i){
						if(!pfactor[j]){
							pfactor[j] = i;
						}
					}
				}
			}
			
			pfactor[2] = 2;
			for(register int i = 3; i < R; i += 2){
				if(!pfactor[i]){
					pfactor[i] = i;
				}
			}
			
			return pfactor;
		}
};



int main(){
	CRT obj;
	obj.sieve();
	
	int t;
	cin >> t;
	LL a, b, mod;
	while(t--){
		cin >> a >> b >> mod;
		cout << obj.combinations(a, b, mod) << endl;
	}
	return 0;
}
	
