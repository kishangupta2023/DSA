//Number of operation to make Network Connected -DSU
// You are given a graph with n vertices and menges.
// You can remove one edge from anywhere and add that edge between any two vertices in one operation.
// Find the minimum number of operation that will be required to make the graph connected
// Input:
// n4   m=3
// Edge-([0, 1], [0,2], [1, 2]]
// Output:1
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
    public:
    int Solve(int n,vector<vector<int>>& edge){
        DisjointSet ds(n);
        int cntExtras = 0;
        for(auto it: edge){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) == ds.findUPar(v)){
                cntExtras++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }

        int cntC = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i) cntC++;
        }
        int ans =cntC -1;
        if(cntExtras >=ans) return ans;
        return -1;
    }
};