// Minimum Path Sum in Grid 
// Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' columns. Each point in the grid has some cost associated with it.
// Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) which minimizes the sum of the cost of all the numbers along the path. You need to tell the minimum sum of that path.
// Note:
// You can only nove down or right at any point in time

#include<bits/stdc++.h>
using namespace std;

class Solution{

    // Recursive Solution
    int f2(int i,int j,vector<vector<int>>& path){
        if(i==0 && j==0) return path[0][0];
        if(i<0 || j<0) return 1e9;
        int up = path[i][j] + f2(i-1,j,path);
        int down = path[i][j] + f2(i,j-1,path);
        return min(up,down);
    }
    int minSumPathrec(vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        return f2(n-1,m-1,grid);
    }


    //Memoization Solution
    int f(int i,int j,vector<vector<int>>& path,vector<vector<int>> &dp){
        if(i==0 && j==0) return path[i][j];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j] != -1) return dp[i][j];
        int up = path[i][j] + f(i-1,j,path,dp);
        int down = path[i][j] + f(i,j-1,path,dp);
        return dp[i][j] = min(up,down);
    }
    int minSumPath(vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,grid,dp);
    }
    //tc- 0(n*m)
    //sc -0(n*m) +( 0(m-1)+(n-1))

    //tabulation Solution
    int minSumPath(vector<vector<int>> &path){
        int n = path.size();
        int m = path[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) dp[i][j] = path[i][j];
                else{
                    int up=path[i][j];
                    if(i>0) up += dp[i-1][j];
                    else up += 1e9;
                    int left =path[i][j];
                    if(j>0) left+= dp[i][j-1];
                    else left += 1e9;
                    dp[i][j] = min(up,left);
                }    
            }
        }
        return dp[n-1][m-1];
    }


    // space optimization
    int minSumPath(vector<vector<int>> &path){
        int n = path.size();
        int m = path[0].size();
        vector<int>prev(n,0);
        for(int i=0;i<n;i++){
            vector<int> cur(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0) cur[j] = path[i][j];
                else{
                    int up=path[i][j];
                    // requiering previous row j's column 
                    if(i>0) up += prev[j];
                    else up += 1e9;

                    int left =path[i][j];
                    // current row previous column
                    if(j>0) left+= cur[j-1];
                    else left += 1e9;
                    cur[j] = min(up,left);
                }    
            }
            prev =cur;
        }
        return prev[m-1];
    }

};