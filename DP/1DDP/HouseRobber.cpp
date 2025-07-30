//House Robber 
// Mr. X is a professional robber planning to rob houses along a street. Each house has a certain amount of money hidden. All houses along this street are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
// You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.
// Note:
// It is possible for Rr. X to rob the same amount of money by looting two different sets of bouans. Just print the maximum possible robbed amount, irrespective of lants of houses robbed.
// For Example:
// cht gives the input array Art (2,3, 2) the output will be 3 beacuase Mr X cannot rob house 1(money = 2),and then rob house 3 (money 2),beacusse they are adjacent houses. So he'll rob only house 2 (money =3) ;
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int maxSum(vector<int>&nums){
        int n = nums.size();
        int prev = nums[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1) take+=prev2;
            int nontake = 0+prev;
            int curi = max(take,nontake);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
    long long int houseRobber(vector<int> & valueInHouse){
        long long int n = valueInHouse.size();
        if(n == 1) return valueInHouse[0];
        vector<int> temp1,temp2;
        for(long long int i=0;i<n;i++){
            if(i != 0) temp1.push_back(valueInHouse[i]);
            if(i != n-1) temp2.push_back(valueInHouse[i]);
        }
        return max(maxSum(temp1),maxSum(temp2));
    }
};