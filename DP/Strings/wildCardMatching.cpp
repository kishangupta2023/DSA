// WildCard Matching 
// ? -> matches with single character 
// * -> matches with sequence of length (0) or more 
// example1 -> s1 = "?ay" and s2 = "ray" 
// you need to return true for above example 

// example2 -> s1 ="ab*cd" and s2 = "abdefcd"
// return true 
// if s1 = "**abcd"
// s2 = "abcd" return true 

// exapmle3 -> s1 ="ab?d" s2 = "abcc"
// return false as c is not equal to d 

#include<bits/stdc++.h>
using namespace std;

class Solution {
    //recursive Solution
    bool f(int i,int j,string &pattern,string &text){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0){
            for(int ii =0;ii<=i;ii++){
                if(pattern[ii] != '*') return false;
            }
            return true;
        }
        if(pattern[i] == text[j] || pattern[i] == '?'){
            return f(i-1,j-1,pattern,text);
        }
        if(pattern[i] == '*'){
            return f(i-1,j,pattern,text) || f(i,j-1,pattern,text);
        }
        return false;
    }
    // tc- > exponential 
    //sc -> 0(N+M)

    //Memoization Solution 
    bool f(int i,int j,string &pattern,string &text,vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0){
            for(int ii =0;ii<=i;ii++){
                if(pattern[ii] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(pattern[i] == text[j] || pattern[i] == '?'){
            return dp[i][j] = f(i-1,j-1,pattern,text,dp);
        }
        if(pattern[i] == '*'){
            return dp[i][j] = f(i-1,j,pattern,text) || f(i,j-1,pattern,text,dp);
        }
        else return dp[i][j] = false;
    }
    //tc->0(N*M)
    // sc-> 0(N*M)+0(N+M)

    // 1 based indexing 
    bool f1(int i,int j,string &pattern,string &text,vector<vector<int>> &dp){
        if(i == 0 && j == 0) return true;
        if(i == 0 && j>=1) return false;
        if(j == 0 && i>=1){
            for(int ii =1;ii<=i;ii++){
                if(pattern[ii-1] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){
            return dp[i][j] = f(i-1,j-1,pattern,text,dp);
        }
        if(pattern[i-1] == '*'){
            return dp[i][j] = f(i-1,j,pattern,text) || f(i,j-1,pattern,text,dp);
        }
        else return dp[i][j] = false;
    }

    bool wildcardMatching(string pattern,string text){
        int n = pattern.size();
        int m = text.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,pattern,text,dp);
    }


    // Tabulation Solution 

     bool wildcardMatching(string pattern,string text){
        int n = pattern.size();
        int m = text.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));

        dp[0][0]= true;
        for(int j=1;j<=m;j++) dp[0][j] = false;
        for(int i=1;i<=n;i++){
            bool flag = true;
            for(int ii =1;ii<=i;ii++){
                if(pattern[ii-1] != '*'){
                     flag = false;
                     break;
                }
            }
            dp[i][0] =  flag;
        }


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){
                      dp[i][j] = dp[i-1][j-1];
                }
                else if(pattern[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }

    //space optimization
    bool wildcardMatching(string pattern,string text){
        int n = pattern.size();
        int m = text.size();
        vector<bool> prev(m+1,false),cur(m+1,false);
        prev[0]= true;
        for(int j=1;j<=m;j++) prev[j] = false;


        for(int i=1;i<=n;i++){
            bool flag = true;
            for(int ii =1;ii<=i;ii++){
                if(pattern[ii-1] != '*'){
                     flag = false;
                     break;
                }
            }
            cur[0] =  flag;
            for(int j=1;j<=m;j++){
                if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){
                      cur[j] = prev[j-1];
                }
                else if(pattern[i-1] == '*'){
                    cur[j] = prev[j] || cur[j-1];
                }
                else cur[j] = false;
            }
            prev = cur;
        }
        return prev[m];
    } 

};