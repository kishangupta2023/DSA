// Strongly connected Components - Kosaraju's Algorithm 
//sort all the edges according to finishing time 
// reverse the graph 
// Do a dfs 

// Q 
// Given a directed Graph with V vertices (Numbered from 0 to v-1) and E edges , FInd the number of strongly connected components in the graph .

#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void dfs(int node,vector<int> &vis,vector<int> adj[],stack<int> &st){
        vis[node] =1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,st);
            }
        }

        st.push(node);
    }
    private: 
    void dfs3(int node,vector<int> &vis,vector<int>adjT[]){
         vis[node] =1;
        for(auto it: adjT[node]){
            if(!vis[it]){
                dfs3(it,vis,adjT);
            }
        }
    }
    public:
    int kosaraju(int V,vector<int> adj[]){
        vector<int>vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }

        vector<int>adjT[V];
        for(int i=0;i>V;i++){
            vis[i] = 0;
            for(auto it: adj[i]){
                adjT[it].push_back(i);
            }
        }
        
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs3(node,vis,adjT);
            }
        }
        return scc;
    }
};

// tc- 0(V+E) + 0(V+E) 
// sc -0(V+E) + 0(2V)