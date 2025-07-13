// Detect a cycle in an undirected Graph using DFS 

#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
    bool DFS(int node,int parent,int vis[],vector<int> adj[]){
        vis[node] = 1;
        for(auto adjacentNode: adj[node]){
            if(!vis[adjacentNode]){
                if(DFS(adjacentNode,node,vis,adj) == true) return true;
                else if(adjacentNode != parent) return true;
            }
            return false;
        }

    }

    public:
    bool detectCycle(int V, vector<int> adj[]){
        int vis[V] = {0};

        for(int i=1;i<=V;i++){
            if(!vis[i]){
              if(DFS(i,-1,vis,adj)  == true){
                  return true;
              }
            }
        }
        return false;
    }

};
// sc -o(N)+o(N)==o(N)
// tc - o(N + 2E)+o(N)


int main(){
    return 0;
}