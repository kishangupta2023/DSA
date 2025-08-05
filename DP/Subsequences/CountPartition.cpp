// Count partition with given Differnece 
// Given an array "ARR",partition it into two subset (possibly empty) such that their union is the original array . Let the Sum of the elements of these two subsets be 'S1' and 'S2'.
// Given the difference 'D' count the number of partitions in which 'S1'is greater than or equal to 'S2' and the difference between 'S1' and 'S2' is equal to "D". Since the answer may be too large ,return modulo '10^9 + 7'.
// If 'Pi_Sj' denotes the Subset 'j' for partition 'i'. THen ,two partitios P1 and P2 are considered different if->
//1)P1_S1 = P1_S1 at lest one of the elements of P1_S1 is diffrenet

//s1-s2 = D
// TotSum -s2-s2 = D
// S2  = (totSum -D)/2
//Count of subsets with S2 

#include<bits/stdc++.h>
using namespace std;



    int mod = (int)(1e9 + 7);
    // Memoization Solution 
     int f(int ind,int sum,vector<int> &num,vector<vector<int>>&dp){
        if(ind == 0){
            if(sum == 0 && num[0]) return 2;
            if(sum == 0 || sum == num[0]) return 1;
            return 0;
        } 
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int notTake = f(ind-1,sum,num,dp);
        int take = 0;
        if(num[ind] <=sum) take = f(ind-1,sum-num[ind],num,dp);

        return dp[ind][sum] = (notTake+take)%mod;
    }

    int findWays(vector<int> &num,int tar){
        int n = num.size();
        vector<vector<int>>dp(n,vector<int>(tar+1,-1));
        return f(n-1,tar,num,dp);
    }

    int countPartitions(int n,int d,vector<int>&arr){
        int totSum =0;
        for(auto &it: arr) totSum+=it;
        if(totSum -d < 0 || (totSum -d) % 2) return false;
        return findWays(arr,(totSum-d)/2);
    }


    // tabulation Solution
    int findWays(vector<int> &num,int tar){
        int n = num.size();
        vector<vector<int>>dp(n,vector<int>(tar+1,0));
        if(num[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        // num[0] = 0
        if(num[0] !=0 && num[0] <= tar) dp[0][num[0]] = 1;
        for(int ind=1;ind<n;ind++){
            for(int sum =0;sum<=tar;sum++){
                int notTake = dp[ind-1][sum];
                int take = 0;
                if(num[ind] <=sum) take = dp[ind-1][sum-num[ind]];

                dp[ind][sum] = (notTake+take)%mod;
            }
        }
        return dp[n-1][tar];
    }

    //space optimization 
    int findWays(vector<int> &num,int tar){
        int n = num.size();
        vector<int>prev(tar+1,0),cur(tar+1,0);
        if(num[0] == 0) prev[0] = 2;
        else prev[0] =1;
        if(num[0] !=0 && num[0] <= tar) prev[num[0]] = 1;

        for(int ind=1;ind<n;ind++){
            for(int sum =0;sum<=tar;sum++){
                int notTake = prev[sum];
                int take = 0;
                if(num[ind] <=sum) take = prev[sum-num[ind]];

                cur[sum] = (notTake+take)%mod;
            }
            prev = cur;
        }
        return prev[tar];
    }
