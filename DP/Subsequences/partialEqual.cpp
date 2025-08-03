// Partial Equal Subset Sum 
// You are given an array 'ARR' of 'N' positive integers. Your task is to find if we can partition the given array into two subsets such that the sum of elements in both subsets is equal.
// For example, let's say the given array is [2. 3, 3, 3, 4, 5), then the array can be partitioned as [2, 3, 5], and [3, 3, 4] with equal sum 10.
// Follow Up:
// Can you solve this using not more than O(S) extra space, where 5 is the sum of all elements of the given array?

#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool subsetsumtoK(int n,int k,vector<int> &arr){
        vector<bool> prev(k+1,0),cur(k+1,0);
        for(int i=0;i<n;i++) prev[0] =cur[0] = true;
        prev[arr[0]] = true;
        for(int ind=1;ind<n;ind++){
            for(int target = 1;target<=k;target++){
                bool notTake = prev[target];
                bool take = false;
                if(arr[ind] <= target) take = prev[target-arr[ind]];
                cur[target] = take | notTake;
            }
            prev = cur;
        }
        return prev[k];
    }

    bool canPartition(vector<int> &arr,int n){
        int sum =0;
        for(int i=0;i<n;i++){
            sum += arr[i];
        }
        int target = sum /2;
        if(sum % 2)return false;
        return subsetsumtoK(n,target,arr);         
    }
    //tc->0(n)+old tc
};