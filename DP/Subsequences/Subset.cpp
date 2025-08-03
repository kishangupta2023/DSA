//Subset sum equal to target
// You are given an array/list 'ARR' of 'N' positive integers and an integer 'K'. Your task is to check if there exists a subset in 'ARR' with a sum equal to 'K'.
// Note: Return true if there exists a subset with sum equal to 'K'. Otherwise, return false.
// For Example:
// If 'ARR' is (1,2,3,4) and 'X'4, then there exists 2 subsets with sun 4. These are (1,3) and (4). Hence, return true.

#include<bits/stdc++.h>
using namespace std;
 
class Solution{
    //Recursive Solution
    bool f(int ind,int target,vector<int>&arr){
        if(target == 0) return true;
        if(ind == 0) return (arr[0] == target);
        bool notTake = f(ind-1,target,arr);
        bool take = false;
        if(arr[ind] <= target) take = f(ind-1,target-arr[ind],arr);
        return take | notTake;
    }
    //tc-> 0(2powern)
    // sc -> 0(n)

    //Memoization Solution
    bool f(int ind,int target,vector<int>&arr,vector<vector<int>> &dp){
        if(target == 0) return true;
        if(ind == 0) return (arr[0] == target);
        if(dp[ind][target] != -1) return dp[ind][target];
        bool notTake = f(ind-1,target,arr,dp);
        bool take = false;
        if(arr[ind] <= target) take = f(ind-1,target-arr[ind],arr,dp);
        return dp[ind][target] = take | notTake;
    } 
    //tc->0(n*target)
    //sc-> 0(n*target)+0(n)

    bool subsetSumToK(int n,int k,vector<int> &arr){
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return f(n-1,k,arr);
    }

    // tabulation Solution
     bool subsetsumToK(int n,int k,vector<int> &arr){
        vector<vector<bool>> dp(n,vector<bool>(k+1,0));
        for(int i=0;i<n;i++) dp[i][0] = true;
        if(arr[0] <= k) dp[0][arr[0]] = true;
        for(int ind=1;ind<n;ind++){
            for(int target = 1;target<=k;target++){
                bool notTake = dp[ind-1][target];
                bool take = false;
                if(arr[ind] <= target) take = dp[ind-1][target-arr[ind]];
                dp[ind][target] = take | notTake;
            }
        }
        return dp[n-1][k];
    }
    // tc->0(n*target)
    //sc->0(n*target)

    //space optimization
    bool subsetsumtoK(int n,int k,vector<int> &arr){
        vector<bool> prev(k+1,0),cur(k+1,0);
        for(int i=0;i<n;i++) prev[0] =cur[0] = true;
        if(arr[0] <= k) prev[arr[0]] = true;
        for(int ind=1;ind<n;ind++){
            for(int target = 1;target<=k;target++){
                bool notTake = prev[target];
                bool take = false;
                if(arr[ind] <= target) take = prev[target-arr[ind]];
                cur[target] = take | notTake;
            }
            prev = cur;
        }
        return prev[k];
    }
    // tc->0(n*target)
    // sc->0(target)
};