// Maximum sum of non-adjacent elements
//You are given an arrayList of N integers . You are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given arrayList.
//Input :2
// 3 size of array 
// 1 2 4 
// 4 size of array 
// 2 1 4 9
//output:
//5
//11

#include<bits/stdc++.h>
using namespace std;
class Solution {
    // Recurrence solution 
    int maxsum(int n,vector<int> &nums){
        if( n == 0) return nums[n];
        if(n < 0) return 0;
        int pick = nums[n] + maxsum(n-2,nums);
        int notpick = 0 + maxsum(n-1,nums);
        return max(pick,notpick);
    }
    //tc-0(2powern)

    //Memoization solution

    int f(int ind,vector<int>& nums,vector<int> &dp){
        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int pick = nums[ind] + f(ind-2,nums,dp);
        int notpick = 0 + f(ind-1,nums,dp);
        return dp[ind] = max(pick,notpick);
    }
    int maxSum(vector<int>&nums){
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums,dp);

    }
    //tc-0(N) and sc-0(N)+0(N)


    // Tabulation way 
    int maxSum2(vector<int>&nums){
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[0] = 0;
        int neg = 0;
        for(int i=0;i<n;i++){
            int take = nums[i];
            if(i>1) take+=dp[i-2];
            int nontake = 0+ dp[i-1];
            dp[i] = max(take,nontake);
        } 
        return dp[n-1];
    }
    //tc-0(N) and sc -0(N)


    //space optimization 
    int maxSum3(vector<int>&nums){
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1) take+=prev2;
            int nontake = 0+prev;
            int curi = max(take,nontake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
    // tc - 0(N) 
    // sc-(1)

};