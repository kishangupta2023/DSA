//Minimum/ Maximum Falling Path Sum |Varaible Starting and Ending Points 
// You have been given an N'M matrix filled with integer numbers, find the maximum sum that can be obtained from a path starting from any celling the first row to any cell in the last row. A
// From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right. So from a particular cell (row, col), we can move in three directions i.e.
// Down: (row+1,col)
// Down left diagonal: (row+1,col-1)
// Down right diagonal: (row+1, col+1)
#include<bits/stdc++.h>
using namespace std;

class Solution{
    //Recursive Solution
    int f(int i,int j,vector<vector<int>> &matrix){
        if(j<0 || j>=matrix[0].size()) return -1e8;
        if(i ==0) return matrix[0][j];
        int u = matrix[i][j] + f(i-1,j,matrix);
        int ld = matrix[i][j] + f(i-1,j-1,matrix);
        int rd = matrix[i][j] + f(i-1,j+1,matrix);
        return max(u,max(ld,rd));
    }

    // Memoization Solution

    int f(int i,int j,vector<vector<int>> &matrix,vector<vector<int>>&dp){
        if(j<0 || j>=matrix[0].size()) return -1e8;
        if(i ==0) return matrix[0][j];
        if(dp[i][j] != -1) return dp[i][j];
        int u = matrix[i][j] + f(i-1,j,matrix);
        int ld = matrix[i][j] + f(i-1,j-1,matrix);
        int rd = matrix[i][j] + f(i-1,j+1,matrix);
        return dp[i][j] = max(u,max(ld,rd));
    }

    int getMaxPathSum(vector<vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int maxi = -1e8;
        for(int j=0;j<m;j++){
            maxi = max(maxi,f(n-1,j,matrix,dp));
        }
        return maxi;
    }

    //Tabulation Solution
    int getMaxPathsum(vector<vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++) dp[0][j] = matrix[0][j];

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int u = matrix[i][j] + dp[i-1][j];
                int ld = matrix[i][j];
                if(j-1>=0) ld += dp[i-1][j-1];
                else ld +=-1e8;
                int rd = matrix[i][j];
                if(j+1<m) rd+= dp[i-1][j+1];
                else rd += -1e8;
                dp[i][j]= max(u,max(ld,rd));
            }
        }
        int maxi = -1e8;
        for(int j=0;j<m;j++){
            maxi = max(maxi,dp[n-1][j]);
        }
        return maxi;
    }


    // space optimization 
     int getMaxPathsum(vector<vector<int>> &matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>prev(m,0),cur(m,0);
        for(int j=0;j<m;j++) prev[j] = matrix[0][j];

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int u = matrix[i][j] + prev[j];
                int ld = matrix[i][j];
                if(j-1>=0) ld += prev[j-1];
                else ld +=-1e8;
                int rd = matrix[i][j];
                if(j+1<m) rd+= prev[j+1];
                else rd += -1e8;
                cur[j]= max(u,max(ld,rd));
            }
            prev = cur;
        }
        int maxi = -1e8;
        for(int j=0;j<m;j++){
            maxi = max(maxi,prev[j]);
        }
        return maxi;
    }
};