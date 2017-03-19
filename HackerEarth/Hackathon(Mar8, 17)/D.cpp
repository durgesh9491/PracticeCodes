#include<stdio.h>
main(int n,int k){ long long x,ans, s[100005];for(int i=0;i<n;i++) scanf("%d",&x),s[x%k]++;for(int i=0;i<k;i++) ans+=s[i]*(s[i]-1);printf("%d",ans);
}
