// Largest Rectangle in the histogram 

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> prefixMax(n), suffixMax(n);

        // PrefixMax: nearest smaller to left
        prefixMax[0] = -1; // No smaller to the left of first element
        for (int i = 1; i < n; i++) {
            int prev = i - 1;
            // Jump back using prefixMax until we find a smaller element
            while (prev >= 0 && heights[prev] >= heights[i]) {
                prev = prefixMax[prev];
            }
            prefixMax[i] = prev;
        }

        // SuffixMax: nearest smaller to right
        suffixMax[n - 1] = n; // No smaller to the right of last element
        for (int i = n - 2; i >= 0; i--) {
            int next = i + 1;
            // Jump forward using suffixMax until we find a smaller element
            while (next < n && heights[next] >= heights[i]) {
                next = suffixMax[next];
            }
            suffixMax[i] = next;
        }

        // Compute max area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = suffixMax[i] - prefixMax[i] - 1;
            maxArea = max(maxArea, width * heights[i]);
        }

        return maxArea;
    }

    vector<int> NSE(vector<int>&num){
        int n = num.size();
        stack<int>st;
        vector<int>ans(n);
        ans[n-1] = n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && num[st.top()] >= num[i]){
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>PSE(vector<int>&num){
        int n =num.size();
        stack<int>st;
        vector<int>ans(n);
        ans[0] = -1;
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && num[st.top()] >= num[i]){
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectArea(vector<int>&heights){
        int n = heights.size();
        vector<int>pse(n);
        pse = PSE(heights);
        vector<int>nse(n);
        nse = NSE(heights); 
        int total = 0;
        for(int i=0;i<n;i++){
            int width = nse[i] - pse[i] -1;
            total = max(total,width*heights[i]);
        }
        return total;
    }
    // tc-0(4N)+0(N) = 0(5N)
    // sc-0(4N)

    // optimesed solution 
    int largestRectangleArea(vector<int>&heights){
        stack<int>st;
        int n =heights.size();
        int nse,pse;
        int element =0;
        int maxArea =0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                element = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top(); 
                maxArea = max(heights[element]*(nse-pse-1),maxArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            nse = n;
            element = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea,(nse-pse-1)*heights[element]);
        }
        return maxArea;
    }
    // tc -> 0(2N)
    // sc -> 0(N)
};
