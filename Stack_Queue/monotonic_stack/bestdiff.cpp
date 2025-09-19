// Given two integers n and k, split the number n into exactly k positive integers such that the product of these integers is equal to n.

// Return any one split in which the maximum difference between any two numbers is minimized. You may return the result in any order.
// Input: n = 44, k = 3
// Output: [2,2,11]

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> best;
    int bestDiff = INT_MAX;

    vector<int> minDifference(int n, int k) {
        vector<int> curr;
        backtrack(n, k, 1, curr);
        return best;
    }

    void backtrack(int n, int k, int start, vector<int>& curr) {
        if (k == 1) {
            if (n >= start) {
                curr.push_back(n);
                check(curr);
                curr.pop_back();
            }
            return;
        }

        for (int i = start; i <= n; i++) {
            if (n % i == 0) {
                curr.push_back(i);
                backtrack(n / i, k - 1, i, curr);
                curr.pop_back();
            }
        }
    }

    void check(vector<int>& curr) {
        int mn = *min_element(curr.begin(), curr.end());
        int mx = *max_element(curr.begin(), curr.end());
        if (mx - mn < bestDiff) {
            bestDiff = mx - mn;
            best = curr;
        }
    }
};