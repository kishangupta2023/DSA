// Best time to buy and sell stock 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProfit = 0;
        int n = prices.size();
        for(int i=1;i<n;i++){
            maxProfit = max(maxProfit,prices[i]-mini);
            mini = min(mini,prices[i]);
        }
        return maxProfit;
    }
    // tc -0(N)
    
};