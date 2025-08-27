// Longest Increasing Subsequence using Binary search 
// we can fid the length easily 
// replacing the number in the same array can give u the max length
// lower_Bound -> gives the index of arr[i] or the first index > arr[i] 
#include<Bits/stdc++.h>
using namespace std;

class Solution{
    int longestIncreasingSubsequence(int arr[],int n){
        vector<int> temp;
        temp.push_back(arr[0]);
        int len = 1;
        for(int i=1;i<n;i++){
            if(arr[i]>temp.back()){
                temp.push_back(arr[i]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),arr[i]) - temp.begin();
                temp[ind] = arr[ind];
            }
        }
        return len;
    }
    // tc -> 0(n*logn)
    // sc-0(n)


};