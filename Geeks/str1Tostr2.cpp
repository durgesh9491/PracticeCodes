#include <bits/stdc++.h>
using namespace std;

int TransformString(char *str1, char *str2){
	int res = -1;
	int p = strlen(str1);
	int q = strlen(str2);
	
	if(p != q) return res;
	int cnt[256];
	memset(cnt, 0, sizeof cnt);
	for(int i=0;i<p;i++){
		cnt[(int)str1[i]]++;
		cnt[(int)str2[i]]--;
	}
	for(int i=0;i<256;i++){
		if(cnt[i] != 0){
			return res;
		}
	}
	
	res = 0;
	int i = p-1, j = p-1;
	while(i>=0 && j>=0){
		while(i>=0 && str1[i] != str2[j]){
			--i;
			res += 1;
		}
		if(i>=0){
			i -= 1;
			j -= 1;
		}
	}
	return res;
}

const int M = 100005;
char s1[M], s2[M];
int main(){
	cin>>s1>>s2;
	cout<<TransformString(s1, s2)<<endl;
}
