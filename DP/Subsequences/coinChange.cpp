// Coin Change 2 | Infinite Supply Problems
// make everywhere long for dp 
#include<bits/stdc++.h>
using namespace std;
class Solution{
    // Recursive Solution
    long f(int ind,int T,int *a){
        if(ind == 0){
            return (T % a[0] == 0);
        }
        long notTake = 0 + f(ind-1,T,a);
        long take = 0;
        if(a[ind] <= T) take = 1+ f(ind,T-a[ind],a);
        return (take+notTake);
    }

    //Memoization solution 
    long f(int ind,int T,int *a,vector<vector<int>> &dp){
        if(ind == 0){
            return (T % a[0] == 0);
        }
        if(dp[ind][T] != -1) return dp[ind][T];
        long notTake = 0 + f(ind-1,T,a,dp);
        long take = 0;
        if(a[ind] <= T) take = 1+ f(ind,T-a[ind],a,dp);
        return dp[ind][T]=(take+notTake);
    }

    long countWaysToMakeChange(int *denominations,int n,int value){
        vector<vector<int>> dp(n,vector<int>(value+1,-1));
        return f(n-1,value,denominations,dp);
    }

    // Tabulation Solution 
    long countWaysToMakeChange(int *denominations,int n,int value){
        vector<vector<int>> dp(n,vector<int>(value+1,0));
        for(int T=0;T<value;T++){
            dp[0][T] =(T % denominations[0] == 0);
        }
        for(int ind =1;ind<n;ind++){
            for(int T=0;T<=value;T++){
                long notTake = 0 + dp[ind-1][T];
                long take = 0;
                if(denominations[ind] <= T) take = 1+ dp[ind][T-denominations[ind]];
                dp[ind][T]=(take+notTake);
            }
        }
        return dp[n-1][value];
    }

    //space optimization 
    long countWaysToMakeChange(int *denominations,int n,int value){
        vector<int>prev(value+1,0),cur(value+1,0);
        for(int T=0;T<value;T++){
           prev[T] =(T % denominations[0] == 0);
        }
        for(int ind =1;ind<n;ind++){
            for(int T=0;T<=value;T++){
                long notTake = 0 + prev[T];
                long take = 0;
                if(denominations[ind] <= T) take = 1+ cur[T-denominations[ind]];
                cur[T]=(take+notTake);
            }
            prev = cur;
        }
        return prev[value];
    }
};