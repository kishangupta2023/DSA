// Next Greater element (Monotonic stack)
// arr = [6,0,8,1,3]
// return [8,8,-1,3,-1]
#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int> nextGreaterElement(vector<int>& nums) {
        vector<int>nge;
       for(int i=0;i<nums.size();i++){
        for(int j = i+1;j<nums.size();j++){
            if(nums[j] > nums[i]){
                nge[i] = nums[j];
                break;
            }
        }
       }
       return nge;
    }
    //tc-0(n*n)
    //sc-0(n)

    vector<int>NGE(vector<int>&num){
        stack<int>st;
        int n = num.size();
        vector<int>nge(n);
        for(int i =n-1;i>=0;i++){
            while(!st.empty() && st.top() <= num[i]){
                st.pop();
            }
            nge[i] =st.empty() ? -1 : st.top();
            st.push(num[i]);
        }
        return nge;
    }
    //tc - 0(2n)
    //sc - 0(n) + 0(n)
};