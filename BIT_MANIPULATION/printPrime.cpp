// Print all the prime factors of a Number 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrime(int n){
        int cnt =0;
        for(int i=1;i*i <=n;i++){
            if(n % i == 0){
                cnt++;
                if(n/i != i){
                   cnt++;
                }
            }
        }
        if(cnt == 2) return true;
        else return false;
    }

    //optimized way 
    vector<int> countPrimes(int n) {
        vector<int>list;
        for(int i=1;i*i<=n;i++){
            if(n%i == 0){
                if(isPrime(i)){
                    list.push_back(i);
                }
                if(n/i != i){
                    if(isPrime(n/i)){
                        list.push_back(n/i);
                    }
                }
            }
        }
        return list;
    }

    // do it by school method by divide by 2 method
    vector<int> PrintPrime(int n){
        vector<int> list;
        for(int i=2;i*i<=n;i++){
            if(n%i == 0){
                list.push_back(i);
            
            while(n%i == 0){
                n = n/i;
            }
           }
        if(n != 1) list.push_back(n);
        }
    }
    //tc->0(root(n) + log(N))
    //sc-0(depend on number of factor)
    // for a large number that is prime tc- 0(n)
};