// move all zeros to the end of the array  
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i] == 0){
                swap(nums[i],nums[i+1]);
            }
        }
    }
    void moveZeros(vector<int>& nums){
        int n = nums.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            if(nums[i] != 0){
                temp.push_back(nums[i]);
            }
        }
        for(int i=0;i<temp.size();i++){
            nums[i] = temp[i];
        }
        for(int i=temp.size();i<n;i++){
            nums[i] = 0;
        }
    }
    // tc -> 0(N)+0(N) == 0(2N)
    // sc -> 0(N)

    void moveZeros(vector<int>&nums){
        //  int n = nums.size();
        // int i =0;
        // for(int j=0;j<n;j++){
        //     if(nums[j] != 0){
        //         swap(nums[i],nums[j]);
        //         i++;
        //     }
        // }
        int n = nums.size();
        int j = -1;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }
        for(int i=j+1;i<n;i++){
            if(nums[i] !=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
    // tc -> 0(N)
    // sc -> 0(1)
};