// Number of Ways to Arrive at Destination
// You are in a city that consists of n intersections numbered from 0 to n-1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.
// You are given an integer n and a 2D integer array roads where roads [i] = [uj, vi, time;] means that there is a road between intersections uj and v_{i} that takes time; minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time
// Return the number of ways you can arrive at your destination in the shortest amount of time Since the answer may be large, reten it modulo 10 ^ 9 + 7

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countPath(int n,vector<vector<int>> &roads){
        vector<pair<int,int>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        vector<int> dist(n,1e9),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        int mod = (int)(1e9 + 7);
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int adjNode =it.first;
                int edW = it.second;
                // this is the first time i am coming 
                //with this short distance 
                if(dis + edW < dist[adjNode]){
                    dist[adjNode] = dis + edW;
                    pq.push({dis+edW,adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis + edW == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }

        }
        return ways[n-1] % mod;
    }
};