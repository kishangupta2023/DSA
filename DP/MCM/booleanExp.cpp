//Evaluate Boolean expression to true 
// You are given a string expr consisting of the characters
// 'T' — represents true
// 'F' — represents false
// '&' — the logical AND operator
// '|' — the logical OR operator
// '^' — the logical XOR (exclusive-or) operator
// expr is guaranteed to follow the pattern operand operator operand operator … operand (i.e. it always starts and ends with an operand and no two operators are adjacent).
// Return the number of distinct ways to fully parenthesize expr such that the whole expression evaluates to true.
// Because the answer can be very large, return it modulo 1e9+7.

// Input: expr = "T|T&F^T"
// Output: 4
// Explanation:
// The expression can be parenthesized as follows (✓ marks variants that evaluate to true):
// 1. ((T|T)&(F^T)) ✓
// 2. (T|(T&(F^T))) ✓
// 3. (((T|T)&F)^T) ✓
// 4. (T|((T&F)^T)) ✓
// 5. ((T|(T&F))^T)   → false
// 6. (T|T)&F^T     → false
// Therefore 4 distinct parenthesizations evaluate to true.

//return the ans in modulo of 1000000007

#include<bits/stdc++.h>
// #define long long ll;
using namespace std;

class Solution{
    int mod = 1000000007;
    //Recursive SOlution
    long long f(int i,int j,int isTrue,string &exp){
        if(i>j) return 0;
        if(i==j){
            if(isTrue){
                return exp[i] == 'T';
            }
            else return exp[i] == 'F';
        }

        long long ways = 0;
        for(int ind =i+1;ind<j-1;j+=2){
            long long lT = f(i,ind-1,1,exp);
            long long lF = f(i,ind-1,0,exp);
            long long rT = f(ind+1,j,1,exp);
            long long rF = f(ind+1,j,0,exp);
            if(exp[ind] == '&'){
                if(isTrue) ways = (ways + (rT*lT)%mod)%mod;
                else{
                    ways = (ways +(rT*lF)%mod +(lT*rF)%mod + (rF*lF)%mod)%mod;
                }
            }
            else if(exp[ind] == '|'){
                if(isTrue){
                    ways = (ways + (lT*rT)%mod +(lT*rF)%mod + (lF*rT)%mod)%mod;
                }
                else{
                    ways = (ways + (rF*lF)%mod)%mod;
                }
            }
            else{
                if(isTrue){
                    ways = (ways +(rT*lF)%mod + (rF*lT)%mod)%mod;
                }
                else{
                    // T^T =F , T^F = T , F^T = T,F^F = F
                    ways = (ways + (rT*lT)%mod + (rF*lF)%mod)%mod;
                }
            }
        }
        return ways;
    }
    //tc- exponential 

    //Memoization Solution 
    long long f(int i,int j,int isTrue,string &exp,vector<vector<vector<long long>>>&dp){
        if(i>j) return 0;
        if(i==j){
            if(isTrue){
                return exp[i] == 'T';
            }
            else return exp[i] == 'F';
        }
        if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
        long long ways = 0;
        for(int ind =i+1;ind<j-1;ind+=2){
            long long lT = f(i,ind-1,1,exp,dp);
            long long lF = f(i,ind-1,0,exp,dp);
            long long rT = f(ind+1,j,1,exp,dp);
            long long rF = f(ind+1,j,0,exp,dp);
            if(exp[ind] == '&'){
                if(isTrue) ways = (ways + (rT*lT)%mod)%mod;
                else{
                    ways = (ways +(rT*lF)%mod +(lT*rF)%mod + (rF*lF)%mod)%mod;
                }
            }
            else if(exp[ind] == '|'){
                if(isTrue){
                    ways = (ways + (lT*rT)%mod +(lT*rF)%mod + (lF*rT)%mod)%mod;
                }
                else{
                    ways = (ways + (rF*lF)%mod)%mod;
                }
            }
            else{
                if(isTrue){
                    ways = (ways +(rT*lF)%mod + (rF*lT)%mod)%mod;
                }
                else{
                    // T^T =F , T^F = T , F^T = T,F^F = F
                    ways = (ways + (rT*lT)%mod + (rF*lF)%mod)%mod;
                }
            }
        }
        return dp[i][j][isTrue] = ways;
    }
    // tc-0(N*N*2)*N == N*N*N
    // sc-0(N*N*2) + stack space 

    int evaluateExp(string &exp){
        int n = exp.size();
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(n,vector<long long>(2,-1)));
        return f(0,n-1,1,exp,dp);
    }


    //Tabulation SOlution 
   int evaluateExp(string &exp) {
    int n = exp.size();
    
    // 3D DP: dp[i][j][0] -> ways to make substring False
    //        dp[i][j][1] -> ways to make substring True
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, 0)));

    // Base cases: single character
    for (int i = 0; i < n; i++) {
        if (exp[i] == 'T') {
            dp[i][i][1] = 1;
            dp[i][i][0] = 0;
        } else if (exp[i] == 'F') {
            dp[i][i][0] = 1;
            dp[i][i][1] = 0;
        }
    }

    // Length of substring
    for (int len = 3; len <= n; len += 2) { // must include at least "T op T"
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            dp[i][j][0] = dp[i][j][1] = 0; // initialize

            for (int ind = i + 1; ind <= j - 1; ind += 2) {
                long long lT = dp[i][ind - 1][1];
                long long lF = dp[i][ind - 1][0];
                long long rT = dp[ind + 1][j][1];
                long long rF = dp[ind + 1][j][0];

                if (exp[ind] == '&') {
                    dp[i][j][1] = (dp[i][j][1] + (lT * rT) % mod) % mod;
                    dp[i][j][0] = (dp[i][j][0] + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
                }
                else if (exp[ind] == '|') {
                    dp[i][j][1] = (dp[i][j][1] + (lT * rT) % mod + (lT * rF) % mod + (lF * rT) % mod) % mod;
                    dp[i][j][0] = (dp[i][j][0] + (lF * rF) % mod) % mod;
                }
                else if (exp[ind] == '^') {
                    dp[i][j][1] = (dp[i][j][1] + (lT * rF) % mod + (lF * rT) % mod) % mod;
                    dp[i][j][0] = (dp[i][j][0] + (lT * rT) % mod + (lF * rF) % mod) % mod;
                }
            }
        }
    }

    return dp[0][n - 1][1]; // number of ways to make whole exp = True
}
};