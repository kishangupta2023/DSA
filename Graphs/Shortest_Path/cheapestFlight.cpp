// Cheapest Flights within K stops
// There are n cities and m edges connected by some narober of flights.
// You are given an array flights where flights[i] = [fromi, toi, price;] indicates that there is a flight from city from; to city to; with cost pricej.
// You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
// Example 1:
// Input:
// n = 4
// flights [[0,1,100], [1,2,100], [2,0,100],[1,3,600],[2,3,200]]
// src = 0
// dst 3
// k=1
// Output:700
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int CheapestFlight(int n,vector<vector<int >> & flights,int src,int dst,int k){
        vector<pair<int,int>>adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src]=0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if(stops > k) continue;
            for(auto iter : adj[node]){
                int adjNode = iter.first;
                int edW = iter.second;

                if(cost + edW < dist[adjNode]  && stops <= k){
                    dist[adjNode] = cost + edW;
                    q.push({stops+1,{adjNode,cost+edW}});

                }
            }
        }        

        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};
// tc -E = flights.size()