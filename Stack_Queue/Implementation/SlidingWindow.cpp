// Sliding Window Maximum
//  You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
// Return the max sliding window.
// Example 1:
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]

#include<bits/stdc++.h>
using namespace std;

class Solution{
     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        if(nums.size() == 1){ans.push_back(nums[0]);
        return ans;
        }
        if(nums.size() == k){
            int maxi =0;
            for(int i=0;i<n;i++){
                maxi= max(maxi,nums[i]);
            }
            ans.push_back(maxi);
            return ans;
        }
        for(int i=0;i<=n-k;i++){
              int maxi = nums[i];
            for(int j =i;j<i+k;j++){
                maxi = max(maxi,nums[j]);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
    // tc -> 0((n-k)*k)

    // optimised Solution 
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans(n-k);
        deque<int> dq;
        for(int i=0;i<n;i++){
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
    // tc- 0(2N)
    // sc- 0(k) + 0(N-k)
};