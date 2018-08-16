#include<bits/stdc++.h>
using namespace std;
int main() {
		int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n,k=0,k1=0,p,q,i;
	    scanf("%d",&n);
	    char a[n][1000];
	    for(i=0;i<n;i++)
	    scanf("%s",a[i]);
	    char s1[1000],s2[1000];
	    scanf("%s %s",s1,s2);
	    for(i=0;i<n;i++)
	    {
	        if(strcmp(a[i],s1)==0)
	        {
	            p=i;
	            k=1;
	        }
	        if(strcmp(a[i],s2)==0)
	        {
	            q=i;
	            k1=1;
	        }
	        if(k==1&&k1==1)
	        break;
	    }
	    printf("%d\n",abs(p-q));
	}
	return 0;
}
