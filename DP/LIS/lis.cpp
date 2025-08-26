// Longest Increasing Subsequence
#include<bits/stdc++.h>
using namespace std;

class Solution{
    // Recursive Solution
    int f(int ind,int prev_ind,int arr[],int n){
        if(ind == n) return 0;

        int len = 0+f(ind+1,prev_ind,arr,n);
        if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
            len = max(len,1 + f(ind+1,ind,arr,n));
        }
        return len;
    }
        //tc-2powern
        //sc-0(N) 
        
        // Memoization solution 
    int f(int ind,int prev_ind,int arr[],int n,vector<vector<int>>&dp){
        if(ind == n) return 0;

        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];
        int len = 0+f(ind+1,prev_ind,arr,n,dp);
        if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
            len = max(len,1 + f(ind+1,ind,arr,n,dp));
        }
        return dp[ind][prev_ind+1]=len;
    }
    //tc->N*N
    //sc->0(N*N) + 0(N)

    int longestIncreasingSubsequence(int arr[],int n){
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,arr,n,dp);
    }

    // Tabulation Solution 
    int longestIncreasingSubsequence(int arr[],int n){
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind =n-1;ind>=0;ind--){
            for(int prev_ind = ind-1;prev_ind >= -1;prev_ind--){
                int len = 0+dp[ind+1][prev_ind+1];
                if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
                    len = max(len,1 + dp[ind+1][ind+1]);
                }
                dp[ind][prev_ind+1]=len;
            }
        }
        return dp[0][-1+1];
    }
    // tc-0(N*N)
    // sc-0(n*n) 

    // space optimzation Solution
    int longestIncreasingSubsequence(int arr[],int n){
        vector<int>next(n+1,0),cur(n+1,0);
        for(int ind =n-1;ind>=0;ind--){
            for(int prev_ind = ind-1;prev_ind >= -1;prev_ind--){
                int len = 0+next[prev_ind+1];
                if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
                    len = max(len,1 + next[ind+1]);
                }
                cur[prev_ind+1]=len;
            }
            next =cur;
        }
        return next[-1+1];
    }
    //tc-0(N*N)
    // sc-0(1)

    // optimize tabulation Solution 
    int longestIncreasingSubsequence(int arr[],int n){
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i =0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(arr[prev] < arr[i]){
                    dp[i] = max(dp[i],1+ dp[prev]);
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
    // tc-0(N*N);
    // sc-0(N);
};