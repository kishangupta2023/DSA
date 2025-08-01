//Traingle || Fixed starting Point and Variable Ending point 
// You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum to reach from the top to the bottom row.
// The triangle array will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.
// You can move only to the adjacent number of row below each step. For example, if you are at index j in row i, then you can move to i ori+ 1 index in row j + 1 in each step.
// For Example:
// If the array given is TRIANGLE [1], (2,3), (3,6,7), (8,9,6,10) the triangle array will look likes
// 1
// 2,3
// 3,6,7
// 8,9,6,10
// for this the minimum sum path would be 1->2->3->8 answer is 14


#include<bits/stdc++.h>
using namespace std;

class Solution{
    // recursive Solution
    int f(int i,int j,vector<vector<int>>& traingle,int n){
        if( i == n-1){
            return traingle[n-1][j];
        }
        int d = traingle[i][j]+f(i+1,j,traingle,n);
        int dg = traingle[i][j]+f(i+1,j+1,traingle,n);
        return min(d,dg);
    }
    // Memoization Solution
    int f(int i,int j,vector<vector<int>>& traingle,int n,vector<vector<int>>& dp){
        if( i == n-1){
            return traingle[n-1][j];
        }
        if(dp[i][j] != -1) return dp[i][j];
        int d = traingle[i][j]+f(i+1,j,traingle,n,dp);
        int dg = traingle[i][j]+f(i+1,j+1,traingle,n,dp);
        return dp[i][j] = min(d,dg);
    }

    int minimumPathSum(vector<vector<int>> &traingle,int n){
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(0,0,traingle,n,dp);
    }

    //Tabulation Solution
    int minimumPathsum(vector<vector<int>> &traingle,int n){
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++) dp[n-1][j] = traingle[n-1][j];

        for(int i =n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                 int d = traingle[i][j]+dp[i+1][j];
                 int dg = traingle[i][j]+dp[i+1][j+1];
                 dp[i][j] = min(d,dg);
            }
        }
        return dp[0][0];
    }

    // space optimization
    int minimumPathsum(vector<vector<int>> &traingle,int n){
        vector<int>front(n,0),cur(n,0);
        for(int j=0;j<n;j++) front[j] = traingle[n-1][j];

        for(int i =n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                 int d = traingle[i][j]+front[j];
                 int dg = traingle[i][j]+front[j+1];
                 cur[j] = min(d,dg);
            }
            front = cur;
        }
        return front[0];
    }

};