// Partition Array for Maximum Sum 
// You are given an integer array arr with length n, and an integer k.
// You may partition arr into one or more contiguous sub-arrays, where each sub-array has length in the range 1 … k (inclusive).
// After you pick a partition, replace every element in each sub-array with the maximum value found in that sub-array. The array is modified in-place for the purpose of computing the total.
// Return the largest possible sum of the entire array after performing exactly one such partition-and-replace operation.
// The test cases are guaranteed to have an answer that fits in a 32-bit signed integer.
// Examples
// Input: arr = [1,15,7,9,2,5,10], k = 3
// Output: 84
// Explanation:
// Choose blocks
// [1,15,7] → max = 15,
// [9] → max = 9,
// [2,5,10] → max = 10.
// The array becomes [15,15,15,9,10,10,10]; sum = 84.

// Input: arr = [2,2,2,2], k = 2
// Output: 8
// Explanation:
// Partition as [2,2] and [2,2]; each sub-array’s max is 2.  
// The array stays [2,2,2,2] and the sum is 8.

#include<bits/stdc++.h>
using namespace std;

class Solution {

    //Recursive Solution
    int f(int ind,vector<int>&num,int k){
        int n = num.size();
        if(ind == n) return 0;
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for(int j = ind;j< min(n,ind+k);j++){
            len++;
            maxi = max(maxi,num[j]);
            int sum = len*maxi + f(j+1,num,k);
            maxAns = max(sum,maxAns);
        }
        return maxAns;
    }
    // tc-exponential 

    // Memoization Solution
    int f(int ind,vector<int>&num,int k,vector<int>&dp){
        int n = num.size();
        if(ind == n) return 0;
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        if(dp[ind] != -1) return dp[ind];
        for(int j = ind;j< min(n,ind+k);j++){
            len++;
            maxi = max(maxi,num[j]);
            int sum = len*maxi + f(j+1,num,k,dp);
            maxAns = max(sum,maxAns);
        }
        return dp[ind] = maxAns;
    }
    // tc->0(N) *0(K)
    // sc -0(N)+0(N)


    int maximumSubarray(vector<int>& num, int k) {
        int n = num.size();
        vector<int> dp(n,-1);
        return f(0,num,k,dp);
    }

    //Tabulation Solution
    int maximumSubarray(vector<int>& num, int k) {
        int n = num.size();
        vector<int> dp(n+1,0);
        dp[n] = 0;

        
        for(int ind = n-1;ind>=0;ind--){
            int len = 0;
            int maxi = INT_MIN;
            int maxAns = INT_MIN;
            for(int j = ind;j< min(n,ind+k);j++){
               len++;
               maxi = max(maxi,num[j]);
               int sum = len*maxi + dp[j+1];
               maxAns = max(sum,maxAns);
             }
             dp[ind] = maxAns;
        }
        return dp[0];
    }

};