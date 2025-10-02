// Rotate Array by k times 
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
// Example 1:
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// bruteforce way 
   void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %=n;
        int temp[k];
        for(int i=0;i<k;i++){
            temp[i] = nums[i];
        }
        for(int i=k;i<n;i++){
            nums[i-k] = nums[i];
        }
        // int j=0;
        for(int i=n-k;i<n;i++){
            // nums[i] = temp[j];
            nums[i] = temp[i-(n-k)];
            // j++;
        }
    }
    // tc -0(N+k)
    // sc 0(K)

// optimsed way 
    vector<int>reverse(vector<int>&nums,int l,int r){
        while(l<r){
            int temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            // swap(nums[l],nums[r])
            l++;
            r--;
        }
        return nums;
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        reverse(nums,0,n-1);
        k %=n;
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
};