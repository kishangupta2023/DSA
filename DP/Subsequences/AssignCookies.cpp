// Assign Cookies | Greedy Algorithm 
// greed = [1,5,3,3,4]  s = [4,2,1,2,1,3]
#include<bits/stdc++.h>
using namespace std;
class Solution{
    int f(vector<int>&greed,vector<int>&s){
        int n = greed.size();
        int m = s.size();
        int l =0;
        int r =0;
        sort(greed.begin(),greed.end());
        sort(s.begin(),s.end());
        while(l<m){
            if(greed[r] <= s[l]){
                r = r+1;
            } 
            l = l+1;
        }
        return r;
    }
    //tc -> nlogn + mlogm + M
    // sc-> o(1)
};