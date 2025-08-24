// BUy and Sell Stock -II | Recursion to space optimzation 
// you can buy and sell at max 2 time as u want but after buying first need to sell then u can buy again 

#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Recusrive Solution
    int f(int ind,int buy,int cap,vector<int> &prices,int n){
        if(ind == n || cap == 0) return 0;

        if(buy == 1){
            return max(-prices[ind]+f(ind+1,0,cap,prices,n),0 + f(ind+1,1,cap,prices,n));
        }
        return max(prices[ind]+f(ind+1,1,cap-1,prices,n),0+f(ind+1,0,cap,prices,n));
    } 
    // tc-> 2powern
    // sc->0(N)

    //Memoization Solution
     int f(int ind,int buy,int cap,vector<int> &prices,int n,vector<vector<vector<int>>> &dp){
        if(ind == n || cap == 0) return 0;

        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        if(buy == 1){
            return dp[ind][buy][cap] = max(-prices[ind]+f(ind+1,0,cap,prices,n,dp),0 + f(ind+1,1,cap,prices,n,dp));
        }
        return dp[ind][buy][cap] = max(prices[ind]+f(ind+1,1,cap-1,prices,n,dp),0+f(ind+1,0,cap,prices,n,dp));
    } 
    //tc->N*2*3
    //sc->N*2*3 + 0(N);

    int maxProfit(vector<int>& prices,int n){
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,n,dp);
        }

    //Tabulation Solution 
 int maxProfit(vector<int>& prices,int n){
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,0)));
        // writing base case is useless as it is already 0 
        // for(int ind =0;ind<n;ind++){
        //     for(int buy =0;buy<2;buy++){
        //         dp[ind][buy][0] = 0;
        //     }
        // }
        // for(int cap =0;cap<3;cap++){
        //     for(int buy =0;buy<2;buy++){
        //         dp[n][buy][cap] = 0;
        //     }
        // }

        for(int ind=n-1;ind>=0;ind--){
            for(int buy =0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy == 1){
                         dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap],0 + dp[ind+1][1][cap]);
                    }
                    else{ 
                        dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
        }

    //space optimzation 
    int maxProfit(vector<int>& prices,int n)
    {
        vector<vector<int>> after(2,vector<int>(3,0));
        vector<vector<int>> cur(2,vector<int>(3,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy =0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy == 1){
                         cur[buy][cap] = max(-prices[ind]+after[0][cap],0 + after[1][cap]);
                    }
                    else{ 
                        cur[buy][cap] = max(prices[ind]+after[1][cap-1],0+after[0][cap]);
                    }
                }
            }
            after = cur;
        }
         return after[1][2];
    }
    // sc->constant 
};
// add a file 
// we can do it in tc->n*4
// by using n*4 dp 
// use 0 1 2 3
// buy sell buy sell 
// f(ind,transaction)
    //  if(ind == n || trans == 4) return 0;
    //  if(trans% 2 == 0) buy 
    //  else sell 