// Minimum Multiplications to Reach End 
// Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.
// Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.
// Input:
// arr[] [2, 5, 7]
// start 3, end = 30
// Output: 2
// Explanation:
// Step 1: 3*26% 1000006
// Step 2: 6*5-30% 100000-30

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int minimumMultiplications(vector<int> & arr,int start,int end){
        queue<pair<int,int>>q;
        q.push({start,0});
        vector<int> dist(100000,1e9);
        dist[start] = 0;
        int mod = 100000;
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            for(auto it:arr){
                int num = (it*node) %mod;
                if(steps + 1 < dist[num]){
                    dist[num] = steps+1;
                    if(num == end) return steps+1;
                    q.push({num,steps+1});
                }
            }

        }
        return -1;
    }
};
//tc - o(100000 + N) hypothetically and exact is not possible 

int main(){
    return 0;
}