// Frog Jump with K Distance 
#include<bits/stdc++.h>
using namespace std;

class Solution{
    //Recursive Solution
      int frogjump(int n,int k,vector<int> heights){
        if(n == 0) return 0;
        int minsteps = INT_MAX;
        for(int j =1;j<=k;j++){
            if(n-j>=0){
                int jump = frogjump(n-j,k,heights) + abs(heights[n]-heights[n-j]);
                int minsteps = min(minsteps,jump);
            }
        }
        return minsteps;
      }
      // tc-0(n)*k & sc -0(n) + 0(n)

      // Memoization solution 
      int frogJump(int n,int k,vector<int> heights){
         if(n == 0) return 0;
         vector<int>dp(n+1,0);
         for(int i=1;i<n;i++){
            int minsteps = INT_MAX;
           for(int j =1;j<=k;j++){
               if(i-j>=0){
                int jump = dp[i-j] + abs(heights[n]-heights[n-j]);
                minsteps = min(minsteps,jump);
               }
            }
        return dp[i] = minsteps;
      }
    } 

    // space optimization 
    // by storing on  k element 


};
