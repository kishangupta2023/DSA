// Partition A Set into Two Subsets with minimum absolute Sum Difference

// You are given an array containing N non-negative integers. Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.
// You just need to find the minimum absolute difference considering any valid division of the array elements.
// Note:
// 1. Each element of the array should belong to exactly one of the subset.
// 2. Subsets need not be contiguous always. For example, for the array (1.2.3), sum of the possible divisions are a) (1,2) and (3) b) (1,3) and (2).
// 3. Subset sum in the sum of all the elements in that subset.

//Example -> [1,2,3,4]
// => [1,4],[2,3] 
// |5-5| = 0 minimum 
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int minSubsetSumDiffernece(vector<int>& arr,int n){
        int totSum = 0;
        for(int i=0;i<n;i++) totSum +=arr[i];

        int k = totSum;
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

        // dp[n-1][col] from 0 to totsum have answer
        int mini = 1e9;
        for(int s1=0;s1<=totSum/2;s1++){
            if(dp[n-1][s1] == true){
                mini = min(mini,abs((totSum-s1)-s1));
            }
        }
        return mini;

    }


    //space optimization 
    int minSubsetSumDiffernece(vector<int>& arr,int n){
        int totSum = 0;
        for(int i=0;i<n;i++) totSum +=arr[i];

        int k = totSum;
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

        // dp[n-1][col] from 0 to totsum have answer
        int mini = 1e9;
        for(int s1=0;s1<=totSum/2;s1++){
            if(prev[s1] == true){
                mini = min(mini,abs((totSum-s1)-s1));
            }
        }
        return mini;

    }
};
