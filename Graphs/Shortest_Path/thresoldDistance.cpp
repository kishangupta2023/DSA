// City With the smallest Number of neighbour at a thresold Distance .
// There are n cities numbered from 0 to n-1. Given the array edges where edges[i]
// =[from, toj, weight] represents a bidirectional and weighted edge between cities from, and toj, and given the integer distance Threshold. You need to find out a city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance, If there are multiple such cities, our answer will be the city with the greatest number
// Note: that the distance of a path connecting cities/and is equal to the sum of the edges' weights along that path
// Example 1:
// Input:
// N-4, M-4
// edges [[0,1,3], [1,2,1], [1,3,4],[2,3,1]1 distance Threshold - 4
// Output:3

//ex -> if 0 ->1,2 and 1->0,2,3 and 2 -> 0,1,3 and 3 -> 1,2
// here 0 and 3 have same small city so return the max of it so answer is 3 


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int findCity(int n,int m,vector<vector<int>>& edges,int distanceThresold){
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(auto it:edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }
        for(int i=0;i<n;i++) dist[i][i] = 0;

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX){
                        continue;
                    }
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }

        int cntCity = n;
        int cityNo = -1;
        for(int city =0;city < n;city++){
            int cnt =0;
            for(int adjCity = 0;adjCity<n;adjCity++){
                if(dist[city][adjCity] <= distanceThresold) cnt++;
            }
            if(cnt<=cntCity){
                cntCity = cnt;
                cityNo =city;
            }
        }
        return cityNo;
    }
};




// Dijkstras with little optimization: 
int findCity2(int n, int m, vector<vector<int>>& roads, int Threshold) {
        vector<int> num(n,0);
        vector<pair<int,int>> adj[n];
        for(int i=0;i<roads.size();i++){
            int dest1 = roads[i][0];
            int dest2 = roads[i][1];
            int cost =  roads[i][2];
            adj[dest1].push_back({dest2,cost});
            adj[dest2].push_back({dest1,cost});
        }
        for(int i=0;i<n;i++){
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

            vector<int> dis(n,1e9);
            pq.push({0,i});
            dis[i] = 0;
            while(!pq.empty()){
                pair<int,int> p = pq.top();
                int node = p.second;
                int dist = p.first;
                pq.pop();
                if(dist>=Threshold){
                    continue;
                }
                for(auto it : adj[node]){
                    int adj_node = it.first;
                    int adj_dis = it.second;
                    if(dist+adj_dis<dis[adj_node]){
                        dis[adj_node]=dist+adj_dis;
                        pq.push({dis[adj_node],adj_node});
                    }
                 }
            }
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dis[j]<=Threshold){cnt++;}
            }
            num[i] = cnt;
        }
        int mn = *min_element(num.begin(),num.end());
        for(int i=n-1;i>=0;i--){
            if(num[i]==mn) {
                return i;
            }
        }
    }