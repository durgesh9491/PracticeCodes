class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> v;
        for(int i=1;i<=n;i++){
            if(i%3==0 && i%5==0){
                v.push_back("FizzBuzz");
                continue;
            }
            if(i%3==0){
                v.push_back("Fizz");
                continue;
            }
            if(i%5==0) v.push_back("Buzz");
            else{
                int tmp = i;
                string p="";
                while(tmp>0){
                    p+= (tmp%10)+'0';
                    tmp/=10;
                }
                reverse(p.begin(), p.end());
                v.push_back(p);
            }
            
        }
        return v;
    }
};
