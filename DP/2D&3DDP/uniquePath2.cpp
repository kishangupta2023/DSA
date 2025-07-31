// Maze obsrtacles
// Given a 'N' 'M' maze with obstacles, count and return the number of paths to reach the right-bottom cell from the top-left cell. A cell in the given maze has a value-1 if it is a blockage or dead-end, else 0. From a given cell, we are allowed to move to cells (i+1, j) and (i. j+1) only. Since the answer can be large, print it modulo 10^9 + 7.
// example 
// 0 0 0
// 0 -1 0
// 0 0 0
// ways =2 


#include<bits/stdc++.h>
using namespace std;
class solution{
    int mod = (int)(1e9 + 7);
    int f(int i,int j,vector<vector<int>>& maze){
        if(i>=0 && j>=0 && maze[i][j] == -1) return 0;
        if(i == 0 && j ==0) return 1;
        if(i<0 || j<0) return 0;
        int up = f(i-1,j,maze);
        int left = f(i,j-1,maze);
        return up + left;
    }
    int mazeobstacles(int n,int m,vector<vector<int>> maze){
        return f(m-1,n-1,maze);
    }

    // memoization 
    int f(int i,int j,vector<vector<int>> maze,vector<vector<int>>&dp){
        if(i>=0 && j>=0 && maze[i][j] == -1) return 0;
        if(i == 0 && j ==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up = f(i-1,j,maze,dp);
        int left = f(i,j-1,maze,dp);
        return dp[i][j] = (up + left)% mod;
    }
    int mazeObstacles(int n,int m,vector<vector<int>> maze){
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(m-1,n-1,maze,dp);
    }

    // Tabulation Solution 
    int mazeObstacle(int n,int m,vector<vector<int>>maze){
        int dp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(maze[i][j] == -1) dp[i][j] =0;
                else if(i ==0 && j == 0) dp[i][j] =1;
                else{
                    int up=0;
                    int left=0;
                    if(i>0)  up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = (up + left)%mod;
                }
            }
        }
        return dp[n-1][m-1];
    }


    // space optimization 
    int mazeObstacles2(int n,int m,vector<vector<int>> maze){
        vector<int> prev(n,0);
        for(int i=0;i<n;i++){
            vector<int> cur(n,0);
            for(int j=0;j<m;j++){
                if(maze[i][j] == -1) cur[j] = 0;
                else if(i ==0 && j == 0) cur[j] =1;
                else{
                    int up=0;
                    int left=0;
                    if(i>0) up = prev[j];
                    if(j>0) left =cur[j-1];
                    cur[j] = (up +left%mod);
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }
};