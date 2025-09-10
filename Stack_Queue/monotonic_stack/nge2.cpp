// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.
// Example 1:
// Input: nums = [1,2,1]
// Output: [2,-1,2]
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>nge;
        int n= nums.size();
        for(int i=0;i<n;i++){
            int next = -1;
            for(int j=i+1;j<=i+n-1;j++){
                if(nums[j%n] > nums[i]){
                    next = nums[j%n];
                    break;
                }
            }
            nge.push_back(next);
        }
        return nge;
    }
    //tc-0(N*N)
    //sc-0(n)

    // optimized solution 
    vector<int> nge2(vector<int>&nums){
        int n = nums.size();
        vector<int>nge(n);
        stack<int>st;
        for(int i =2*n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            if(i < n){
                nge[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i%n]);
        }
        return nge;
    }
    //tc- 0(4n)
    // sc -0(2n)+0(n)
};