//Count number of Nice subarray 
// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

// Example 1:

// Input: nums = [1,1,2,1,1], k = 3
// Output: 2
// Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int>&nums,int k){
        int l =0;
        int r= 0;
        int count =0;
        int countOdds =0;
        int n = nums.size();
        while(r<n){
            if(nums[r]%2 != 0) countOdds++;
            while(countOdds > k){
                if(nums[l]%2 != 0) countOdds--;
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return f(nums,k) - f(nums,k-1);
    }
};