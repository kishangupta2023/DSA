// Rotten orange 
// given a grid of dimesion n*m where each cell in the grid can have value 0 ,1 or 2 which has the following meaning 
// 0 . Empty cell
// 1 . Cells have fresh orange 
// 2 . Cells have rotten orange 
// we have to determine what is the minimun time required to rot all oranges .A rotten orange at index[i,j] can rot other fresh oranges at index [i-1,j], [i+1,j],[i,j-1],[i,j+1] top down left right in unit time . 

// apply BFS as it is level wise 
#include<iostream>
#include<vector>
#include<Queue>
using namespace std;

class Solution{
     public:
     int orangesRotting(vector<vector<int>> &grid ){
        int n = grid.size();
        int m = grid[0].size();
        // {{row,column},time}
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] == 2;
                }
                else{
                    vis[i][j] =0;
                }
            }
        }
        int tm = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow >= 0 && nrow< n && ncol >=0 && ncol <m && vis[nrow][ncol] !=2 && grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] !=2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return tm;
     }
};

// sc - o(n*m)
//tc - o(o(n*m) + (n*m*4)

int main(){
    return 0;
}


// class Solution{
//      public:
//      int orangesRotting(vector<vector<int>> &grid ){
//         int n = grid.size();
//         int m = grid[0].size();
//         // {{row,column},time}
//         queue<pair<pair<int,int>,int>> q;
//         int vis[n][m];
//         int cntFresh = 0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j] == 2){
//                     q.push({{i,j},0});
//                     vis[i][j] == 2;
//                 }
//                 else{
//                     vis[i][j] =0;
//                 }
//                 if(grid[i][j] == 1) cntFresh++;
//             }
//         }
//         int tm = 0;
//         int drow[] = {-1,0,1,0};
//         int dcol[] = {0,1,0,-1};
//         int cnt = 0;
//         while(!q.empty()){
//             int r = q.front().first.first;
//             int c = q.front().first.second;
//             int t = q.front().second;
//             tm = max(tm,t);
//             q.pop();
//             for(int i=0;i<4;i++){
//                 int nrow = r+drow[i];
//                 int ncol = c+dcol[i];
//                 if(nrow >= 0 && nrow< n && ncol >=0 && ncol <m && vis[nrow][ncol] !=2 && grid[nrow][ncol] == 1){
//                     q.push({{nrow,ncol},t+1});
//                     vis[nrow][ncol] = 2;
//                     cnt++;
//                 }
//             }
//         }
//         if(cnt !=cntFresh) return -1;
        
//         return tm;
//      }
// };