// Longest Substring with At Most K Distinct Characters 

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int function(string s,int k){
        int n = s.size();
        int maxlen = 0;
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp.clear();
            for(int j=i;j<n;j++){
                mpp[s[j]]++;
                if(mpp.size() <= k){
                    maxlen = max(maxlen,j-i+1);
                }else{
                    break;
                }
            }
        }
        return maxlen;
    }
    //tc -> 0(n*n)
    // sc->0(256)

    int f(string s,int k){
        int maxlen =0;
        int l =0 ;
        int r = 0;
        unordered_map<char,int>mpp;
        int n = s.size();
        while(r <n){
            mpp[s[r]]++;
            while(mpp.size() > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            if(mpp.size() <= k){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
    }
    // tc -> 0(2N)
    // sc -> 0(256)

    // more optimised 
     int f(string s,int k){
        int maxlen =0;
        int l =0 ;
        int r = 0;
        unordered_map<char,int>mpp;
        int n = s.size();
        while(r <n){
            mpp[s[r]]++;
            if(mpp.size() > k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            if(mpp.size() <= k){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
    }
};