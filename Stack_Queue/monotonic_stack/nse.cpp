// next smaller element 
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int>NSE(vector<int>&num){
        stack<int>st;
        int n = num.size();
        vector<int>nse(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() >= num[i]){
                st.pop();
            }
            if(!st.empty()) {
                nse[i] = st.top();
            }
            st.push(num[i]); 
        }
        return nse;
    }

    // previous Smaller element 
    vector<int> PSE(vector<int>&num){
        stack<int> st;
        int n = num.size();
        vector<int>pse(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top() >=num[i]){
                st.pop();
            }
            if(!st.empty()){
                pse[i] = st.top();
            }
            st.push(num[i]);
        }
        return pse;
    }
};