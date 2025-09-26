// Binary subarray with sum
// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// A subarray is a contiguous part of the array.
// Example 1:
// Input: nums = [1,0,1,0,1], goal = 2
// Output: 4

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int maxlen = 0;
        for(int i=0;i<n;i++){
            int oneCount =0;
            for(int j=i;j<n;j++){
                if(nums[j] == 1) oneCount++;
                if(oneCount == goal){
                    maxlen++;
                }else if(oneCount > goal){
                    break;
                }
            }
        }
        return maxlen;
    }

    // optised approach 
    int f(vector<int>&nums,int goal){
        if(goal < 0) return 0;
        int n =nums.size();
        int l =0;
        int r =0;
        int sum =0;
        int cnt =0;
        while(r < n){
            sum += nums[r];
            while(sum > goal){
                sum = sum-nums[l];
                l++;
            }
            cnt +=(r-l+1);
            r++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return f(nums,goal) - f(nums,(goal-1));
    }
    // tc->0(4N) as 2 calls 
    // sc->0(1)

};

