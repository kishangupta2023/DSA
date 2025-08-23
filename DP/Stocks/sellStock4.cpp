// BUy and Sell Stock IV | recursion to space optimization
// allowed to do atmost k transanction 

#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Recusrive Solution
    int f(int ind,int tranNo,vector<int> &prices,int n,int k){
        if(ind == n || tranNo == 2*k) return 0;

        if(tranNo % 2 == 0){
            return max(-prices[ind]+f(ind+1,tranNo+1,prices,n,k),0 + f(ind+1,tranNo,prices,n,k));
        }
        return max(prices[ind]+f(ind+1,tranNo+1,prices,n,k),0+f(ind+1,tranNo,prices,n,k));
    } 
    // tc-> 2powern
    // sc->0(N)

    //Memoization Solution
    int f(int ind,int tranNo,vector<int> &prices,int n,int k,vector<vector<int>> &dp){
        if(ind == n || tranNo == 2*k) return 0;

        if(dp[ind][tranNo] != -1) return dp[ind][tranNo];

        if(tranNo % 2 == 0){
            return dp[ind][tranNo] = max(-prices[ind]+f(ind+1,tranNo+1,prices,n,k),0 + f(ind+1,tranNo,prices,n,k));
        }
         return dp[ind][tranNo] =  max(prices[ind]+f(ind+1,tranNo+1,prices,n,k),0+f(ind+1,tranNo,prices,n,k));
    } 
    //tc->N*2*3
    //sc->N*2*3 + 0(N);

    int maxProfit(vector<int>& prices,int n,int k ){
        vector<vector<int>> dp(2,vector<int>(2*k,-1));
        return f(0,0,prices,n,k,dp);
        }

    //Tabulation Solution 
    int maxProfit(vector<int>& prices,int n,int k ){
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));

        for(int ind = n-1;ind>=0;ind--){
            for(int tranNo = 2*k-1;tranNo>=0;tranNo--){
                 if(tranNo % 2 == 0){
                    dp[ind][tranNo] = max(-prices[ind]+dp[ind+1][tranNo+1],dp[ind+1][tranNo]);
                }
               else{
                 dp[ind][tranNo] =  max(prices[ind]+dp[ind+1][tranNo+1],0+dp[ind+1][tranNo]);
               }
            }
        }
        return dp[0][0];
        }

    //space optimzation 
    int maxProfit(vector<int>& prices,int n,int k)
    {
        vector<vector<int>> after(2,vector<int>(k+1,0));
        vector<vector<int>> cur(2,vector<int>(k+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy =0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
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
         return after[1][k];
    }
    // sc->constant 

    // space optimzation 
     int maxProfit(vector<int>& prices,int n,int k ){
       vector<int> after(2*k+1,0);
       vector<int> cur(2*k+1,0);

        for(int ind = n-1;ind>=0;ind--){
            for(int tranNo = 2*k-1;tranNo>=0;tranNo--){
                 if(tranNo % 2 == 0){
                   cur[tranNo] = max(-prices[ind]+after[tranNo+1],after[tranNo]);
                }
               else{
                 cur[tranNo] =  max(prices[ind]+after[tranNo+1],0+after[tranNo]);
               }
            }
            after =cur;
        }
        return after[0];
        }
};