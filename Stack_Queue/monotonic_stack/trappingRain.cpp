// Trapping rainwater 
// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int prefixMax[n];
        int suffixMax[n];
        prefixMax[0] = height[0];
        for(int i=1;i<n;i++){
            prefixMax[i] = max(prefixMax[i-1],height[i]);
        }
        suffixMax[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            suffixMax[i] = max(suffixMax[i+1],height[i]);
        }
        int total = 0;
        int leftmost;
        int rightmost;
        for(int i=0;i<n;i++){
            leftmost = prefixMax[i];
            rightmost = suffixMax[i];
            if(leftmost > height[i] && rightmost >height[i]){
                total += min(leftmost,rightmost) - height[i];
            }
        }
        return total;
    }
    // tc- o(2n)+ 0(n) = 0(3n)
    // sc-0(2n)

    // optimised way 
    
    int trap1(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int leftmax =0;
        int rightmax = 0;
        int total = 0;
        while(l < r){
            if(height[l] <= height[r]){
                if(leftmax > height[l]){
                    total += leftmax - height[l];
                }else{
                    leftmax = height[l];
                }
                    l++;
            }
            else{
                if(rightmax > height[r]){
                    total += rightmax - height[r];
                }
                else{
                    rightmax = height[r];
                }
                    r--;
            }
        }
        return total;
    }
    //tc- 0(n)
    //sc-0(1)
};

