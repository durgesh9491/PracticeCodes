#include<bits/stdc++.h>
using namespace std;

class Exception{
	private: 
		string msg;
		
	public:
        Exception(const string& str) : msg(str) {}
		~Exception() {}
		
		string getMessage(){
			return msg;
		}
};

class Fraction{
	private:
		int num, den;
		
		int gcd(int a, int b){
			if(a == 0) return b;
			return gcd(b % a, a);
		}
		
	public:
		Fraction(){}
		Fraction(int a, int b):num(a), den(b) {}
		~Fraction(){}
		
		Fraction add(Fraction &obj){
			try{
				if(den == 0 || obj.den == 0){
					throw Exception("Denominator is Zero");
				}
				int gcf = gcd(den, obj.den);
				int new_den = (den * obj.den) / gcf;
				int new_num = (num * (new_den / den)) + (obj.num * (new_den / obj.den)); 
				Fraction new_obj(new_num, new_den);
				lowest(new_obj);
				return new_obj;
			}
			catch(Exception &e){
				cout << e.getMessage() << endl;
				return Fraction(0, 0);
			}
		}
		
		Fraction lowest(Fraction obj){
			int gcf = gcd(obj.num, obj.den);
			obj.num = obj.num / gcf;
			obj.den = obj.den / gcf;
			return obj;
		}
		
	    void print(Fraction &obj){
			cout << obj.num << " | " << obj.den << endl;
		}
};


int main(){
	Fraction p(2, 0), q(3, 250);
	Fraction s = p.add(q);
	s.print(s);
}
	
	
