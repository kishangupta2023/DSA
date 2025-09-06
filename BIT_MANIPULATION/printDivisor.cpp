// Print all divisor of a number 
#include<bits/stdc++.h>
using namespace std;

class Solution{
    vector<int> printArr(int n){
        vector<int>arr;
        for(int i=1;i*i<=n;i++){
            if(n%i == 0){
                arr.push_back(i);
                if(n/i != i){
                    arr.push_back(n/i);
                }
            }
        }
        return arr;
    }
    //tc-0(sqrt(n))
};