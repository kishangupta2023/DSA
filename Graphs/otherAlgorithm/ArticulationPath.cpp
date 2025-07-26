// Articulation Point in Graph
// Nodes on whose removal the graph breaks into multiple components is articulation point 
// tin[] ->Store the time of insertion during DFS 
// low[]-> min of all adjacent nodes apart from parent & visited nodes. 

// Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components.
// Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). A
// There might be loops present in the graph
// Your Task:
// You don't need to read or print anything. Your task is to complete the function articulation Points() which takes V and adj as input parameters and returns a list containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are no such vertices then returns a list containing -1.
// Expected Time Complexity:O(V+E)
// Expected Auxiliary Space:0(V)


#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    int timer =0;
    void dfs(int node,int parent,vector<int> &vis,int tin[], int low[],vector<int> &mark,vector<int>adj[]){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(auto it: adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it,node,vis,tin,low,mark,adj);
                low[node] = min(low[node],low[it]);
                if(low[it] >= tin[node] && parent != -1){
                    mark[node] = 1;
                }
                child++;
            }
            else{
                low[node] = min(low[node],tin[it]);
            }
        }
        if(child > 1 && parent == -1){
            mark[node] = 1;
        }
    }
    public: 
    vector<int> articulationPoints(int n,vector<int> adj[]){
        vector<int> vis(n,0);
        int tin[n];
        int low[n];
        vector<int>mark(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,vis,tin,low,mark,adj);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(mark[i] == 1){
                ans.push_back(i);
            }
        }
        if(ans.size() == 0) return {-1};
        return ans;

    }
};
// sc - 3n
// tc - v+2e + 0(n)