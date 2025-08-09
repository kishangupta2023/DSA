//Rod Cutting Problem | S Array Space optimised Approach 

#include<bits/stdc++.h>
using namespace std;

class Solution{

    // recursive Solution
    int f(int ind,int N,vector<int> &price){
        if(ind == 0) {
            return N*price[0];
        }

        int notTake = 0+ f(ind-1,N,price);
        int take = INT_MIN;
        int rodLength = ind+1;
        if(rodLength<= N){
             take = price[ind]+ f(ind,N-rodLength,price);
        }

        return max(notTake,take);
    }
    // tc->exponential 
    // sc-0(target)

    //Memoization Solution
     int f(int ind,int N,vector<int> &price,vector<vector<int>>&dp){
       if(ind == 0) {
            return N*price[0];
        }

        if(dp[ind][N] !=-1) return dp[ind][N];
        int notTake = 0+ f(ind-1,N,price,dp);
        int take = INT_MIN;
        int rodLength = ind+1;
        if(rodLength<= N){
             take = price[ind]+ f(ind,N-rodLength,price,dp);
        }
        return dp[ind][N]=max(notTake,take);
    }
    //tc-> 0(N*N)
    //sc-> 0(N*N) + 0(TARGET)

    int rodCutting(int n,vector<int>&price){
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
    }

    //Tabulation Solution
     int rodCutting(int n,vector<int>&price){
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        for(int N =0;N<n;N++){
            dp[0][N] =N*price[0];
        }

        for(int ind =1;ind<n;ind++){
            for(int N=0;N<=n;N++){
                 int notTake = 0+ dp[ind-1][N];
                 int take = INT_MIN;
                 int rodLength = ind+1;
                 if(rodLength<= N){
                    take = price[ind]+ dp[ind][N-rodLength];
                }
              dp[ind][N]=max(notTake,take);
            }
        }
        return dp[n-1][n];
    }
    //tc->0(N*W)
    //sc->0(N*W)

    //space optimized //2array space optimization 
    int rodCutting(int n,vector<int>&price){
        vector<int>prev(n+1,0),cur(n+1,0);
        for(int N =0;N<n;N++){
            prev[N] =N*price[0];
        }

        for(int ind =1;ind<n;ind++){
            for(int N=0;N<=n;N++){
                 int notTake = 0+ prev[N];
                 int take = INT_MIN;
                 int rodLength = ind+1;
                 if(rodLength<= N){
                    take = price[ind]+ cur[N-rodLength];
                }
              cur[N]=max(notTake,take);
            }
            prev = cur;
        }
        return prev[n];
    } 
    
    //space optimized //1D array space optimization 
    int rodCutting(int n,vector<int>&price){
        vector<int>prev(n+1,0);
        for(int N =0;N<n;N++){
            prev[N] =N*price[0];
        }

        for(int ind =1;ind<n;ind++){
            for(int N=0;N<=n;N++){
                 int notTake = 0+ prev[N];
                 int take = INT_MIN;
                 int rodLength = ind+1;
                 if(rodLength<= N){
                    take = price[ind]+ prev[N-rodLength];
                }
              prev[N]=max(notTake,take);
            }
        }
        return prev[n];
    }
};