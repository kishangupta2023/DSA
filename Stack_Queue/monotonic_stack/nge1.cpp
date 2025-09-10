// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
// Example 1:
// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        int n = nums2.size();
        unordered_map<int,int>mpp;
        for(int i= n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()) mpp[nums2[i]] = -1;
            else mpp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int x:nums1){
            ans.push_back(mpp[x]);
        }
        return ans;
    }
};
