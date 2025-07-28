// Findnig fibbonacci number using DP 
#include<bits/stdc++.h>
using namespace std;

//Memoization solution
int f(int n,vector<int> &dp){
    if(n<=1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = f(n-1,dp) + f(n-2,dp);
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    // cout<<"Fibbonaci of number is :"<<f(n,dp)<<endl;
    
    // Tabular Solution
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    // tc & sc- 0(N)

    // cout<<dp[n]<<endl;


    // more optimise way
    //tc-0(N) 
    int prev2 = 0;
    int prev = 1;
    for(int i=2;i<=n;i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    cout<<prev<<endl;
    return 0;
}

//tc -0(N)
//sc -0(N)+0(N)(for array space)