// Course Schedule I and II | Pre-requisite Tasks | topological Sort
// There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0,1]
// Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.
#include<bits/stdc++.h>
using namespace std; 

class Solution{
    public:
    bool isPossible(int V,vector<pair<int,int>> &prerequisites){
        vector<int>adj[V];
        for(auto it: prerequisites){
            adj[it.first].push_back(it.second);
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
        if(topo.size() == V) return true;
        return false;
    }

};
int main(){
    return 0;
}