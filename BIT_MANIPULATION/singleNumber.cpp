// Single Number
// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.
// Example 1:
// Input: nums = [2,2,1]
// Output: 1
// Input: nums = [4,1,2,1,2]
// Output: 4


// use map and store the count and then traverse the element which appear ones 
//map<int,int>mpp
//for(int i=0;i<n;i++) mpp[nums[i]]++;
//for(auto it: mpp) if(it.value == 1) return it.first;
//tc->n*logm+0(m) where m = (n/2)+1
//sc-0(m)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// Xor = a^a = 0 
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int i=0;i<nums.size();i++){
            x = x^nums[i];
        }
        return x;
    }
    //tc -> 0(n)
    //sc->0(1)
};