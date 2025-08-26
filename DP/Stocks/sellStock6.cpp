// Buy And Sell Stocks With Transaction Fee 

#include<bits/stdc++.h>
using namespace std;

class Solution {
    

    //space optimzation 
    int getMaximumProfit(int n,int fee,vector<int>&values){
        vector<long>prev(2,0),cur(2,0);
        prev[0] =prev[1] = 0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy =0;buy<2;buy++){
                int profit = 0;
                if(buy){
                    profit = max(-values[ind]+prev[0],0 + prev[1]);
                }
                else{
                    profit = max(values[ind]-fee +prev[1],0+prev[0]);
                }
                cur[buy] = profit;
            }
            prev = cur;
        }
        return prev[1];
    }

    // space optimzation with some variable
    int getMaximumProfit(int n,int fee,vector<int>&values){
        int curBuy,curNotBuy;
        int aheadNotBuy=0;
        int aheadBuy = 0;

        for(int ind=n-1;ind>=0;ind--){

            //sell
             curNotBuy = max(values[ind]-fee+aheadBuy,0+aheadNotBuy);
             //buy
             curBuy = max(-values[ind]+aheadNotBuy,0 + aheadBuy);  
            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;
    }
};