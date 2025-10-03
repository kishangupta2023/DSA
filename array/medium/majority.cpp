// Majority Element 
// using algorithm Moore's Voting Algorithm
// Majority element (>n/2)
#include<bits/stdc++.h>
using namespace std;

class Solution{
    //bruteforce 
    int majority(vector<int>&nums){
        int n = nums.size();
        for(int i=0;i<n;i++){
            int cnt =0;
            for(int j=0;j<n;j++){
                if(nums[j] == nums[i]){
                    cnt++;
                }
            }
            if(cnt > n/2) return nums[i];
        }
    }
    // tc -> 0(N*N)

    // use hash mao and return the ans of which hash is greater thsn n/2
    // tc -> 0(NlogN)

    // Moore's Voting Algorithm 
    int majority(vector<int>&nums){
        int n =0;
        int count =0;
        int element =0;
        for(int i=0;i<n;i++){
            if(count ==0){
                element = nums[i];
                count = 1;
            }
            count += (nums[i] == element)? 1:-1;
        }
        return element;
    }

};