#include<bits/stdc++.h>
using namespace std;

#define LL        long long
#define pb        push_back
#define mp        make_pair
#define sz(_)     (int(_.size()))
#define len(_)    (int(_.length()))


const int MX = 100005;

string intToRoman(int num) {
	int a[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
	string b[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	string ans="";
	for(int i=12;i>=0;i--){
		while(num>=a[i]){
			num-=a[i];
			ans+=b[i];
		} 
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<intToRoman(n)<<endl;
    }
	return 0;
}

