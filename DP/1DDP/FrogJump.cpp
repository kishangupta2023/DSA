// Frog Jump 
// There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair.
// HEIGHT[i] is the height of the (i+1)th stair.lf Frog jumps from ith to ith stair, the energy lost in the jump is given by |HEIGHT[i-1]-HEIGHT[j-1] [In the Frog is on ith staircase, he can jump either to (th stair or to (i+2)th stair. Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nith stair.
// For Example
// If the given HEIGHT array in (10,20,30,10), the answer 20 as the frog can jump from ist stair to 2nd stalt (120-10-10rgy lost and then a jump from 2nd stale ta Last stair (115-2010 energy losti Sn, the total wargy Inst is 20.
// Input Format:
// The first line of the input containe an inseperting the number of teat cases.
// The Fient Line of each teat care consigle integer, denoting the number of stairs in the staircase,
// The rest Line connaLAS BELT ALTAY

#include<bits/stdc++.h>
using namespace std;

int recway(int n,vector<int> &heights){
    if(n == 0) return 0;
    int left = recway(n-1,heights) + abs(heights[n]-heights[n-1]);
    int right = INT_MAX;
    if(n > 1){
         right = recway(n-2,heights) + abs(heights[n]-heights[n-2]);
    }
    return min(left,right);
}
// Memoization 
class Solution{
    private:
    int f(int ind,vector<int> &heights,vector<int> &dp){
        if( ind == 0) return 0;
        if(dp[ind] != -1) return dp[ind];
        int left =f(ind-1,heights,dp) + abs(heights[ind]-heights[ind-1]) ;
        int right = INT_MAX;
        if(ind > 1) right =f(ind-2,heights,dp) + abs(heights[ind]-heights[ind-2]);
        return dp[ind] = min(left,right);
    }
    public:
    int frogJump(int n,vector<int> &heights){
        vector<int> dp(n+1,-1);
        return f(n-1,heights,dp);

    }
};
// Tabulation form of solution 
int frogjump(int n,vector<int> heights){
    vector<int> dp(n,0);
    dp[0] =0;
    for(int i=1;i<n;i++){
        int fs = dp[i-1] + abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if(i>1){
            ss = dp[i-2] + abs(heights[i]-heights[i-2]);
        }
        dp[i] = min(fs,ss);
        return dp[n-1];
    }
}

// space optimization way 
int frogJUmp(int n,vector<int> heights){
    int prev =0;
    int prev2 = 0;
    for(int i=1;i<n;i++){
        int fs = prev + abs(heights[i]-heights[i-1]);
        int ss = INT_MAX;
        if(i>1){
            ss = prev2 + abs(heights[i]-heights[i-2]);
        }
        int curi = min(fs,ss);
        prev2 = prev;
        prev = curi;
    }
    return prev;

}


