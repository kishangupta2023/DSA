// Distance of nearest cell having 1 | 0/1 matrix
// 0 1 0
// 1 0 0
// 1 0 0 
// in the above example we need to find the nearest cell to have 1
// for first one -> distance --> 1 0 1
// for second one -> distance -->0 1 2  
// for third one -> distance --> 0 1 2  
#include<iostream>
#include<vector>
#include<Queue>
using namespace std;

class Solution {

    public:
    vector<vector<int>>nearest(vector<vector<int>>grid){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({{i,j},0});
                    vis[i][j] =1;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;

            int drow[] = {-1,0,1,0}; 
            int dcol[] = {0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int nrow = row+ drow[i];
                int ncol = col+ dcol[i];

                if(nrow>=0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }
        return dist;
    } 
};