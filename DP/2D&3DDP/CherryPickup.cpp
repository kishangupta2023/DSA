//Cherry Pickup || 3D DP || Dp on Grids
// Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.
// Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, 'C' 1) in the grid. Each of them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero. If both stay in the same cell. only one of them will pick the chocolates in it.
// If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j 1) or (i + 1, j +1). They will always stay inside the 'GRID.
// Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules .
//Example ->
// 2 3 1 2
// 3 4 2 2
// 5 6 3 5
// alice->2->4->6
// bob -> 2 ->2->5
// max sum 12+9 = 21


#include<bits/stdc++.h>
using namespace std;

class Solution{
    // recursive Solution 
    int f(int i,int j1,int j2,int c,int r,vector<vector<int>> &grid){
        if(j1<0 || j2<0 || j1>= c || j2>=c){
            return -1e8;
        }
        if(i == r-1){
            if(j1 == j2) return grid[i][j1];
        }
        else{
            return grid[i][j1] +grid[i][j2];
        }
        // explore all paths of alce and bob simultaneously
        int maxi =-1e9;
        for(int dj1 = -1; dj1 <=1;dj1++){
            for(int dj2=-1;dj2 <=1;dj2++){
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += f(i+1,j1+dj1,j2+dj2,r,c,grid);
                maxi = max(maxi,value);
            }
        }
        return maxi;
    }
    // Memoization
    int f(int i,int j1,int j2,int c,int r,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp){
        if(j1<0 || j2<0 || j1>= c || j2>=c){
            return -1e8;
        }
        if(i == r-1){
            if(j1 == j2) return grid[i][j1];
        }
        else{
            return grid[i][j1] +grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        // explore all paths of alce and bob simultaneously
        int maxi =-1e9;
        for(int dj1 = -1; dj1 <=1;dj1++){
            for(int dj2=-1;dj2 <=1;dj2++){
                int value = 0;
                if(j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];
                value += f(i+1,j1+dj1,j2+dj2,r,c,grid,dp);
                maxi = max(maxi,value);
            }
        }
        return dp[i][j1][j2] =maxi;
    }
    // tc-0(n*m*m)*9
    //sc -0(n*m*m) + 0(N)stack space
    int maximumChocolates(int r,int c,vector<vector<int>> &grid){
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return f(0,0,c-1,r,c,grid,dp);
    }

    // Tabulation Solution 
    int maximumChocolates(int n,int m,vector<vector<int>> &grid){
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if( j1 == j2) dp[n-1][j1][j2] = grid[n-1][j2];
                else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        for(int i=n-2; i>=0; i--){
            for(int j1=0; j1 < m; j1++){
                for(int j2=0; j2 < m; j2++){
                    int maxi =-1e9;
                    for(int dj1 = -1; dj1 <=1;dj1++){
                    for(int dj2=-1;dj2 <=1;dj2++){
                    int value = 0;
                    if(j1 == j2) value = grid[i][j1];
                    else value = grid[i][j1] + grid[i][j2];
                    if(j1+dj1 >=0 && j1+dj1 <m && j2+dj2>=0 && j2+dj2<m){
                    value += dp[i+1][j1+dj1][j2+dj2];
                    }else{
                        value += -1e8;
                    }
                    maxi = max(maxi,value);
                }
            }
                dp[i][j1][j2] =maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }

    // Space optimiation 
    int maximumChocolates(int n,int m,vector<vector<int>> &grid){
        vector<vector<int>>front(n,vector<int>(m,0));
        vector<vector<int>>cur(n,vector<int>(m,0));
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if( j1 == j2) front[j1][j2] = grid[n-1][j2];
                else front[j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }

        for(int i=n-2; i>=0; i--){
            for(int j1=0; j1 < m; j1++){
                for(int j2=0; j2 < m; j2++){
                    int maxi =-1e9;
                    for(int dj1 = -1; dj1 <=1;dj1++){
                    for(int dj2=-1;dj2 <=1;dj2++){
                    int value = 0;
                    if(j1 == j2) value = grid[i][j1];
                    else value = grid[i][j1] + grid[i][j2];
                    if(j1+dj1 >=0 && j1+dj1 <m && j2+dj2>=0 && j2+dj2<m){
                    value += front[j1+dj1][j2+dj2];
                    }else{
                        value += -1e8;
                    }
                    maxi = max(maxi,value);
                }
            }
                cur[j1][j2] =maxi;
                }
            }
            front = cur;
        }
        return front[0][m-1];
    }

};