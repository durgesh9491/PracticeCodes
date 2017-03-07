#include<bits/stdc++.h>
using namespace std;
/* Head ends here */

int stringReduction(char a[]) {
   int l= strlen(a);
    stack<char> st;
   for(int i=0;i<l;i++){
       if(st.empty() || st.top()==a[i]){
          st.push(a[i]); 
       }
       else{
               char tp = st.top();
               if(tp!=a[i]){
                   st.pop();
                   if(tp=='a' && a[i]=='b')
                       st.push('c');
                   else if(tp=='b' && a[i]=='a')
                       st.push('c');     
                   else if(tp=='a' && a[i]=='c')
                       st.push('b');
                   else if(tp=='c' && a[i]=='a')
                       st.push('b');
                   else if(tp=='b' && a[i]=='c')
                       st.push('a');
                   else if(tp=='c' && a[i]=='b')
                       st.push('a');
                }
           
           
                tp=st.top();
                st.pop();
                    while(!st.empty() && tp!=st.top()){
                        char tp1 = st.top();
                        st.pop();
                       if(tp=='a' && tp1=='b')
                           st.push('c');
                       else if(tp=='b' && tp1=='a')
                           st.push('c');     
                       else if(tp=='a' && tp1=='c')
                           st.push('b');
                       else if(tp=='c' && tp1=='a')
                           st.push('b');
                       else if(tp=='b' && tp1=='c')
                           st.push('a');
                       else if(tp=='c' && tp1=='b')
                           st.push('a');
                       tp= st.top();
                       st.pop();
                    }
                st.push(tp);   
       }
   }
   return (int)st.size();
}

void reverse(char *a){
	int l =strlen(a),i=0;
	while(i<l/2){
		swap(a[i],a[l-i-1]);
		i++;
	}
}

int main() {	
	//freopen("out.txt","w",stdout);
    int res1,res2, t, i;
    scanf("%d",&t);
    char a[1000000];
    for (i=0;i<t;i++) {
        scanf("%s",a);
        res1=stringReduction(a);
        reverse(a);
        res2=stringReduction(a);
        cout<<res1<<" "<<res2<<endl;
        printf("%d\n",min(res1,res2));  
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
