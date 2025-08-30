// Longest bitonic Subsequence | LIS
// arr[] = {1,11,2,10,4,5,2,1} 
// bitonic = increasing then decreasing or it can just be increase or it can just be decrease
//lis is also a bitonic subsequence 
// ex1- 1,2,10,4,2,1
// ex2- 1,2,10,5,2,1
// ex3- 1,11,10,4,2,1
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int longestBitonicSubsequence(vector<int>&arr,int n){
        vector<int> dp1(n,1);
        for(int i =0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(arr[prev] < arr[i] && 1+dp1[prev]>dp1[i]){
                    dp1[i] = 1+ dp1[prev];
                }
            }
        }
        
        vector<int> dp2(n,1);
        for(int i =n-1;i>=0;i--){
            for(int prev = n-1;prev>i;prev--){
                if(arr[prev] < arr[i] && 1+ dp2[prev] >dp2[i]){
                    dp2[i] = 1+ dp2[prev];
                }
            }
        }
        
        int maxi = 0;
        for(int i =0;i<n;i++){
            maxi = max(maxi,dp1[i]+dp2[i]-1);
        }
        return maxi;
    }

    // tc->0(2*n*n)
};