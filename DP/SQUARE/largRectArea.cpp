// Largest Rectangle in histogram 
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
// 2 pass Solution 
    int largestRectangleArea(vector<int>&heights){
        int n = heights.size();
        stack<int> st;
        int leftSmall[n],rightSmall[n];
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) leftSmall[i] =0;
            else leftSmall[i] = st.top()+1;
            st.push(i);
        }

        // clear the stack to be re-used
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) rightSmall[i] =n-1;
            else rightSmall[i] = st.top()-1;
            st.push(i);
        }
        int maxA = 0;
        for(int i=0;i<n;i++){
            maxA = max(maxA,heights[i]*(rightSmall[i] -leftSmall[i]+1));
        }
        return maxA;
    }

    // 1 pass Solution
    int largRectArea(vector<int>&histo){
        stack<int> st;
        int maxA = 0;
        int n = histo.size();
        for(int i=0;i<=n;i++){
            while(!st.empty() && (i==n || histo[st.top()] >=histo[i])){
                int height = histo[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i -st.top()-1;
                maxA = max(maxA,width*height);
            }
            st.push(i);
        }
        return maxA;
    }
};

