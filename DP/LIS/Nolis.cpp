// Number of Longest Increasing Subsequences
//arr[] = {1,3,5,4,7}
// ans = {1,3,4,7} and {1,3,5,7} 2 subsequences 

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int findNumberOfLIS(vector<int> &arr){
        int n = arr.size();
        vector<int> dp(n,1),cnt(n,1);
        int maxi = 1;
        for(int i =0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(arr[prev] < arr[i] && 1+dp[prev] > dp[i]){
                    dp[i] =1+ dp[prev];
                    // inherit
                    cnt[i] = cnt[prev];
                }
                else if(arr[prev] < arr[i] && 1+dp[prev] == dp[i]){
                    // increase the count
                    cnt[i] +=cnt[prev];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        int nos = 0;
        for(int i=0;i<n;i++){
            if(dp[i] == maxi) nos += cnt[i];
        }
        return nos;
    }
};