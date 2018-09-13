/*
 * Complete the function below.
 */

#include<bits/stdc++.h>
using namespace std;


/*
 * Complete the function below.
 */
int findMatchingPair(string input) {
    int l = (int)input.length();
    int i = 0;
    stack<char> st;
    int ans = -1;
    while(i < l)
    {
        if(i==0 && !isupper(input[i]))
        {
            ans = -1;
            break;
        }
        if(st.empty())
        {
            st.push(input[i]);
        }
        else
        {
            if(isupper(input[i]))
            {
                st.push(input[i]);
            }
            else
            {
                if(char(toupper(input[i])) == st.top())
                {
                    st.pop();
                    ans = i;
                }
                else
                {
                    break;
                }
            }
            
        }
        i++;          
    }
    return ans;
}


// Complete the findMinGates function below.
int findMinGates(vector<int> arrivals, vector<int> departures, int flights) {
    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());
    int ans = 0, j = 0, mx = 0;
    for(int i = 0; i < (int)arrivals.size(); i++){
        while(arrivals[i] <= departures[j] && i < flights)
        {
            ans++;
            i++;
        }
        i--;
        j++;
        mx = max(ans, mx);
        ans--;
    }
    return mx;
}



int main(){
	string s;
	while(cin >> s){
		cout << findMatchingPair(s) << endl;
	}
}

