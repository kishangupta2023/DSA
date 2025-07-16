// Alien dictionary | Topological Sort 
// Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
// Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.
// Example
// Input:
// N = 5, K = 4
// dict("baa", "abcd", "abca","cab", "cad")
// Output:
// Explanation:
// Here order of characters is
// 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
// Similarly we can find other orders

#include<bits/stdc++.h>
using namespace std;

    vector<int> topoSort(int V,vector<int> adj[]){
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
        return topo;
    }
    string findOrder(string dict[],int N,int K){
        vector<int> adj[K];
        for(int i=0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(),s2.size());
            for(int ptr =0;ptr<len;ptr++){
                if(s1[ptr] != s2[ptr]){
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }
        vector<int> topo = topoSort(K,adj);
        string ans = " ";
        for(auto it: topo){
            ans = ans +" "+ char(it + 'a');
        }
        return ans;

    }


int main(){
    string dict[] = {"baa", "abcd", "abca","cab", "cad"};
    string answer = findOrder(dict,5,4);
    cout<<answer<<endl;
}
// when the order is not possible 
// abcd
// abc   as the string length of the above is greater heace order is not possible
// also if cyclid dependencies then not possible 
