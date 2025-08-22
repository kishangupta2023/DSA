// BUy and Sell Stock -II | Recursion to space optimzation 
// you can buy and sell as many time as u want but after buying first need to sell then u can buy again 
#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Recusrive Solution
    long f(int ind,int buy,long *values,int n){
        if(ind == n) return 0;

        long profit = 0;
        if(buy){
            profit = max(-values[ind]+f(ind+1,0,values,n),0 + f(ind+1,1,values,n));
        }
        else{
            profit = max(values[ind]+f(ind+1,1,values,n),0+f(ind+1,0,values,n));
        }
        return profit;
    } 

    // tc-> 2powern
    // sc->0(N)

    //Memoization Solution
    long f(int ind,int buy,long *values,int n,vector<vector<long>>dp){
        if(ind == n) return 0;

        if(dp[ind][buy] != -1) return dp[ind][buy];

        long profit = 0;
        if(buy){
            profit = max(-values[ind]+f(ind+1,0,values,n,dp),0 + f(ind+1,1,values,n,dp));
        }
        else{
            profit = max(values[ind]+f(ind+1,1,values,n,dp),0+f(ind+1,0,values,n,dp));
        }
        return dp[ind][buy] = profit;
    }  
    //tc->2*N
    //sc->2*N + 0(N)

    long getMaximumProfit(long *values,int n){
        vector<vector<long>>dp(n,vector<long>(2,-1));
        return f(0,1,values,n,dp);
        }

    //Tabulation Solution 
    long getMaximumProfit(long *values,int n){
        vector<vector<long>>dp(n+1,vector<long>(2,0));
        dp[n][0] = dp[n][1] = 0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy =0;buy<2;buy++){
                long profit = 0;
                if(buy){
                    profit = max(-values[ind]+dp[ind+1][0],0 + dp[ind+1][1]);
                }
                else{
                    profit = max(values[ind]+dp[ind+1][1],0+dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][1];
    }

    //space optimzation 
    long getMaximumProfit(long *values,int n){
        vector<long>prev(2,0),cur(2,0);
        prev[0] =prev[1] = 0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy =0;buy<2;buy++){
                long profit = 0;
                if(buy){
                    profit = max(-values[ind]+prev[0],0 + prev[1]);
                }
                else{
                    profit = max(values[ind]+prev[1],0+prev[0]);
                }
                cur[buy] = profit;
            }
            prev = cur;
        }
        return prev[1];
    }

    // space optimzation with some variable
    long getMaximumProfit(long *values,int n){
        long curBuy,curNotBuy;
        long aheadNotBuy=0;
        long aheadBuy = 0;
        for(int ind=n-1;ind>=0;ind--){
             curNotBuy = max(values[ind]+aheadBuy,0+aheadNotBuy);
             curBuy = max(-values[ind]+aheadNotBuy,0 + aheadBuy);  
            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;
    }
};