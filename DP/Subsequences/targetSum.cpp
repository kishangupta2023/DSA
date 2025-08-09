//Target Sum 
// example ->
// arr[] -> [1,2,3,1] assign sign either + or - to get a given target target = 3
// + - + + = 3
// - + + - = 3
// so 2 ways  
//Divide the into 2 subsets S1-S2 =target 
// same code as previous 
#include<bits/stdc++.h>
using namespace std;

class Solution{
      int findWays(vector<int> &num,int tar){
        int n = num.size();
        vector<int>prev(tar+1,0),cur(tar+1,0);
        if(num[0] == 0) prev[0] = 2;
        else prev[0] =1;
        if(num[0] !=0 && num[0] <= tar) prev[num[0]] = 1;

        for(int ind=1;ind<n;ind++){
            for(int sum =0;sum<=tar;sum++){
                int notTake = prev[sum];
                int take = 0;
                if(num[ind] <=sum) take = prev[sum-num[ind]];

                cur[sum] = (notTake+take);
            }
            prev = cur;
        }
        return prev[tar];
    }

     int countPartitions(int n,int d,vector<int>&arr){
        int totSum =0;
        for(auto &it: arr) totSum+=it;
        if(totSum -d < 0 || (totSum -d) % 2) return false;
        return findWays(arr,(totSum-d)/2);
    }

    int targetSum(int n,int target,vector<int>&arr){
        return countPartitions(n,target,arr);
    }

};