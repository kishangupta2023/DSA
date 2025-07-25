//Minimum Spanning Tree 
//Given a weighted , undirected and connected graph of V vertices and E dges . the task is to find the sum of weights of the edges of the Minimum Spanning Tree 

// greedy approach 

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int spanningTree(int V,vector<vector<int>>adj[]){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int> vis(V,0);
        // wt , node
        pq.push({0,0});
        int sum =0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;

            if(vis[node] == 1) continue;
            // add it to mst 
            vis[node] = 1;
            sum +=wt;
            for(auto it:adj[node]){
                int adjNode = it[0];
                int edW = it[1];
                if(!vis[adjNode]){
                    pq.push({edW,adjNode});
                }
            }
        }
        return sum;
    }
};
// tc - ElogE + ElogE = ElogE
// sc - o(E)
