#include<bits/stdc++.h>
using namespace std;

#define LL        long long
#define pb        push_back
#define mp       make_pair

const int MX = 100005;


int main(){
	int t, k;
	cin>>t;
	string s;
	while(t--){
		cin>>s>>k;
		vector<int> cnt(26, 0);
		multiset<pair<int, char> > st;
		multiset<pair<int, char> > ::reverse_iterator it;
		for(int i=0;i<(int)s.length();i++) cnt[s[i]-'a']++;
		for(int i=0;i<26;i++) st.insert(mp(cnt[i], i));
		for(int i=0;i<k;i++){
			it = st.rbegin();
			int cnt = it->first;
			int ch = it->second;
			st.erase(st.find(mp(cnt, ch)));
			cnt--;
			st.insert(mp(cnt, ch));
		}
		LL ans = 0;
		for(it = st.rbegin();it != st.rend();it++){
			ans += (it->first)*(it->first);
		}
		cout<<ans<<endl;
		
    }
	return 0;
}
