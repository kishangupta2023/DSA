// Maximum Rectangle Area with all 1's 
// Given a m x n binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
// Examples
// Input: matrix = [[1, 0, 1, 0, 0], [1, 0, 1, 1, 1], [1, 1, 1, 1, 1], [1, 0, 0, 1, 0]]
// Output: 6
// Explanation: The highlighted part depicts the rectangle with the largest area i.e. 6.

// Input : matrix = [[1]] 
// Output: 1 
// Explanation: In this case, there is only one rectangle with area 1.

//before doing this u should know how to find the largest rectangle in histogram 


#include<bits/stdc++.h>
using namespace std;

class Solution{

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

    int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat,int n,int m){
       int maxArea = 0;
       vector<int> height(m,0);
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == 1) height[j]++;
            else height[j] = 0;
        }
        int area = largRectArea(height);
        maxArea = max(maxArea,area);
       }
       return maxArea;
    }
    // tc -> 0(n*(n+m));
    // sc--0(N)
};