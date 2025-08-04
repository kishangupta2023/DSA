// Counts Subsets with Sum K 
#include<bits/stdc++.h>
using namespace std;

class Solution{ 
    //recursive Solution
    int f(int ind,int sum,vector<int> &num){
        if(sum == 0) return 1;
        if(ind == 0) return num[0] == sum;
        int notTake = f(ind-1,sum,num);
        int take = 0;
        if(num[ind] <=sum) take = f(ind-1,sum-num[ind],num);

        return notTake+take;
    }
    //tc -0(2powerN)
    // sc->0(n)


    // Memoization Solution 
    int f(int ind,int sum,vector<int> &num,vector<vector<int>>&dp){
        if(sum == 0) return 1;
        if(ind == 0) return num[0] == sum;
        if(dp[ind][sum] != -1) return dp[ind][sum];
        int notTake = f(ind-1,sum,num,dp);
        int take = 0;
        if(num[ind] <=sum) take = f(ind-1,sum-num[ind],num,dp);

        return dp[ind][sum] = notTake+take;
    }
    // tc-> 0(n*sum)
    //sc->0(n*sum) + 0(n)

    int findWays(vector<int> &num,int tar){
        int n = num.size();
        vector<vector<int>>dp(n,vector<int>(tar+1,-1));
        return f(n-1,tar,num,dp);
    }

    // tabulation Solution
    int findWays(vector<int> &num,int tar){
        int n = num.size();
        vector<vector<int>>dp(n,vector<int>(tar+1,0));
        for(int i=0;i<n;i++) dp[i][0] = 1;
        if(num[0] <= tar) dp[0][num[0]] = 1;
        for(int ind=1;ind<n;ind++){
            for(int sum =0;sum<=tar;sum++){
                int notTake = dp[ind-1][sum];
                int take = 0;
                if(num[ind] <=sum) take = dp[ind-1][sum-num[ind]];

                dp[ind][sum] = notTake+take;
            }
        }
        return dp[n-1][tar];
    }
    //tc-0(n*Sum)
    // sc -0(n*Sum)

    //space optimization 
    int findWays(vector<int> &num,int tar){
        int n = num.size();
        vector<int>prev(tar+1,0),cur(tar+1,0);
        cur[0] = prev[0] = 1;
        if(num[0] <= tar) prev[num[0]] = 1;

        for(int ind=1;ind<n;ind++){
            for(int sum =0;sum<=tar;sum++){
                int notTake = prev[sum];
                int take = 0;
                if(num[ind] <=sum) take = prev[sum-num[ind]];

                cur[sum] = notTake+take;
            }
            prev = cur;
        }
        return prev[tar];
    }
    //tc-0(n*Sum)
    //sc-0(SUm)

};