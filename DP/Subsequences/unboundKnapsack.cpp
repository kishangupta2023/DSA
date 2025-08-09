// Unbounded knapsack | 1-D Array Space optimised Approach
// there are infinite supply of items

#include<bits/stdc++.h>
using namespace std;

class Solution{

    // recursive Solution
    int f(int ind,int W,vector<int> &wt,vector<int>&val){
        if(ind == 0) {
            return ((int)(W/wt[0]))*val[0];
        }

        int notTake = 0+ f(ind-1,W,wt,val);
        int take = 0;
        if(wt[ind] <= W){
             take = val[ind]+ f(ind,W-wt[ind],wt,val);
        }

        return max(notTake,take);
    }
    // tc->2powern
    // sc-0(W)

    //Memoization Solution
     int f(int ind,int W,vector<int> &wt,vector<int>&val,vector<vector<int>>&dp){
        if(ind == 0) {
            return ((int)(W/wt[0]))*val[0];
        }
        if(dp[ind][W] != -1) return dp[ind][W];
        int notTake = 0+ f(ind-1,W,wt,val,dp);
        int take = INT_MIN;
        if(wt[ind] <= W){
             take = val[ind]+ f(ind,W-wt[ind],wt,val,dp);
        }

        return dp[ind][W]=max(notTake,take);
    }
    //tc-> 0(N*W)
    //sc-> 0(N*W) + 0(N)

    int unboundedKnapsack(int n,int w,vector<int>&val,vector<int>&wt){
        vector<vector<int>>dp(n,vector<int>(w+1,-1));
        return f(n-1,w,wt,val,dp);
    }

    //Tabulation Solution
    int unboundedKnapsack(int n,int w,vector<int>&val,vector<int>&wt){
        vector<vector<int>>dp(n,vector<int>(w+1,0));

        for(int W =0;W<w;W++){
            dp[0][W] = ((int)(W/wt[0]))*val[0];
        }

        for(int ind =1;ind<n;ind++){
            for(int W=0;W<=w;W++){
                int notTake = 0+ dp[ind-1][W];
                int take = 0;
                if(wt[ind] <= W){
                    take = val[ind] + dp[ind][W-wt[ind]];
                }
                dp[ind][W] = max(take,notTake);
            }
        }
        return dp[n-1][w];
    }
    //tc->0(N*W)
    //sc->0(N*W)

    //space optimized //2array space optimization 
    int unboundedKnapsack(int n,int w,vector<int>&val,vector<int>&wt){
         vector<int>prev(w+1,0),cur(w+1,0);

        for(int W =0;W<w;W++){
            prev[W] = ((int)(W/wt[0]))*val[0];
        }

       for(int ind =1;ind<n;ind++){
            for(int W=0;W<=w;W++){
                int notTake = 0+ prev[W];
                int take = 0;
                if(wt[ind] <= W){
                    take = val[ind] + cur[W-wt[ind]];
                }
                cur[W] = max(take,notTake);
            }
            prev = cur;
        }
        return prev[w];
    }
    //tc->0(N*W)
    //sc->0(W)

    //space optimzation in single array

    int unboundedKnapsack(int n,int w,vector<int>&val,vector<int>&wt){
         vector<int>prev(w+1,0);

        for(int W =0;W<w;W++){
            prev[W] = ((int)(W/wt[0]))*val[0];
        }

       for(int ind =1;ind<n;ind++){
            for(int W=0;W<=w;W++){
                int notTake = 0+ prev[W];
                int take = 0;
                if(wt[ind] <= W){
                    take = val[ind] + prev[W-wt[ind]];
                }
                prev[W] = max(take,notTake);
            }
            
        }
        return prev[w];
    }
};