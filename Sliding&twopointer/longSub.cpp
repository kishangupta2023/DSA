// Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest substring without duplicate characters.
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int n = s.size();
        int maxLength =0;
        for(int i=0;i<n;i++){
            mpp.clear();
            for(int j=i;j<n;j++){
                if(mpp[s[j]] == 1) break;
                mpp[s[j]] = 1;
                int len = j-i+1;
                maxLength= max(len,maxLength);
            }
        }
        return maxLength;
    }
    // tc-> n*n
    // sc ->0(256)

    int lengthOfLongSubstring(string s) {
        int hash[256];
        for(int i=0;i<256;i++) hash[i] = -1;
        int n = s.size();
        int l =0;
        int r = 0;
        int maxlength = 0;
        while (r < n){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= l){
                    l = hash[s[r]]+1;
                }
            }
            int len = r-l+1;
            maxlength = max(len,maxlength);
            hash[s[r]] = r;
            r++;
        }
        return maxlength;  
    }
    // tc-> 0(n)
    // sc-> 0(256)
};

 