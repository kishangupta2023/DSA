// Remove K digits 
// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
// Example 1:
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() <= k) return "0";
        stack<char> st;

        for (char c : num) {
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // Remove extra digits if k > 0
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build the result string
        string res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());

        // Remove leading zeros
        int idx = 0;
        while (idx < res.size() && res[idx] == '0') idx++;
        res = res.substr(idx);

        return res.empty() ? "0" : res;
    }
    // tc-0(3N)+0(K)
    // sc-0(2N)
};
