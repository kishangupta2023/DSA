// Number of Enclaves || Multi-source BFS
// count the no's of lands(1) for going out of the boundary  
// return the count of lands from which u cant reach the boundary
#include<iostream>
#include<vector>
#include<Queue>
using namespace std;
class Solution{
    public:
    int numberOfEnclaves(vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int vis[n][m] = {0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // first row , first col ,last row last col
                if(i ==0 || j == 0 || i ==n-1 || j == m-1){
                   if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                   }
                }
            }
        }
        int drow[] = {-1,0,1,0}; 
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // traverse all four direction
            for(int i=0;i<4;i++){
               int nrow = row + drow[i];
               int ncol = col + dcol[i];
               if(nrow >=0 && nrow<n && ncol >= 0 && ncol <m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                q.push({nrow,ncol});
                vis[nrow][ncol] =1;
               }
            }

        }
        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
};
//sc - n*m
// tc -o(n*m*4)


int main(){
    return 0;
}