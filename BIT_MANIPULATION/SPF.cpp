//Smallest Prime Factor(SPF) | Prime Factorization
// You are given an integer array queries of length n.

// Return the prime factorization of each number in array queries in sorted order.

// Examples:
// Input : queries = [2, 3, 4, 5, 6]

// Output : [ [2], [3], [2, 2], [5], [2, 3] ]

// Explanation : The values 2, 3, 5 are itself prime numbers.
// The prime factorization of 4 will be --> 2 * 2.
// The prime factorization of 6 will be --> 2 * 3.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> primeFactors(vector<int>& queries) {
        int MAXN = 1e5;   // sieve limit
        vector<int> spf(MAXN+1);

        // Initialize smallest prime factor (SPF)
        for(int i=1; i<=MAXN; i++) spf[i] = i;

        // Sieve to fill SPF
        for(int i=2; i*i<=MAXN; i++){
            if(spf[i] == i){   // i is prime
                for(int j=i*i; j<=MAXN; j+=i){
                    if(spf[j] == j) spf[j] = i;
                }
            }
        }

        vector<vector<int>> result;

        // Process each query
        for(int x : queries){
            vector<int> factors;
            while(x != 1){
                factors.push_back(spf[x]);
                x /= spf[x];
            }
            sort(factors.begin(), factors.end());
            result.push_back(factors);
        }

        return result;
    }
};
