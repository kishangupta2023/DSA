// Shortest distance in a binary maze 
// I Given a n m matrix grid where ca where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1.
// If the path is not possible between source cell and destination cell, then return -1.
// Example 1:
// Input:
// grid[][] = ( 1, 1, 1, 1 ),
// (1, 1, 0, 1),
// {1, 1, 1, 1}
// ( 1, 1, 0, 0 ),
// {1, 0, 0, 1}
// source = {0, 1}
// destination = {2, 2}
// Output:3

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int shortestPath(vector<vector<int>> & grid,pair<int,int> source,pair<int,int> destination){
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[source.first][source.second] =0;
        q.push({0,{source.first,source.second}});
        int dr[]= {-1,0,1,0};
        int dc[]= {0,1,0,-1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i=0;i<4;i++){
                int newr = r + dr[i];
                int newc = c + dc[i];

                if(newr >=0 && newr<n && newc >=0 && newc < m && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc]){
                    dist[newr][newc] = 1+dis;
                    if(newr == destination.first && newc == destination.second){
                        return dis +1;
                    }
                    q.push({1+dis,{newr,newc}});
                }
            }

        }
        return -1;

    }
};
