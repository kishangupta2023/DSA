// check if a number is prime or not 
// a number is divisible by 1 & itself and total no of divisors = 2 
// as 1 is not prime number 

#include<bits/stdc++.h>
using namespace std;

bool prime(int n){
    int cnt =0;
    for(int i=1;i<=n;i++){
        if(n%i == 0){
            cnt++;
        }
    }
    if(cnt == 2) return true;
    else return false;
    // tc-> 0(N)
    // sc-0(1)
}bool prime(int n){
    int cnt =0;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            cnt++; 
        if(n/i != i){
            cnt = cnt+1;
        }
    }
    }
    if(cnt == 2) return true;
    else return false;
}
// tc-0(sqrt(n))
//sc-0(1)
int main(){
    int n;
    cin>>n;
    if(prime(n)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}