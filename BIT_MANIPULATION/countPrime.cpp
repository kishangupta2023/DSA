// Given an integer n, return the number of prime numbers that are strictly less than n.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }
        return count;
    }
    // ***** Sieve of Eratosthenes 
    // print all number which are prime till n
    vector<int> PrintPrimes(int n){
        if (n <= 2) return {0};

        vector<bool> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int>arr;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) arr.push_back(i);
        }
        return arr;
    }
};
