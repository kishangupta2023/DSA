// Palindrome Partition II 
// Given a string s, partition s such that every substring of the partition is a palindrome.Return the minimum cuts needed for a palindrome partitioning of s.
// Examples:
// Input : s = "aab"
// Output : 1
// Explanation : The palindrome partitioning ["aa", "b"] could be produced using 1 cut.
// Input : s = "abaaba"
// Output : 0
// Explanation : The complete string can be considered as a partition as the string itself is palindrome.
// There are other ways to partition the string but it requires more number of cuts.

// Solved using front partition

#include<bits/stdc++.h>
using namespace std;

class Solution {
    //Recursion Solution

    bool isPalindrome(int i,int j,string s){
        while(i<j){
            if(s[i] !=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int f(int i,int n,string &str){
        if(i == n) return 0;
        int minCost = INT_MAX;

        //i...j
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,str)){
            int cost = 1 + f(j+1,n,str);
            minCost = min(cost,minCost);
            }
        }
        return minCost;
    }
    //tc- exponential 

    // Memoization Solution 
    int f(int i,int n,string &str,vector<int> &dp){
        if(i == n) return 0;
        int minCost = INT_MAX;

        if(dp[i] != -1) return dp[i];
        //i...j
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,str)){
            int cost = 1 + f(j+1,n,str,dp);
            minCost = min(cost,minCost);
            }
        }
        return dp[i] = minCost;
    }
    // tc- 0(N*N)
    //sc-0(N) +0(N)

    int palindromePartitioning(string str){
        int n = str.size();
        vector<int> dp(n,-1);
        return f(0,n,str,dp)-1;
    }

    // Tabulation Solution
    int palindromePartitioning(string str){
        int n = str.size();
        vector<int> dp(n+1,0);
        dp[n] = 0;
        for(int i =n-1;i>=0;i--){
            int minCost = INT_MAX;
            for(int j=i;j<n;j++){
               if(isPalindrome(i,j,str)){
                int cost = 1 + dp[j+1];
                 minCost = min(cost,minCost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0]-1;
    }


};