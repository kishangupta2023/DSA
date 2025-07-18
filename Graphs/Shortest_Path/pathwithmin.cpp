// path with minimum effort 
// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights [row][col] represents the height of cell (row, col) You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-Indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
// Example 1:
// heights [[1,2,2],[3,8,2], [5,3,5]]
// Output: 2
// Explaination. The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells. This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function Minimum Effort() which takes the array height and Returns the minimum effort required to travel from the top-left cell to the bottom-right cell

#include<bits/stdc++.h>
using namespace std; 
class Solution {
    int MinimumEffort(vector<vector<int>> & heights){
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        pq.push({0,{0,0}});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n-1 && col == m-1) return diff;
            for(int i=0;i<4;i++){
                int nrow = row+drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow <n && ncol >=0 && ncol <m ){
                    int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]),diff);
                    if(newEffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = newEffort;
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }
        }
        return 0; // unreachable 

    }
    // tc - same as dijkstra ElogV
    // sc - n*m*4  *log(n*m)
};