// SHortest path in undirected Graph having unit distance 
// You are given an Undirected Graph having unit weight, find the shortest distance from src to all the points, if path is not possible then put -1.
// Example:
// Input:
// n = 9, m= 10
// edges=[[0,1], [0,3], [3,4], [4,5] [5, 6], [1,2], src=0
// Output:
// 0 1 2 1 2 3 3 4 4
// Your Task:
// You don't need to print or input anything. Complete the function shortest path() which takes a undirected graph, an integer n and an integer src as the input parameters and returns an integer, denoting the vector of distance from src to all nodes.
// Constraint:
//M represt no of edges

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int> shortestPath(vector<vector<int>> &edges ,int N, int M,int src){
        vector<int>adj[N];
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int dist[N];
        for(int i=0;i<N;i++) dist[i] =1e9;
        dist[src] = 0;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }
        vector<int> ans(N,-1);
        for(int i=0;i<N;i++){
            if(dist[i] !=1e9){
                ans[i] = dist[i];
            }
        }
        return ans;
    }

};
// tc- same as bfs
// sc - whatever extra is created  == o(v+2E)

int main(){
    return 0;
}