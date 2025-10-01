// intersection of two sorted arrays 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// bruteforce appoach 
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
        int n1 = nums1.size();
        int n2 = nums2.size();
        int vis[n2] = {0};
        vector<int>ans;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i] == nums2[j] && vis[j] ==0){
                    ans.push_back(nums1[i]);
                    vis[j] = 1;
                    break;
                }
                if(nums2[j] > nums1[i]) break;
            }
        }
        return ans;
    }
    // tc -> 0(N1*N2)
    // sc -> 0(N2)

    
// optimised approach 
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
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
                if(intersect.size() == 0 ){
                    intersect.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return intersect;
    }
};