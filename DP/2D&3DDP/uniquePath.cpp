// Grid Unique Paths
// Total Unique Paths 
// You are present at point 'A' which is the top-left cell of an MXN matrix, your destination is point "B". which is the bottom-right cell of the same matrix. Your task is to find the total number of unique paths from point 'A' to point 'B'. In other words, you will be given the dimensions of the matrix as integers 'M' and 'N', your task is to find the total number of unique paths from the cell MATRIX[0][0] to MATRIX['M' - 1]['N-1].
// To traverse in the matrix, you can either move Right or Down at each step. For example in a given point MATRIX[i][j], you can move to either MATRIX[i + 1][j] or MATRIX[i][j+1].
// Input Format:
// The Elrat Line of input contains an integer T representing the number of the .
// The first and the only line of each test cass contains two space-separated intagara 'M' and "H", denoting the number of rows and number of columns of the ваккая respectively.
// Output Format:
// For every test case, return a single integer, which is the total number of unique paths for scaveling from top-left to bottom-right cells of the matrix.
// Example 
//  2
// 2 2
// 1 1
// output 
//2
// 1
#include<bits/stdc++.h>
using namespace std;
class Solution{
    // Recursive Solution
    int f(int i,int j){
        if(i == 0 && j ==0) return 1;
        if(i<0 || j<0) return 0;
        int up = f(i-1,j);
        int left = f(i,j-1);
        return up + left;
    }
    int uniquepaths(int m,int n){
        return f(m-1,n-1);
    }
    // tc - 0(2power(n*m))
    // sc - path length = (m-1) + (n-1)


    //Memoization
    int fs(int i,int j,vector<vector<int>>& dp){
        if(i == 0 && j ==0) return 1;
        if(i<0 || j<0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int up = fs(i-1,j,dp);
        int left = fs(i,j-1,dp);
        return dp[i][j] = up + left;
    }
    int uniquepaths(int m,int n){
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return fs(m-1,n-1,dp);
    }
    // tc -0(n*m)
    //sc - 0(n-1)+(m-1) + 0(n*m)


    // Tabulation Solution
    int uniquepaths2(int m,int n){
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i ==0 && j == 0) dp[i][j] =1;
                else{
                    int up=0;
                    int left=0;
                    if(i>0)  up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m-1][n-1];
    }
    // Tc -0(n*m)
    // sc -0(n*m)

    // space optimization
    int uniquepaths3(int m,int n){
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> cur(n,0);
            for(int j=0;j<n;j++){
                if(i ==0 && j == 0) cur[j] =1;
                else{
                    int up=0;
                    int left=0;
                    if(i>0) up = prev[j];
                    if(j>0) left =cur[j-1];
                    cur[j] = up +left;
                }
            }
            prev = cur;
        }
        return prev[n-1];
    }


    // for removing TLE 
    int uniquePath(int m,int n){
        int N = n+m-2;
        int r = m-1;
        double res = 1;
        for(int i=1;i<=r;i++){
            res = res*(N-r+i)/i;
        }
        return (int)res;
    }
};
