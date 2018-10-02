#include<bits/stdc++.h>
using namespace std;


string reverseIndividualWords(string s){
	int l = (int)s.length();
	for(int i = 0; i < l; i++){
		int j = i;
		while(j < l && s[j] != '.'){
			j += 1;
		}
		if(j != i){
			reverse(s.begin() + i, s.end() - (l -j));
			i = j - 1;
		}
	} 
	return s;
}


int main(){
	int t;
    string s;
	cin >> t;
	getline(cin, s);
	while(t--){
		getline(cin, s);
	    string ret = reverseIndividualWords(s);
		reverse(ret.begin(), ret.end());
		cout << ret << endl;
	}
}



/*
 * Input : 1 i.like.this.program.very.much
 * Output: much.very.program.this.like.i
 */
