// Longest Common Subsequence | DP on Strings
#include<bits/stdc++.h>
using namespace std;

class Solution{
    //recursive Solution
    // int f(int i,int j,string &s,string &t){
    //     if(i<0 || j<0) return 0;
    //     if(s[i] == t[j]) return 1+ f(i-1,j-1,s,t);
    //     return max(f(i-1,j,s,t),f(i,j-1,s,t));
    // }
    // change in base case
    int f(int i,int j,string &s,string &t){
        if(i==0 || j==0) return 0;
        if(s[i-1] == t[j-1]) return 1 + f(i-1,j-1,s,t);
        return max(f(i-1,j,s,t) , f(i,j-1,s,t));
    }
    //tc->0(2powerN + 2powerM)  == exponential
    //sc-0(n*m)

    //Memoization Solution
    // int f(int i,int j,string &s,string &t,vector<vector<int>>dp){
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(s[i] == t[j]) return dp[i][j] = 1+ f(i-1,j-1,s,t,dp);
    //     return dp[i][j] = max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
    // }
    //for changing base case
    int f(int i,int j,string &s,string &t,vector<vector<int>>dp){
        if(i==0 || j==0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == t[j-1]) return dp[i][j] = 1+ f(i-1,j-1,s,t,dp);
        return dp[i][j] = max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
    } 
    //tc->0(n*m)
    //sc->0(n*m) + 0(n*m) recursive stack space
    
    int lcs(string s,string t){
        int n =s.size();
        int m =t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,t);
    }

    // Tabulation Solution
    int lcs(string s,string t){
        int n =s.size();
        int m =t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int j=0;j<=m;j++) dp[0][j] =0;
        for(int i=0;i<=n;i++) dp[i][0] =0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }

    //space optimzation Solution 
    int lcs(string s,string t){
        int n =s.size();
        int m =t.size();
        vector<int>prev(m+1,0),cur(m+1,0);

        for(int j=0;j<m;j++) prev[j] =0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i] == t[j]) cur[j] = 1+ prev[j-1];
                else cur[j] = max(prev[j],cur[j-1]);
            }
            prev = cur;
        }
        return prev[m];
    }

};