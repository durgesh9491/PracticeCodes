#include <bits/stdc++.h>
using namespace std;

map<int, char> Map;

int main(){
	Map[10] = 'a';
	Map[11] = 'b';
	Map[12] = 'c';
	Map[13] = 'd';
	Map[14] = 'e';
	Map[15] = 'f';
	int t;
	cin >> t;
	while(t--){
		string inp;
		cin >> inp;
		int n = (int)inp.length();
		if(n % 4 != 0){
			int add = 4 - (n%4);
			n += add;
			while(add > 0){
				inp = '0' + inp;
				--add;
			}
		}
		string hex = "";
		for(int i = 0; i < n; i += 4){
			int j = 0, p = 8, num = 0;
			while(i + j < n && j < 4){
				num += (inp[i + j] - '0')*p;
				p /= 2;
				j += 1;
			}
			if(num > 9) hex += Map[num];
			else hex += char(num + '0');
		}
		cout<<hex<<endl;
	}
			
	return 0; 
	
}
