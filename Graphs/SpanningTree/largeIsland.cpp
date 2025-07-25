//making a large island 
// You are given an n x n binary grid. A grid is said to be binary if every value in grid is either 1 or 0.
// You can change at most one cell in grid from 0 to 1.
// You need to find the largest group of connected 1's.
// Two cells are said to be connected if both are adjacent to each other and both have same value.
// Input: 2 11 01
// Output:4

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int>rank,parent,size;
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
    bool isValid(int newr,int newc,int n){
        return newr>=0 && newr<n && newc>=0 && newc<n;
    }
    public:
    int MaxConnection(vector<vector<int>> & grid){
        int n = grid.size();
        DisjointSet ds(n*n);
        // Step-1
        for(int row = 0;row< n;row++){
            for(int col =0;col<n;col++){
                if(grid[row][col] ==0) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                for(int i=0;i<4;i++){
                    int newr = row+ dr[i];
                    int newc = col+ dc[i];
                    if(isValid(newr,newc,n) && grid[newr][newc] == 1){
                        int nodeNo = row*n +col;
                        int adjNodeNo = newr*n + newc;
                        ds.unionBySize(nodeNo,adjNodeNo);

                    }
                }
            }
        }
        //step-2
        int mx = 0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                 int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                set<int> components;
                for(int i=0;i<4;i++){
                    int newr = row+ dr[i];
                    int newc = col+ dc[i];
                    if(isValid(newr,newc,n)){
                        if(grid[newr][newc] ==1){
                            components.insert(ds.findUPar(newr*n +newc));
                        }
                    }
                }
                int sizeTotal =0;
                for(auto it: components){
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal +1);
            }
        }
        for(int cellNo = 0;cellNo<n*n;cellNo++){
            mx = max(mx,ds.size[ds.findUPar(cellNo)]);
        }

        return mx;
    }
};