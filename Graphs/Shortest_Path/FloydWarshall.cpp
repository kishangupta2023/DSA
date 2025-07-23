// Floyd Warshall Algorithm 
//MUlti Source shortest path also detect negative cycles 
// How to detect a negative cycle -> if(cost[i][i] < 0) then negative cycle exists 

// the problem is to find the shortest distance btw every pair of vertices in a given edge-weighted directed Graph 
// Do it inplace 
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void shortest_distance(vector<vector<int>>&matrix){
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = 1e9;
                }
                if(i == j){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                   matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]); 
                }
            }
        }



        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 1e9){
                    matrix[i][j] = -1;
                }
            }
        }
    }

};

// sc -o(n2)
// tc- o(n3)