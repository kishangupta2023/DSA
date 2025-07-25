//Account Merge -DSU
// Bob, a teacher of St. Joseph School given a task by his principal to merge the details of the students where each element details [I] is a list of strings, where the first dlement details [1] [0] is a name of the student, and the rest of the elements are emails representing emails of the student. Two details definitely belong to the same student if there is some common email to both detail. After merging the details, return the details of the student in the following format the first element of each detail is the name of the student, and the rest of the elements ans emails in sorted order The details themselves can be returned in any order Note Two details have the same name, they may belong to different people as people could have the same name A person can have any number of details initially, but all of their details definitely have the same name
// Note: In case 2 or more same email belongs to 2 or more different names merge with first name only. Print in the order in sorted way according to the name of the details
// Input:
// n: 4
// details -
// [["John", "johnsmith@mail.com", "john_newyork@mail.com"],
// ["John", "johnsmith@mail.com", "john00@mail.com"],
// ["Mary", "mary@mail.com"],
// ["John", "johnnybravo@mail.com"]]
// Output:
// [["John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"],["Mary", "mary@mail.com"],
// ["John", "johnnybravo@mail.com*]]
// Explanation:
// The first and second John's are the same person as they have the common email "johnsmith@mail.com". The third John and Mary are different people as none of their email addresses are used by other accounts.
// We could return these lists in any order, for example
// answer [[Mary', 'mary@mail.com'),

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int>rank,parent,size;
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] =1;
        }
    }

    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
// ulp_u =ultimate parent of u 
    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution{
    public:
    vector<vector<string>> mergeDetails(vector<vector<string>>& details){
        int n =details.size();
        unordered_map<string,int> mapMailNode;
        DisjointSet ds(n);
        for(int i =0;i<n;i++){
            for(int j=1;j<details[i].size();j++){
                string mail = details[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    mapMailNode[mail] = i;
                }
                else{
                    ds.unionBySize(i,mapMailNode[mail]);
                }
            }
        }
        vector<string> mergeMail[n];
        for(auto it: mapMailNode){
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergeMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i=0;i<n;i++){
            if(mergeMail[i].size() == 0) continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for(auto it: mergeMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;

    }
};