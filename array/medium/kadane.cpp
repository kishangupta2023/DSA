// Kadane Algorithm , maximum subarray sum 
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int kadane(vector<int>&nums){
        int n = nums.size();
        int maxSum =nums[0];
        int currentSum = nums[0];
        for(int i=1;i<n;i++){
            currentSum = max(nums[i],currentSum+nums[i]);
            if(currentSum > maxSum){
                maxSum = currentSum;
            }
        }
        return maxSum;
    }
    // 0(n)

    // return the subarray 
    vector<int>kadanes(vector<int>&nums){
        int sum =0;
        int n = nums.size();
        int maxi = INT_MIN;
        int start =0;
        int ansStart = -1;
        int ansEnd = -1;
        for(int i=0;i<n;i++){
            if(sum == 0) start = i;
            sum = sum + nums[i];
            if(sum > maxi){
                maxi = sum;
                ansStart =start;
                ansEnd = i;
            }
            if(sum < 0){
                sum =0;
            }
        }
        vector<int>ans;
        for(int i=ansStart;i<=ansEnd;i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
    
    vector<int>kadanes(vector<int>&nums){
        int currentSum =nums[0];
        int n = nums.size();
        int maxSum = nums[0];
        int start =0;
        int tempStart = -1;
        int End = -1;
        for(int i=1;i<n;i++){
            if(nums[i]> currentSum + nums[i]){
                currentSum = nums[i];
                tempStart = i;
            }
            if(currentSum > maxSum){
                maxSum = currentSum;
                start = tempStart;
                End = i;
            }
        }
        vector<int>ans;
        for(int i=start;i<=End;i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};