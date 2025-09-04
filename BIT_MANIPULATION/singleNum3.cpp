//Single Number III 
// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

// we can do it hashing 
// store map<num,fre>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// bruteforce approach
    vector<int> singleNumber1(vector<int>& nums) {
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<int>ans;
        for (auto it:mpp){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
    // tc-0(nlogn)+0(m)
    //sc-0(m) for storing all the element in map m = (n/2)+1 
    
    // optimised way 
vector<int> singleNumber(vector<int>& nums) {
    long x = 0;
    for (int n : nums) {
        x ^= n;
    }
    // get rightmost set bit
    long rightmost = x & -x;

    int b1 = 0, b2 = 0;
    for (int n : nums) {
        if (n & rightmost) {
            b1 ^= n;
        } else {
            b2 ^= n;
        }
    }
    return {b1, b2};
}

    vector<int> singleNumber(vector<int>& nums) {
        long x =0;
        for(int i=0;i<nums.size();i++){
            x = x^nums[i];
        }
        // need a number to turn rightmost bit as 1
        long rightmost = (x&(x-1))^x; 
        //create two bucket ;
        int b1,b2;
        b1=b2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] & rightmost){
                b1 = b1^nums[i];
            }
            else{
                b2 = b2^nums[i];
            }
        }
        return {b1,b2};
    }
    // tc-0(2N)
    //sc-0(1)
};

 