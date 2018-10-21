#include<bits/stdc++.h>
using namespace std;

#define LL    long long

class MOD{
	private: 
		LL mod;
		bool isPrime;
		const static LL INF = 2e18;
		
	public:
		MOD(){
			mod = 1e9 + 7;
			isPrime = true;
		}
		MOD(LL &ref, LL &refPrime){
			mod = ref;
			isPrime = refPrime;
		}
		LL add(const LL &a, const LL &b){
			LL x = a + b;
			return (x >= mod) ? (x-mod) : x;
		}
		LL sub(const LL &a, const LL &b){
			int x = a - b;
			return (x < 0) ? (x  + mod) : x;
		}
		LL mul(const LL &a, const  LL &b){
			LL x = (a * b);
			return (x >= mod) ? (x % mod) : x;
		}
		
		LL modexp(LL a,LL b){
			LL x = 1; a = add(a, 0);
			while(b > 0){
				if(b & 1)
					x = mul(x, a);
				a = mul(a, a);
			    b >>= 1;
			}
			return x;
	    }
	    
		LL mulmod(LL a,LL b){
			LL x = 0; a = add(a, 0); 
			while(b > 0){
				if(b&1)
					x = add(x, a);
				a = add(a, a);
				b >>= 1;
			}
			return x;
		}
		
		/*
		 * Suppose that (a/b) mod p = r. Then, a/b = mp+r, i.e., a=bmp+br.
		 * Thus, a mod (bp) = br mod (bp). Since r<p, i.e., br<bp, we have a mod (bp) = br.\
		 * Therefore, (a mod (bp))/b = br /b = r.
		 * Provided b * p < INF
		 */
		LL div(LL &a, LL &b){
			return (b < INF/mod) ? ((a % mul(b, mod)) / b) : mul(a, modexp(b, mod - 2));
		}
};




int main(){
	return 0;
}
