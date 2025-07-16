// Djisktra's Algorithm with SET 
// erase -> already existing  values
#include<bits/stdc++.h>
using namespace std; 

class Solution{
    public:
    vector<int> djstra(int V,vector<vector<int>> adj[],int S){
        set<pair<int,int>> st;
        vector<int> dist(V,1e9);
        st.insert({0,S});
        dist[S] = 0;
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);

            for(auto it:adj[node]){
                int adjNode = it[0];
                int edgeW = it[1];

                if(dis + edgeW < dist[adjNode]){
                    if(dist[adjNode] != 1e9){
                        st.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode] = dis + edgeW;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};
int main(){
    return 0;
}