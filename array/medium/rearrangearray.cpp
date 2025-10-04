// Rearrange Array Elements by Sign 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n =nums.size();
        int j=0;
        int k=1;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(nums[i] >= 0){
                ans[j] = nums[i];
                j+=2;
            }
            else{
                ans[k] = nums[i];
                k+=2;
            }
        }
        return ans;
    }
    // tc -> 0(N)
    // sc -> 0(N)
    


};