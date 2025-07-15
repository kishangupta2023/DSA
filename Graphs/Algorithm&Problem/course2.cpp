// Course Schedule I and II part -2 
// There are a total of n tasks you have to pick, labeled from 0 to n-1. Some tasks may have prerequisites tasks, forexample to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
// Given the total number of n tasks and a list of prerequisite pairs of size m.
// Find a ordering of tasks you should pick to finish all tasks.
// Note: There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all tasks, return an empty array.
// Returning any correct order will give the output as 1, whereas any invalid order will give the output 0.

#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int> findOrder(int V,int m, vector<vector<int>> prerequisites){
        vector<int>adj[V];
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        int indegree[V] = {0};
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // node is in your topo sort 
            // remove it from the indegree
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        if(topo.size() == V) return topo;
        return {};
    }
    
};

int main(){
    return 0;
}