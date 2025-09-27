// Number of Substrings Containing All Three Characters

// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c.
// Example 1:
// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int total =0;
        for(int i=0;i<n;i++){
            int hash[3] = {0};
            for(int j=i;j<n;j++){
                hash[s[j]-'a'] = 1;
                if(hash[0]+hash[1]+hash[2] == 3){
                    total = total + (n-j);
                    break;
                }
            }
        }
        return total;
    }
    // tc -> 0(N*N)
    // sc -> 0(1)

    // optimsed solution 
    
    int numberOfSubstrings(string s) {
        int n = s.size();
        int total =0;
        int hash[3] = {-1,-1,-1};
        for(int i=0;i<n;i++){
            hash[s[i]-'a'] = i;
            if(hash[0] != -1 && hash[1] != -1 && hash[2] != -1){
                total = total + (1 + min(hash[0],min(hash[1],hash[2])));
            }
        }
        return total;
    }
    // tc ->0(N)
    // sc -0(1)
};

