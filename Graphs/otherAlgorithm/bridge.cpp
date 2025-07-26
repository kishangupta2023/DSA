// Bridges in Graph- Using Tarjan's Algorithm of time in nd low time
//Critical Connection in a network  
// There are n servers numbered from e ton 1 connected by undirected server-to-server connections forming a network where connections [i] = [a, b] represents a connection between servers a and by. Any server can reach other servers directly or indirectly through the network.
// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
// Return all critical connections in the network in any order.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    int timer = 1;
    private:
    void dfs(int node,int parent,vector<int>&vis,vector<int>adj[],int tin[],int low[],vector<vector<int>>& bridges){
        vis[node]= 1;
        tin[node] = low[node] = timer;
        timer++;
        for(auto it:adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                dfs(it,node,vis,adj,tin,low,bridges);
                low[node] = min(low[node],low[it]);

                // node -- it
                if(low[it] > tin[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node] =  min(low[node],low[it]);
            }
        }
    }
    public:
    vector<vector<int>> criticalConnections(int n,vector<vector<int>>& connections){
        vector<int> adj[n];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0,-1,vis,adj,tin,low,bridges);
        return bridges;
    }
};
// tc- 0(V+2E)
