// Remove duplicates in-place from sorted array 

#include<bits/stdc++.h>
using namespace std;

class Solution{
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        int n =nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int index =0;
        for(auto it:st){
            nums[index] = it;
            index++;
        }
        return index++;
    }
    // tc -> 0(Nlog(N)) + 0(N)
    // sc -> 0(N)


    // two pointer apporach;
    int removeDup(vector<int>&nums){
        int n = nums.size();
        int i=0;
        for(int j =1;j<n;j++){
            if(nums[j] != nums[i]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
    // tc -> 0(N)
    // sc -> 0(1)
};