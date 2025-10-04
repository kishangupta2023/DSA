// Rearrange Array Elements by Sign 
// if any of the positive and negativ numbers are left, add them at the end without altering the order . 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n =nums.size();
        vector<int>pos;
        vector<int>neg;
        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                pos.push_back(nums[i]);
            }else{
                neg.push_back(nums[i]);
            }
        }
        int minsize = min(pos.size(),neg.size());
        for(int i=0;i<minsize;i++){
            nums[i*2] = pos[i];
            nums[i*2+1] = neg[i];
        }
        int index = minsize*2;
        for(int i=minsize;i<n;i++){
            if(pos.size() > neg.size()){
                nums[index] = pos[i];
                index++;
            }else{
                nums[index] = neg[i];
                index++;
            }
        }
        
        
    }
};
