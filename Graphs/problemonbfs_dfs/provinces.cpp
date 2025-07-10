//Number of provinces | connected graph
// given  an undirected graph with V vertices , we say two vertices u and v belongs to a single province if there is a path from u and v or v to u . your task is to find the number of provinces 
// Note : A provinces is a group of directly or indrectly connencted cities and no other cities outside of the group 

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    private:
    void dfs(int node,vector<int>adjLs[],int vis[]){
        vis[node] = 1;
        for(auto it: adjLs[node]){
            if(!vis[it]){
                dfs(it,adjLs,vis);
            }
        }
    }


    public:
    int numProvisions(vector<vector<int>> adj,int V){
        vector<int> adjLs[V];

        // to change adjacent matrix to list 
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
               if(adj[i][j] == 1 && i!=j) {
                   adjLs[i].push_back(j);
                   adjLs[j].push_back(i);
                }
            }
        }
        int vis[V] = {0};
        int count = 0;
        for(int i =0;i<V;i++){
            if(!vis[i] == 0){
                count++;
                dfs(i,adjLs,vis);   
            }
        }
    }
};

// sc -> o(n) + o(n)
// tc -> o(n) + o(V +2E) 


int main(){
     return 0;
}

