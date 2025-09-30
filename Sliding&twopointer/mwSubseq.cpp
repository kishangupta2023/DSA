// ﻿Given strings s1 and s2, return the minimum contiguous substring part of s1, so that s2 is a subsequence of the part.

// If there is no such window in s1 that covers all characters in s2, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int minLen = INT_MAX, start = -1;

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[0]) continue; // potential start

            int j = i, k = 0;
            // try to match subsequence
            while (j < n && k < m) {
                if (s1[j] == s2[k]) k++;
                j++;
            }

            if (k == m) { // subsequence matched
                int end = j - 1;
                // shrink from left
                k = m - 1;
                while (end >= i) {
                    if (s1[end] == s2[k]) k--;
                    if (k < 0) break;
                    end--;
                }
                if (end - i + 1 < minLen) {
                    minLen = end - i + 1;
                    start = i;
                }
            }
        }

        return (start == -1) ? "" : s1.substr(start, minLen);
    }

    string minWindow(string s1,string s2){
        int n = s1.size();
        int m = s2.size();
        int start = -1;
        int minlen = INT_MAX;
        int i=0;
        while(i < n){
            int j=0;
            while(i < n){
                if(s1[i] == s2[j]) j++;
                if(j > m) break;
                i++;
            }
            if(j < m) break; 

            int end =i;
            j = m-1;
            while(i >=0){
                if(s1[i] == s2[j]) {
                    j--;
                    if(j <0) break;
                }
                i--;
            }
            int sIndex = i;

            if(end -sIndex+1 < minlen){
                minlen = end-sIndex+1;
                start;
            }
            i = sIndex+1;

            return (start == -1)? "":s1.substr(start,minlen);
        }
    }
};
