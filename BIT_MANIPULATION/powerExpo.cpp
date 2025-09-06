// Power Exponentiation 
#include<bits/stdc++.h>
using namespace std;

    int fun(int x,int n){
        int ans =1;
        int m =n;
        while(n>0){
            if(n%2 == 1){
                ans *=x;
                n = n-1;
            }
            else {
                n = n/2;
                x =x*x;
            }
        }
        if(m < 0) return 1/ans;
        return ans;
    }
    //tc -> o(logn) base 2 

int main(){
    int answer = fun(2,3);
    cout<<answer;
}