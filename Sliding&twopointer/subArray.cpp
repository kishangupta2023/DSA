// Subarray with k different integers
// Given an integer array nums and an integer k, return the number of good subarrays of nums.

// A good array is an array where the number of different integers in that array is exactly k.

// For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
// A subarray is a contiguous part of an array.

 

// Example 1:

// Input: nums = [1,2,1,2,3], k = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  // bruteforce approach 
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int maxlen =0;
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp.clear();
            for(int j=i;j<n;j++){
                mpp[nums[j]]++;
                if(mpp.size() == k){
                    maxlen++;
                }
                else if(mpp.size() < k) continue;
                else{
                    break;
                }
            }
        }
        return maxlen;
    }
    // tc -> 0(N*N)
    // sc -> 0(N)

    // optimsed way 
    int f(vector<int>& nums,int k){
         if(k == -1) return 0;
        int n = nums.size();
        int total=0;
        int l=0;
        int r=0;
        unordered_map<int,int>mpp;
        while(r < n){
            mpp[nums[r]]++;
            while(mpp.size() > k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            total += (r-l+1);
            r++;
        }
        return total;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums,k) - f(nums,k-1);
    }
    // tc -0(4N)
    // sc - 0(2N)
};