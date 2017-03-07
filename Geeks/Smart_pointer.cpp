#include<iostream>
using namespace std;
 
class SmartPtr
{
   int *ptr;  // Actual pointer
public:
   // Constructor: Refer http://www.geeksforgeeks.org/g-fact-93/
   // for use of explicit keyword 
   SmartPtr(int *p = NULL) { ptr = p; } 
   // Destructor
   ~SmartPtr() { delete(ptr); }  
   // Overloading dereferencing operator
   int &operator *() {  return *ptr; }
};
 
int main(){
    SmartPtr ptr= SmartPtr(new int);
    *ptr = 20;
    cout << *ptr; 
    return 0;
}
