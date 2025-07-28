// Count Ways To reach The N-th Stairs
// you have been given a number of stairs. initially you are at 0th stairs and you need to reach the Nth stair. Each time you can either climbs one step or two steps .
//you are supposed to return the number of distinct ways in which you can climb from the 0th step to Nth step
#include<bits/stdc++.h>
using namespace std;
int reccursiveway(int n){
    if(n == 0 || n == 1) return 1;
    int left = reccursiveway(n-1);
    int right = reccursiveway(n-2);
    return left + right;
}
int countWays(int n) {
    if (n == 0 || n == 1) return 1;

    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int countWays2(int n) {
    if (n == 0 || n == 1) return 1;
    int prev2 = 1, prev1 = 1, curr;
    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}
class Solution{
    int countDistinctWaysToClimbStairs(long long n){
        if (n == 0 || n == 1) return 1;

    long long prev1 = 1;  // ways to reach step 1
    long long prev2 = 1;  // ways to reach step 0
    long long curr;

    for (long long i = 2; i <= n; ++i) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
    }
};
int main(){
    int n;
    cin>>n;
    cout<<reccursiveway(n)<<endl;
}