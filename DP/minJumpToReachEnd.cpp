#include <bits/stdc++.h>
using namespace std;
 
// Returns minimum number of jumps to reach arr[h] from arr[l]

#define MAX 109

int dp[MAX],arr[MAX];
int minJumps(int arr[], int l, int h)
{
   // Base case: when source and destination are same
   if (h == l)
     return dp[h]=0;
 
   // When nothing is reachable from the given source
   if (arr[l] == 0)
     return dp[l]=INT_MAX;
 
   // Traverse through all the points reachable from arr[l]. Recursively
   // get the minimum number of jumps needed to reach arr[h] from these
   // reachable points.
   int min = INT_MAX;
   for (int i = l+1; i <= h && i <= l + arr[l]; i++)
   {
	   int & t = dp[i];
	   if(t!=INT_MAX) return dp[i];
       t= minJumps(arr, i, h);
       if(t != INT_MAX && t + 1 < min)
           min = t + 1;
   }
 
   return min;
}
 
// Driver program to test above function
int main()
{
    int n,t;
    cin>>t;
    while(t--){
		for(int i=0;i<MAX;i++) dp[i]=INT_MAX;
		cin>>n;
		for(int i=0;i<n;i++) cin>>arr[i];
	    cout<<minJumps(arr, 0, n-1)<<endl;
	}
  return 0;
}

