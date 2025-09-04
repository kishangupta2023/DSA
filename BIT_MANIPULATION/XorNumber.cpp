// Xor of Numbers in a given Range 
// given an integer n,find the Xor of all numbers from 1 to n .
// 1^2^3^4 = 4

// we can do it by forloop 
// for(int i =1;i<=n;i++) ans = ans^i;
// return ans;

// n=1 ->       1
// n=2 1^2      3
// n=3 1^2^3    0
// n=4 1^2^3^4  4

// n=5 1^2^3^4^5  1
// n=6 1^2^3^4^5^6 7 

// conclusion  n%4 = 0 ans =n
//  if n%4 =1 ans 1
// if n%4 =2  ans = n+1
// if n%4  = 3   ans = 0

#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    int f(int n){
      if(n%4 == 1) return 1;  
      else if(n%4 == 2) return n+1;  
      else if(n%4 == 3) return 0;  
      else return n;  
    }
    //tc-0(1)
    //sc-0(1)

    // for finding Xor from low to high 
    // take xor from 1 to high and 1 to low-1 then xor them together 
    //tc-(1)
    //sc-0(1)
    int f1(int l ,int r){
        return f(l-1)^f(r);
    }
};
