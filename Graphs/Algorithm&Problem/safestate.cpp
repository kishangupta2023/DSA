// find Eventual safe states | BFS |Topological Sort
// A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V-1.
// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.
// You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> eventualSafeNodes(int V , vector<int> adj[]){
        vector<int> adjRev[V];
        int indegree[V] ={0};
        for(int i=0;i<V;i++){
            // i->it
            // it->i
            for(auto it:adj[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safeNodes;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it: adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};
// tc -similar to topo sort 
// sc - same as topo + sorting space and adjrev space


int main(){
    return 0;
}