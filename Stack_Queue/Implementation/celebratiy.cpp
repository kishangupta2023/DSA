// A celebrity is a person who is known by everyone else at the party but does not know anyone in return. Given a square matrix M of size N x N where M[i][j] is 1 if person i knows person j, and 0 otherwise, determine if there is a celebrity at the party. Return the index of the celebrity or -1 if no such person exists.
// Note that M[i][i] is always 0.
// Examples
// Input: M = [ [0, 1, 1, 0], [0, 0, 0, 0], [1, 1, 0, 0], [0, 1, 1, 0] ]
// Output: 1
// Explanation: Person 1 does not know anyone and is known by persons 0, 2, and 3. Therefore, person 1 is the celebrity.

// Everyone should know him but he should know no one
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int answer(vector<vector<int>> &mat){
        int n = mat.size();
        vector<int>knowMe(n,0);
        vector<int>Iknow(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1){
                    knowMe[j]++;
                    Iknow[i]++;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(knowMe[i] == n-1 && Iknow[i]== 0){
                return i;
            }
        }
        return -1;
    }
    //tc -0(N*N) + 0(N)
    // sc-0(2N)

    int ans(vector<vector<int>> &mat){
        int n = mat.size();
        int top =0;
        int down = n-1;
        while(top<down){
            if(mat[top][down] == 1){
                top = top+1;
            }
            else if(mat[down][top] == 1){
                down = down-1;
            }
            else{
                top++;
                down--;
            }
        }
        if(top > down) return -1;
        for(int i=0;i<n;i++){
            if(i == top) continue;
            if(mat[top][i] == 0 && mat[i][top] == 1){
                 continue;
            } 
            else{
                return -1;
            }
        }
        return top;
    }
    //tc -0(2N)
    //sc-0(1) 
};