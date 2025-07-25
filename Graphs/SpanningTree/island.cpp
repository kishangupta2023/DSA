// Number of Island - II -- online Queries DSU
// You are given a n,m which means the row and column of the 2D matrix and an array of size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator and each operator has two integer A[i] [0], A[i] [1] means that you can change the cell matrix [A[i][0]] [A[i][1]] from sea to island. Return how many island are there in the matrix after each operator. You need to return an array of size k.
// Note: An island means group of 1s such that they share a common side.
// Input: n = 4 m = 5 k=4 A ((1,1),(0,1),(3,3),(3,4))
// Output: 1122
#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] =1;
        }
    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
// ulp_u =ultimate parent of u 
    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution{
    private:
    bool isValid(int adjr,int adjc,int n,int m){
        return adjr >=0 && adjr<n && adjc>=0 && adjc<m; 
    }
    public:
    vector<int> numOfislands(int n,int m,vector<vector<int>> &operators){
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int cnt =0;
        vector<int>ans;
        for(auto it:operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int adjr = row + dr[i];
                int adjc = col + dc[i];

                if(isValid(adjr,adjc,n,m)){
                    if(vis[adjr][adjc] == 1){
                        int nodeNo = row*m +col;
                        int adjNodeNo = adjr*m +adjc; 
                        if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)){
                            cnt--;
                            ds.unionBySize(nodeNo,adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};