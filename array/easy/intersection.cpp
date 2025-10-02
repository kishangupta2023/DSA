// intersection of two array if not sorted then u can sort  
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0;
        int j=0;
        int n = nums1.size();
        int m = nums2.size();
        vector<int>intersect;
        while(i<n && j < m){
            if(nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else{
                if(intersect.size() == 0 || intersect.back() != nums1[i] ){
                    intersect.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return intersect;
    }
};