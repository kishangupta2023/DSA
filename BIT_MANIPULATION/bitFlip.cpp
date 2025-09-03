// Minimum bit flips to convert aa number 
// start = 10 to goal = 7
// 1010 -> 0111

// first Xor it then count number of set bit
// if(ans &(1<< i)) cnt++ 
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int ans=0;
    ans = a^b;
    int cnt = 0;
    for(int i=0;i<32;i++){
        if(ans & (1<<i)){
            cnt++;
        }
    }
    // just count 1 in the ans by dividing by 2 
    cout<<cnt<<endl;
    // tc->0(31)
}