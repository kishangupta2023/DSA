// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
// Example 1:
// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

// convert it as largest subarray with max k zeros 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLength = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int zeros = 0;
            for(int j=i;j<n;j++){
                if(nums[j] == 0) zeros++;
                if(zeros <= k){
                    int len = j-i+1;
                    maxLength = max(len,maxLength);
                }else{
                    break;
                }
            }
        }
        return maxLength;
    }
    // tc ->0(N*N) approx
    // sc->0(1)

    int longestOne(vector<int>&nums,int k){
        int maxLength = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        int zeros = 0;
        while(r < n){
            if(nums[r] == 0) zeros++;
            while(zeros > k){
                if(nums[l] == 0) zeros--;
                l++;
            }
            if(zeros <=k){
                int len = r-l+1;
                maxLength = max(len,maxLength);
            }
            r++;
        }
        return maxLength;
    }
    // tc-> 0(N)+0(N) = 0(2N)
    // sc-> 0(1)

    // most optimal Solution 
    int longestones(vector<int>& nums,int k){
        int maxLength = 0;
        int l = 0;
        int r = 0;
        int n = nums.size();
        int zeros = 0;
        while(r < n){
            if(nums[r] == 0) zeros++;
            if(zeros > k){
                if(nums[l] == 0) zeros--;
                l++;
            }
            if(zeros<=k){
                int len = r-l+1;
                maxLength = max(maxLength,len);
            }
            r++;
        }
        return maxLength;
    }
    // tc-> 0(N)
    // sc->0(1)
};
