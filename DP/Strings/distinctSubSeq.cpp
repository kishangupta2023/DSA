// Distinct Subsequences | 1D array optimization Technique 
// Example -> s1 ="babgbag"  s2="bag"
//how many times s2 appear in s1 ? 
// in total 5 occurences of s2 in s1

#include<bits/stdc++.h>
using namespace std;

class Solution{
    // recursive Solution 
    int f(int i,int j,string s1,string s2){
        if(j<0) return 1;
        if(i<0) return 0;
        if(s1[i] == s2[j]){
            return f(i-1,j-1,s1,s2) + f(i-1,j,s1,s2);
        }
        else{
            return f(i-1,j,s1,s2);
        }
    }
    // tc-> exponential near about 2powern+2powerm
    // sc-> 0(N+M)

    // Memoization Solution
     int f(int i,int j,string s1,string s2,vector<vector<int>>&dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j] !=-1) return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] = f(i-1,j-1,s1,s2,dp) + f(i-1,j,s1,s2,dp);
        }
        else{
            return dp[i][j] = f(i-1,j,s1,s2,dp);
        }
    } 
    //tc->0(n*m)
    //sc->0(n*m)+0(n+m)(stack space)

    int numDistinct(string s,string t){
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }


    //1 based indexing  also declare dp array of n+1,m+1 and pass n and m at the place of n-1 and m-1 in the function 
    int f1(int i,int j,string s1,string s2){
        if(j == 0) return 1;
        if(i ==0) return 0;
        if(s1[i-1] == s2[j-1]){
            return f1(i-1,j-1,s1,s2) + f1(i-1,j,s1,s2);
        }
        else{
            return f1(i-1,j,s1,s2);
        }
    }

    // Tabulation Solution 1 based indexing 
    int numDistinct(string s,string t){
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++) dp[i][0] = 1;
        // for(int j=1;j<=m;j++) dp[0][j] = 0; you can ommit this as everthing is intiailly Zero 

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+ dp[i-1][j];
                }
                else{
                   dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
    // for overFlow use double at the place of int in dp 

    //space optimization Solution 2 array optimization 
    int numDistinct(string s,string t){
        int n = s.size();
        int m = t.size();
        vector<int>prev(m+1,0),cur(m+1,0);
        prev[0] =cur[0] = 1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    cur[j] = prev[j-1]+ prev[j];
                }
                else{
                   cur[j] = prev[j];
                }
            }
            prev = cur;
        }
        return prev[m];
    }

     //space optimization Solution 1 array optimization 
    int numDistinct(string s,string t){
        int n = s.size();
        int m = t.size();
        vector<int>dp(m+1,0);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1] == t[j-1]){
                    dp[j] = dp[j-1]+ dp[j];
                }
            }
        }
        return dp[m];
    }
};
