// Detect a cycle in a undirected Graph using BFS 
#include<iostream>
#include<vector>
#include<Queue>
using namespace std;
class Solution{
    private:
    bool detect(int src,vector<int> adj[],int vis[]){
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjacentNode: adj[node]){
                if(!vis[adjacentNode]){
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode,node});
                }
                else if(parent != adjacentNode){
                    return true;
                }
            }
        }
        return false;
    }
   


    public:
    bool isCycle(int V,vector<int>adj[]){
    int vis[V] = {0};
    for(int i =0;i<V;i++){
        if(!vis[i]){
            if(detect(i,adj,vis)) return true;
        }
    }
    return false;

}
// tc-o(n+2E) +o(n)
// sc-o(N) + O(N) == o(N)
};


int main(){
    return 0;
}
