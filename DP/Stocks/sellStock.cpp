// Best Time to BUy and Sell Stock | DP on Stocks 
// You are given an array/list 'prices' where the elements of the array represent the prices of the stock as they were yesterday and indices of the array represent minutes. Your task is to find and return the maximum profit you can make by buying and selling the stock. You can buy and sell the stock only once.z

#include<bits/stdc++.h>
using namespace std;

class Solution{
    int maximumProfit(vector<int> &prices){
        int mini = prices[0];
        int maxProfit = 0;
        int n = prices.size();
        for(int i=0;i<n;i++){
            int cost = prices[i] - mini;
            maxProfit = max(maxProfit,cost);
            mini = min(mini,prices[i]);
        }
        return maxProfit;
    }
};