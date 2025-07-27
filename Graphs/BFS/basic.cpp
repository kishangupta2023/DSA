#include<iostream>
#include<vector>
#include<Queue>
using namespace std;

class Solution {
    public: 
    vector<int> bfsOfGraph(int V,vector<int> adj[]){
        int vis[V] = {0};
        vis[0] =1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while(q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};

//sc -o(3V) & tc - o(V) + o(2E) = (total degree)

int main(){

    return 0;
}