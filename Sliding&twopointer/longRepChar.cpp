// longest repeating character replacement
// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

// Example 1:

// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n =s.size();
        int maxlen = 0;
        for(int i=0;i<n;i++){
            int hash[26] = {0};
            int maxf = 0;
            for(int j=i;j<n;j++){
                hash[s[j]-'A']++;
                maxf = max(maxf,hash[s[j]-'A']);
                int changes = (j-i+1)-maxf;
                if(changes <= k){
                    maxlen= max(maxlen,j-i+1);
                }else{
                    break;
                }
            }
        }
        return maxlen;
    }
    // tc - 0(n*n)
    // sc -0(26)

    // optimised approach 
    int characterReplacement(string s, int k) {
        int n =s.size();
        int maxlen = 0;
        int hash[26] = {0};
        int l=0;
        int r =0;
        int maxf = 0;
        while(r < n){
            hash[s[r]-'A']++;
            maxf = max(hash[s[r]-'A'],maxf);
            while((r-l+1) -maxf > k){
                hash[s[l]-'A']--;
                maxf = 0;
                for(int i=0;i<26;i++){
                    maxf = max(maxf,hash[i]);
                }
                l++;
            }
            if((r-l+1)-maxf <= k){
                maxlen = max(maxlen,(r-l+1));
            }
            r++;
        }
        return maxlen;
    }
    // tc-> 0((2N)*26)
    // sc -> 0(26)


    // more optimsed
    int characterReplacement(string s, int k) {
        int n =s.size();
        int maxlen = 0;
        int hash[26] = {0};
        int l=0;
        int r =0;
        int maxf = 0;
        while(r < n){
            hash[s[r]-'A']++;
            maxf = max(hash[s[r]-'A'],maxf);
            if((r-l+1) -maxf > k){
                hash[s[l]-'A']--;
                l++;
            }
            if((r-l+1)-maxf <= k){
                maxlen = max(maxlen,(r-l+1));
            }
            r++;
        }
        return maxlen;
    }
    // tc -> 0(n)
    // sc -> 0(26)
};