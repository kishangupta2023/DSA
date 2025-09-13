// Sum of Subarray minimum 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int modulo = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n =arr.size();
        vector<vector<int>>result;
        for (int i = 0; i < n; i++) {
              vector<int> subarray;
            for (int j = i; j < n; j++) {
              subarray.push_back(arr[j]);   // keep growing the current subarray
              result.push_back(subarray);   // store its current version
        }
        }
        int ans =0;
        for(int i=0;i<result.size();i++){
            int mini = INT_MAX;
            for(int j=0;j<result[i].size();j++){
                mini = min(mini,result[i][j]);
            }
            ans += mini;
        }
        return ans%modulo;
    }

    // another bruteforce approach 
    int sumSubarrayMini(vector<int>& arr) {
        int n = arr.size();
        long long ans = 0; // use long long to avoid overflow

        for (int i = 0; i < n; i++) {
            int mini = INT_MAX;
            for (int j = i; j < n; j++) {
                mini = min(mini, arr[j]);  // update minimum as we expand subarray
                ans = (ans + mini) % modulo;
            }
        }
        return ans;
    }
    // it will give TLE 
    //tc-0(n*n)
    //sc-0(1)


    // optimized way 
    vector<int>NSE(vector<int>&num){
        stack<int>st;
        int n = num.size();
        vector<int>nse(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && num[st.top()]>= num[i]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i); 
        }
        return nse;
    }

    // previous Smaller element 
    vector<int> PSE(vector<int>&num){
        stack<int> st;
        int n = num.size();
        vector<int>pse(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && num[st.top()]>num[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
    // we are storing the indexes of the smaller element 

    int sumSubarrayMins(vector<int>& arr) {
       vector<int> nse = NSE(arr);
       vector<int> pse = PSE(arr);
        int total =0;
       for(int i=0;i<arr.size();i++){
        int left = i - pse[i];
        int right = nse[i] - i;
        total = (total + (left*right*1LL*arr[i])%modulo)%modulo;
       }
       return total;
    }
    //tc-0(5n)
    //sc-0(5n)
};