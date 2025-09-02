// Swap 2 number without taking 3rd variable 
// using Xor operator we can do it
// (a^b)^b  = a 
#include<bits/stdc++.h>
using namespace std;
int countSetBit(int n){
        int cnt = 0;
        while(n>1){
            // if(n%2 == 1) cnt +=1;
            cnt += n&1;
            // n =  n/2;
            n= n >> 1;
        }
        if(n==1) cnt +=1;
        return cnt;
    }
    int countSetBit2(int n){
        int cnt = 0;
        while(n != 0){
            n = n&(n-1);
            cnt++;
        }
        return cnt;
    }
    //tc-0(no of set bit)
int main(){
    int a,b;
    cin>>a>>b;
    a = a^b;
    b = a^b;  // (a^b)^b = a 
    a = a^b;  //(a^b)^b = b here b is a 
    cout<<a<<" "<<b<<endl;

    //Q2 check if the ith bit is set or not if 1 then set else not
    // just left shift 1 for ith bit then & it with n 
    // or right shift n by ith place and then & with 1 
    //  if((n>>i) & 1 == 0) then not a set 


    // Q3 Set the ith Bit of n  it means make it 1
    // take 1 and then left shift to ith bit then do or operation with it ==>  N|(1<<i)


    //Q4 Clear the ith bit it mean make it 0 
    //take 1 and then shift to ith bit then perform not operation then & it with n 
    // n & (~(1<<2))

    //Q5 Toggle the ith bit 
    // 1->0 or 0->1
    // take 1 and then left shift to ith bit then perform Xor operation with n ==> n ^(1<<i)


    //Q6 Remove the last set bit (rightMOst)
    // 1010 -> 1000 or 1000->0000 or 1001 ->1000
    // just and(&)  the number n with n-1
    
    //Q7 Check if the number is a power of 2 or not 
    // if 1 setbit then it power of 2 
    // if(N&N-1 == 0) then it is power of 2 


    //Q8 Count the number of Set bits
    int n;
    cin>>n; 
    cout<<countSetBit(n);
}