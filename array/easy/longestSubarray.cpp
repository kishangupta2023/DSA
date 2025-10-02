// Longest subArray with sum k 
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int longSub(vector<int>nums,int k){
        int n = nums.size();
        int ans =0;
        for(int i=0;i<n;i++){
            int sum =0;
            for(int j=i;j<n;j++){
                sum += nums[i];
                if(sum == k){
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
    int longSub(vector<int>nums,long long k){
        int n = nums.size();
        map<long long,int>preSum;
        long long sum = 0;
        int maxlen = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(sum == k){
                maxlen = max(maxlen,i+1);
            }
            long long rem = sum -k;
            if(preSum.find(rem) != preSum.end()){
                int len = i-preSum[rem];
                maxlen = max(maxlen,len);
            }
            if(preSum.find(sum) == preSum.end()){
                 preSum[sum] = i;
            }
        }
        return maxlen;
    }
    // tc- > 0(N*logN) when used unordered when best case = 0(n*1) at worst case = 0(N*n)
    // sc -0(N)

    // optimal solution 
     int longSub(vector<int>nums,long long k){
        int n = nums.size();
        long long sum = nums[0];
        int maxlen = 0;
        int left = 0;
        int right =0;
        while(right < n){
            while(left <= right && sum > k){
                sum -= nums[left];
                left++;
            }
            if(sum == k){
                maxlen = max(maxlen,right-left+1);
            }
            right++;
            if(right < n) sum += nums[right];
        }
        return maxlen;
    }
    // tc -> 0(2N)
    // sc -> 0(1)
};