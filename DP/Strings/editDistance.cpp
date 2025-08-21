// Edit Distance  
// s1 ="horse" s2 ="ros"
// 3 operations u can do 
//any character u can insert anywhere in s1 
// u can take any char and remove from s1 
// pick up any char in string s1 and replace with any given character 
//tell minimum number of steps to convert s1 into given string s2 

#include<bits/stdc++.h>
using namespace std;

class Solution {
    //recursive Solution 
    int f(int i,int j,string &s1,string &s2){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(s1[i] == s2[j]) return f(i-1,j-1,s1,s2);
        return 1+ min(f(i-1,j,s1,s2),min(f(i-1,j-1,s1,s2),f(i,j-1,s1,s2)));
    }
    // tc-Exponential 
    //sc -0(N*M)

    // Memoization Solution 
    int f(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) dp[i][j] = f(i-1,j-1,s1,s2,dp);
        return dp[i][j]  = 1 + min(f(i-1,j,s1,s2,dp),min(f(i-1,j-1,s1,s2,dp),f(i,j-1,s1,s2,dp)));
    }

    // for 1based indexing 
     int f1(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i == 0) return j;
        if(j == 0) return i;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i-1] == s2[j-1]) dp[i][j] = f(i-1,j-1,s1,s2,dp);
        return dp[i][j]  = 1 + min(f(i-1,j,s1,s2,dp),min(f(i-1,j-1,s1,s2,dp),f(i,j-1,s1,s2,dp)));
    }
    //tc-0(N*M)
    //sc-0(N*M)+0(N+M)

    int editDistance(string str1,string str2){
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,str1,str2,dp);
    }

    //Tabulation Solution 
     int editDistance(string s1,string s2){
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j=0;j<=m;j++) dp[0][j] = j;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j]  = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
            }
        }
        return dp[n][m];
    }

    // space optimization 
      int editDistance(string s1,string s2){
        int n = s1.size();
        int m = s2.size();
        vector<int>prev(m+1,0),cur(m+1,0);

        for(int j=0;j<=m;j++) prev[j] = j;

        for(int i=1;i<=n;i++){
            cur[0] =i;
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]) cur[j] = prev[j-1];
                else cur[j]  = 1 + min(prev[j],min(prev[j-1],cur[j-1]));
            }
            prev = cur;
        }
        return prev[m];
    }
};