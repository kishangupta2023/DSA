// Union of two sorted array 

#include<bits/stdc++.h>
using namespace std;

class Solution{

    vector<int> findUnion(vector<int>&num1,vector<int>&num2){
        set<int>st;
        for(int i=0;i<num1.size();i++){
            st.insert(num1[i]);
        }
        for(int i=0;i<num2.size();i++){
            st.insert(num2[i]);
        }
        int n = st.size();
        vector<int>unions(n);
        int i=0;
        for(auto it: st){
            unions.push_back(it);
        }
        return unions;
    }
    // tc-> 0(N1logN) + 0(N2logN) + 0(N1+N2)
    // sc -0(n1+n2) +0(N1+N2)

    vector<int>findUnion(vector<int>&nums1,vector<int>&nums2){
        vector<int>unions;
        int i =0;
        int j =0;
        int n = nums1.size();
        int m = nums2.size();
        while(i < n && j < m){
            if(nums1[i] <= nums2[j]){
                if(unions.size() == 0 || unions.back() != nums1[i]){
                    unions.push_back(nums1[i]);
                }
                i++;
            }else{
                if(unions.size() == 0 || unions.back() != nums2[j]){
                    unions.push_back(nums2[j]);
                }
                j++;
            }
        }
        while(j< m){
            if(unions.size() == 0 || unions.back() != nums2[j]){
                    unions.push_back(nums2[j]);
                }
                j++;
        }
        while(i < n){
            if(unions.size() == 0 || unions.back() != nums1[i]){
                    unions.push_back(nums1[i]);
                }
                i++;
        }
        return unions;
    }
    // tc -> 0(n+m)
};
