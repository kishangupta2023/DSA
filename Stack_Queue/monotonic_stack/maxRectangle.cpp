// Maximum Rectangle 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRectSum(vector<int>&num){
        int n = num.size();
        stack<int>st;
        int nse;
        int pse;
        int element;
        int maxSum =0;
        for(int i=0;i<n;i++){
            while(!st.empty() && num[st.top()] > num[i]){
                element = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                maxSum = max(maxSum,(nse-pse-1)*num[element]);
            }
            st.push(i);
        }
        while(!st.empty()){
            element = st.top();
            st.pop();
            nse = n;
            pse = st.empty() ? -1 : st.top();
            maxSum = max(maxSum,(nse-pse-1)*num[element]);
        }
        return maxSum;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>pSum(n,vector<int>(m));
        for(int j=0;j<m;j++){
            int sum =0;
            for(int i=0;i<n;i++){
                int val = matrix[i][j]-'0';
                sum+=val;
                if(val == 0) sum = 0;
                pSum[i][j] = sum;
            }
        }
        int maxSum =0;
        for(int i=0;i<n;i++){
            maxSum = max(maxSum,maxRectSum(pSum[i]));
        }
        return maxSum;

    }
};