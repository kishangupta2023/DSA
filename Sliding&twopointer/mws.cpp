// // Minimum Window Substring 
// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
// The testcases will be generated such that the answer is unique.
// Example 1:
// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int minlen = INT_MAX;
        int sIndex = -1;
        for(int i=0;i<n;i++){
            int hash[256] = {0};
            int cnt =0;
            for(int j=0;j<m;j++) hash[t[j]]++;
            for(int j=i;j<n;j++){
                if(hash[s[j]] > 0){
                    cnt++;
                    hash[s[j]]--;
                }
                if(cnt == m){
                    if(j-i+1 < minlen){
                        minlen = j-i+1;
                        sIndex = i;
                    }
                    break;
                }
            }
        }
        if(sIndex == -1) return "";
        return s.substr(sIndex,minlen); 
    }
    // tc -> 0(N*N)
    // sc -> 0(256)

    // optimised solution 
     string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int hash[256] = {0};
        int l =0;
        int r =0;
        int cnt =0;
        int minlen = INT_MAX;
        int sIndex =-1;
        for(int i=0;i<m;i++) hash[t[i]]++;
        while(r < n){
            if(hash[s[r]] > 0){
                cnt++;
            }
            hash[s[r]]--;
            while(cnt == m){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        if(sIndex == -1) return "";
        return s.substr(sIndex,minlen);
    }
    // tc -0(2N + M)
    // sc -0(256)
};
