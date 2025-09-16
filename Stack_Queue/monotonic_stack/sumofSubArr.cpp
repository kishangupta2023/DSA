// Sum of Subarray Ranges 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for(int i=0;i<n;i++){    
            int mini = nums[i];
            int maxi = nums[i];
            for(int j=i+1;j<n;j++){
                mini = min(mini,nums[j]);
                maxi = max(maxi,nums[j]);
                ans = ans + (maxi - mini);
            }
        }
        return ans;
    }
    // tc- 0(N*N)
    //sc-0(1)

    // optimsed way
    // next smaller element  
    vector<int> NSE(vector<int>& nums){
        int n =nums.size();
        stack<int>st;
        vector<int> nse(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            nse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return nse;
    }
    // privous smaller element 
    vector<int> PSE(vector<int>& nums){
        int n =nums.size();
        stack<int>st;
        vector<int> pse(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    // next greater element 
    vector<int> NGE(vector<int> & nums){
        int n = nums.size();
        vector<int>nge(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            nge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return nge;
    }
    // prev greater element
    vector<int> PGE(vector<int> & nums){
        int n = nums.size();
        vector<int>pge(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }

    long long sumofSubArrayMin(vector<int>&nums){
        int n = nums.size();
        vector<int>nse = NSE(nums);
        vector<int>pse = PSE(nums);
        long long total = 0;
        for(int i =0;i<n;i++){
            int left = i - pse[i];
            int right =( nse[i] == -1 ? n : nse[i]) - i;
            total = total + (left*right*1LL*nums[i]);
        }
        return total;
    }
    long long sumofSubArrayMax(vector<int>&nums){
        int n = nums.size();
        vector<int>nge = NGE(nums);
        vector<int>pge = PGE(nums);
        long long total =0;
        for(int i=0;i<n;i++){
            int left = i - pge[i];
            int right = (nge[i] == -1 ? n : nge[i])-i;
            total = total + (left*1LL*right*nums[i]);
        }
        return total;
    }
    long long subArrayRanges(vector<int>&nums){
        long long maxSum = sumofSubArrayMax(nums);
        long long minSum = sumofSubArrayMin(nums);
        return (maxSum - minSum);
    }
    //tc -0(5N) + 0(5N) == 0(10N) == 0(N)
    // sc -0(10N)
    
};