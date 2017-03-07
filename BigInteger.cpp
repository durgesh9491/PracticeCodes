#include <bits/stdc++.h>
using namespace std;

#define pb                        push_back
#define mp                        make_pair
#define ff                        first
#define ss                        second
#define rep(i,a,b)                for(int i=(a);i<=(b);++i)
#define rer(i,b,a)                for(int i=(b);i>=(a);--i)
#define clr(x,_)                  memset(x,_,sizeof(x))
#define feach(c,_)                for(__typeof((c).begin()) _=(c).begin();_!=(c).end();++_)
#define all(_)                    _.begin(),_.end()
#define sz(_)                     (int(_.size()))
#define len(_)                    (int(_.length()))
#define LB(_,x)                   (lower_bound(all(_),x)-(_.begin()))
#define UB(_,x)                   (upper_bound(all(_),x)-(_.begin()))
#define sq(x)                     ((x)*(x))
#define dist(x1,y1,x2,y2)         (sqrt(sq(x1-x2)+sq(y1-y2)))
#define area(x1,y1,x2,y2,x3,y3)   (abs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))))
#define PI                        acos(-1.0)
#define cnt_1                      __builtin_popcountll
#define lg(x)                     (63-__builtin_clzll(x))
#define dig(x)                    (int(log10(double(x)))+1)
#define T()                       int _;cin>>_;while(_--)
#define gc                        getchar//_unlocked

//traces
#define dg1(x)                cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<endl;
#define dg2(x,y)              cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<" | "#y" = "<<y<<endl;
#define dg3(x,y,z)            cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
#define dg4(a,b,c,d)          cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<endl;
#define dg5(a,b,c,d,e)        cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<endl;
#define dg6(a,b,c,d,e,f)      cerr<<__FUNCTION__<<" : "<<__LINE__<<" : "#a" = "<<a<<" | "#b" = "<<b<<" | "#c" = "<<c<<" | "#d" = "<<d<<" | "#e" = "<<e<<" | "#f" = "<<f<<endl;

typedef long long int LL;     typedef pair<int,int> PII;       typedef vector<int> VI;          typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;      typedef vector<LL> VLL;          typedef vector<PLL> VPLL;        typedef vector<VPII> VVPII;

//utility functions
#define RG                   1
bool markP[RG];VI prime;
inline void sieve(){int i,j;for(i=2;i*i<=RG;++i)if(!markP[i])for(j=i<<1;j<RG;j+=i)if(!markP[j])markP[j]=1;prime.pb(2);for(i=3;i<RG;i+=2)if(!markP[i])prime.pb(i);}
inline void inp(int &x){register int c=gc();x=0;bool neg=0;for(;((c<48||c>57)&&c!='-');c=gc());if(c=='-'){neg=1;c=gc();}for(;c>47&&c<58;c=gc()){x=(x*10)+(c-48);}if(neg)x=-x;}
inline void inpl(LL &x){register LL c=gc();x=0;bool neg=0;for(;((c<48||c>57)&&c!='-');c=gc());if(c=='-'){neg=1;c=gc();}for(;c>47&&c<58;c=gc()){x=(x*10)+(c-48);}if(neg)x=-x;}
inline LL modexp(LL a,LL b,const LL &mod){LL x=1;a%=mod;while(b>0){if(b&1){x*=a;if(x>=mod)x%=mod;};b>>=1;a*=a;if(a>=mod)a%=mod;}return x;}
inline LL mulmod(LL a,LL b,const LL &mod){LL x=0;a%=mod;while(b>0){if(b&1){x+=a;if(x>=mod)x-=mod;}a<<=1;if(a>=mod)a-=mod;b>>=1;}return x;}
inline LL toNum(const string &st){LL num;stringstream ss(st);ss>>num;return num;}
inline LL strmod(const string &T,const LL &mod){LL mul=0;rep(i,0,len(T)-1){mul=(mul*10+T[i]-'0');if(mul>=mod)mul%=mod;}return mul;}
inline LL fib(LL n,const int &mod){LL i,j,h,k,t;i=h=1;j=k=0;while(n>0){if(n&1){t=j*h%mod;j=(i*h+j*k+t)%mod;i=(i*k+t)%mod;}t=h*h%mod;h=(2*k*h+t)%mod;k=(k*k+t)%mod;n>>=1;}return j;}
inline LL comb(const LL &N,LL R,const LL &mod){if(R>N) return 0;R>(N-R)?(R=N-R):R;LL mul=1LL;rep(i,0,R-1) mul=((mul*(N-i))%mod*modexp(i+1,mod-2,mod))%mod;return mul;}
inline bool cmp(const PII &X,const PII &Y) {return (X.ff!=Y.ff)?(X.ff<Y.ff):(X.ss<Y.ss);}

#define MOD                  1000000007
#define MX                   200007
#define base                 1000000000
#define base_digits          9

struct BigInt 
{
	VI a;
	int sign;
	BigInt():sign(1){}
	BigInt(LL v){*this=v;}
	BigInt(const string &s){read(s);}
	
	void operator=(const BigInt &v){sign=v.sign;a=v.a;}
	void operator=(LL v){
		sign=1;
		if(v<0) sign=-1,v=-v;
		while(v>0){
			a.pb(v%base);
			v/=base;
		}
	}
	
	BigInt operator+(const BigInt &v) const{
		if(sign==v.sign){
			BigInt res(v);
			for(register int i=0,carry=0;i<max(sz(a),sz(v.a)) || carry;++i){
				if(i==sz(res.a))
				res.a.pb(0);
				res.a[i]+=carry+(i<sz(a)?a[i]:0);
				carry=(res.a[i]>=base);
				if(carry) res.a[i]-=base;
	     	}
		    return res;
		}
		return *this-(-v);
	}
	
	BigInt operator-(const BigInt &v) const{
		if (sign==v.sign){
			if (abs()>=v.abs()){
				BigInt res(*this);
				for (register int i=0,carry=0;i<sz(v.a) || carry;++i){
					res.a[i]-=carry+(i<sz(v.a)?v.a[i]:0);
					carry=res.a[i]<0;
					if(carry) res.a[i]+=base;
				}
				res.trim();
				return res;
			}
		    return -(v-*this);
		}
		return *this+(-v);
	}
	
	void operator*=(int v){
		if (v<0) sign=-sign,v=-v;
		for(register int i=0,carry=0;i<sz(a) || carry;++i){
			if(i==sz(a)) a.push_back(0);
			LL cur=a[i]*(LL)v+carry;
			carry=int(cur/base);
			a[i]=int(cur%base);
		}
		trim();
	}
	
	BigInt operator*(int &v) const{
	    BigInt res(*this);
	    res*=v;
	    return res;
	}
	
    BigInt operator/(int &v) const{
	    BigInt res(*this);
	    res/=v;
	    return res;
    }
    
    void operator/=(int v){
	    if(v<0) sign=-sign,v=-v;
	    for(register int i=sz(a)-1,rem=0;i>=0;--i){
	        LL cur=a[i]+rem*(LL)base;
	        a[i]=int(cur/v);
	        rem=int(cur%v);
	    }
        trim();
    }
    
    int operator%(int v) const{
	    if(v<0)v=-v;
	    LL m=0;
	    for(register int i=sz(a)-1;i>=0;--i){
            m=(a[i]+ m*base);
            if(m>=v) m%=v;
        }
        return m*sign;
    }
    
    bool operator<(const BigInt &v) const{
	    if(sign!=v.sign) return sign<v.sign;
	    if(sz(a)!=sz(v.a)) return sz(a)*sign < sz(v.a)*v.sign;
	    for(register int i=sz(a)-1;i>=0;--i){
	        if(a[i]!=v.a[i])
			return a[i]*sign < v.a[i]*sign;
		}
    return false;
    }

    void trim(){
        while(!a.empty() && !a.back()) a.pop_back();
        if(a.empty()) sign=1;
    }
    
    BigInt operator-() const{
        BigInt res(*this);
        res.sign=-sign;
        return res;
    }
 
    BigInt abs() const{
        BigInt res(*this);
        res.sign*=res.sign;
        return res;
    }
 
    LL longValue() const{
    	LL res=0;
        for (register int i=sz(a)-1;i>=0;--i)
            res=res*base+a[i];
        return res*sign;
    }
 
    friend BigInt GCD(const BigInt &a, const BigInt &b){return b.isZero()?a : GCD(b,a%b);}
    friend BigInt LCM(const BigInt &a, const BigInt &b){return a/GCD(a,b)*b;}
    BigInt operator/(const BigInt &v) const{return divmod(*this,v).first;}
	BigInt operator%(const BigInt &v) const{return divmod(*this, v).second;}
    void operator+=(const BigInt &v) {*this = *this + v;}
    void operator-=(const BigInt &v) {*this = *this - v;}
    void operator*=(const BigInt &v) {*this = *this * v;}
    void operator/=(const BigInt &v) {*this = *this / v;}
    bool operator>(const BigInt &v) const{return v < *this;}
    bool operator<=(const BigInt &v) const{return !(v < *this);}
    bool operator>=(const BigInt &v) const{return !(*this < v);}
    bool operator==(const BigInt &v) const{return !(*this < v) && !(v < *this);}
    bool operator!=(const BigInt &v) const{return *this < v || v < *this;}
    bool isZero() const{return a.empty() || (sz(a)==1 && !a[0]);}
	
	friend pair<BigInt, BigInt> divmod(const BigInt &a1, const BigInt &b1){
        int norm=base/(b1.a.back()+1);
        BigInt a(a1.abs()*norm);
        BigInt b(b1.abs()*norm);
        BigInt q,r;
        q.a.resize(a.a.size()); 
        for (register int i=a.a.size()-1;i>=0;--i){
            r*=base;
            r+=a.a[i];
            int s1=r.a.size()<=b.a.size() ? 0 : r.a[b.a.size()];
            int s2=r.a.size()<=b.a.size()-1 ? 0 : r.a[b.a.size()-1];
            int d=((LL)base*s1+s2)/b.a.back();
            r-=b*d;
            while(r<0) r+=b,--d;
            q.a[i]=d;
        }
        q.sign=a1.sign * b1.sign;
        r.sign=a1.sign;
        q.trim();
        r.trim();
        return mp(q,r/norm);
    }
    
    friend istream& operator>>(istream &stream, BigInt &v){
	    string s;
	    stream>>s;
	    v.read(s);
	    return stream;
    }
    friend ostream& operator<<(ostream &stream, const BigInt &v){
        if(v.sign==-1) stream<<'-';
        stream<<(v.a.empty()? 0:v.a.back());
        for(register int i=sz(v.a)-2;i>=0;--i)
            stream<<setw(base_digits)<<setfill('0')<<v.a[i];
        return stream;
    }
 
    void read(const string &s){
        sign=1;
        a.clear();
        int pos=0;
        while (pos<sz(s) && (s[pos]=='-' || s[pos]=='+')){
            if(s[pos]=='-') sign=-sign;
            ++pos;
        }
        for (register int i=sz(s)-1;i>=pos;i-=base_digits){
            int x=0;
            for(register int j=max(pos,i-base_digits+1);j<=i;++j)
                x=x*10+s[j]-48;
            a.push_back(x);
        }
        trim();
    }
 
    VI convert_base(const VI &a,const int &old_digits,const int &new_digits) const{
        VLL p(max(old_digits,new_digits)+1);
        p[0]=1;
        for(register int i=1;i<sz(p);++i)
            p[i]=p[i-1]*10;
        vector<int> res;
        LL cur=0;
        int cur_digits=0;
        for(register int i=0;i<sz(a);++i){
            cur+=a[i]*p[cur_digits];
            cur_digits+=old_digits;
            while(cur_digits>=new_digits){
                res.push_back(int(cur%p[new_digits]));
                cur/=p[new_digits];
                cur_digits-=new_digits;
            }
        }
        res.push_back((int)cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }
 
    VLL karatsubaMultiply(const VLL &a, const VLL &b) const{
        int n=sz(a);
        VLL res(n+n);
        if (n<=32){
            for(register int i=0;i<n;++i)
                for(register int j=0;j<n;++j)
                    res[i+j]+=a[i]*b[j];
            return res;
        }
        int k=n>>1;
        VLL a1(a.begin(),a.begin()+k);
        VLL a2(a.begin()+k,a.end());
        VLL b1(b.begin(),b.begin()+k);
        VLL b2(b.begin()+k,b.end());
        VLL a1b1=karatsubaMultiply(a1,b1);
        VLL a2b2=karatsubaMultiply(a2,b2);
        for(register int i=0;i<k;++i) a2[i] += a1[i];
        for(register int i=0;i<k;++i) b2[i] += b1[i];
        VLL r=karatsubaMultiply(a2,b2);
        for(register int i=0;i<(int)a1b1.size();++i) r[i]-=a1b1[i];
        for(register int i=0;i<(int)a2b2.size();++i) r[i]-=a2b2[i];
        for(register int i=0;i<(int)r.size();   ++i) res[i+k]+=r[i];
        for(register int i=0;i<(int)a1b1.size();++i) res[i]+=a1b1[i]; 
        for(register int i=0;i<(int)a2b2.size();++i) res[i+n]+=a2b2[i];
        return res;
    }
 
    BigInt operator*(const BigInt &v) const{
        VI a6=convert_base(this->a,base_digits,6);
        VI b6=convert_base(v.a,base_digits,6);
        VLL a(all(a6));
        VLL b(all(b6));
        while (sz(a)<sz(b)) a.push_back(0);
        while (sz(b)<sz(a)) b.push_back(0);
        while (sz(a) & (sz(a)- 1)) a.push_back(0), b.push_back(0);
        VLL c=karatsubaMultiply(a,b);
        BigInt res;res.sign=sign*v.sign;
        for(register int i=0,carry=0;i<sz(c);++i){
            LL cur=c[i]+carry;
            res.a.push_back(int(cur%1000000));
            carry=int(cur/1000000);
        }
        res.a=convert_base(res.a,6,base_digits);
        res.trim();
        return res;
    }
    
    int sumDig(){
	    int s=0,temp;
		for(int i=0;i<sz(a);++i){
			temp=a[i];
			while(temp>0){
				s+=temp%10;
				temp/=10;
			}
		}
		return s;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
	//freopen("inp.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	BigInt a,b,ans(1);
	while(1){
		cin>>a>>b;
		for(BigInt i=0;i<b;i = i+1){
			ans *= a;
		}
		cout<<ans<<endl;
	}
	return 0;
}

