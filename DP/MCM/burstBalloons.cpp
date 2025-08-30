// Burst Balloons | partition DP
#include<bits/stdc++.h>
using namespace std;

class Solution{

    // recursive Solution
    int f(int i,int j,vector<int>&a){
        if(i>j) return 0;

        int maxi = INT_MIN;
        for(int ind = i;ind<=j;ind++){
            int cost = a[i-1]*a[ind]*a[j+1] + f(i,ind-1,a) + f(ind+1,j,a);
            maxi = max(maxi,cost);
        }
        return maxi;
    }
    //tc-  exponential 

    //Memoization SOlution
    int f(int i,int j,vector<int>&a,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int maxi = INT_MIN;
        for(int ind = i;ind<=j;ind++){
            int cost = a[i-1]*a[ind]*a[j+1] + f(i,ind-1,a,dp) + f(ind+1,j,a,dp);
            maxi = max(maxi,cost);
        }
        return dp[i][j] = maxi;
    }
    // tc-0(N*N*N)
    // sc-0(N*N)+0(N)

    int maxCoins(vector<int> &a){
        int n = a.size();
        a.push_back(1);
        a.insert(a.begin(),1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(1,n,a,dp);
    }

    // tabulation Solution
    int maxCoins(vector<int> &a){
        int n = a.size();
        a.push_back(1);
        a.insert(a.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i = n;i>=1;i--){
            // j == n
            for(int j=1;j<=n;j++){
                 if(i>j) continue;
                 int maxi = INT_MIN;
                 for(int ind = i;ind<=j;ind++){
                     int cost = a[i-1]*a[ind]*a[j+1] + dp[i][ind-1] + dp[ind+1][j];
                     maxi = max(maxi,cost);
                    }
                   dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};

