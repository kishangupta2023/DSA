#include<iostream>
#include<vector>
#include<Queue>
using namespace std;

class Solution {
    private:
    void dfs(int node,vector<int> adj[],int vis[],vector<int> &ls ){
        ls.push_back(node);
        //traverse all its neighbour
        for(auto it: adj[node]){
            if(vis[it]){
                dfs(it,adj,vis,ls);
            }
        }
    }
    public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]){
        int vis[V] = {0};  
        int start = 0;
        vector<int> ls;
        dfs(start,adj,vis,ls);
        return ls; 
    }
};
// tc- o(n) + (2*E)
// sc - o(n)+O(n)+o(n) == o(n)

int main(){
   return 0;
}