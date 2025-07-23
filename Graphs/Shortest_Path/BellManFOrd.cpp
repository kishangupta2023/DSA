// BellMan Ford Algorithm 
// help to detect negative cycles only applicable to diredted graph
// edges can be in any order 
// Relax all the edges N-1 times sequentially 
// relax = if(dist[u] + wt < dist[v]) dist[v] = dist[u] + wt

// why N-1 iterations 
// distance array will be ready after n-1 in worst case 
// Since in a graph of N nodes , in worst case, you will take N-1 eges to reach from the first to the last , thereby we iterate for N-1 iterations. 

// how to detect negative cycles 
// on Nth iteration,the relaxation will be done ,and if the dist[] arrays gets reduces then negative cycle present 


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> bellman_ford(int V,vector<vector<int>> & edges,int S){
        vector<int> dist(V,1e8);
        dist[0]= 0;
        for(int i=0;i<V-1;i++){
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if(dist[u] != 1e8 && dist[u]+wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // Nth relaxation to check negative cycle 
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u]+wt < dist[v]){
                return {-1};
            }
        }

        return dist;
    }

};
// Tc - o(V*E)