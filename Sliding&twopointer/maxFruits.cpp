 // Fruit into the baskets 
// You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

// You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

// You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
// Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
// Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
// Given the integer array fruits, return the maximum number of fruits you can pick.

 

// Example 1:

// Input: fruits = [1,2,1]
 // Output: 3
 // Explanation: We can pick from all 3 trees.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxLen = 0;
        for(int i=0;i<n;i++){
            set<int>st;
            for(int j=i;j<n;j){
               st.insert(fruits[i]);
               if(st.size() <=2){
                maxLen = max(maxLen,j-i+1);
               }
               else{
                break;
               }
          }
        }
    }
    // tc->0(N*N)
    // sc-> 0(3)

    int totalFruits(vector<int>& fruits){
        int l =0;
        int r =0;
        int maxlen =0;
        unordered_map<int,int>mpp;
        while(r < fruits.size()){
            mpp[fruits[r]]++;
            if(mpp.size() > 2){
                while(mpp.size() > 2){
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]] == 0){ 
                        mpp.erase(fruits[l]);
                    }
                    l++;
                }
            }
            if(mpp.size() <=2){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
    // tc-> 0(2N)
    // sc -> 0(3)

    // more optimised approach 
    int totalFRuits(vector<int>& fruits){
        int l =0;
        int r =0;
        int maxlen =0;
        unordered_map<int,int>mpp;
        while(r < fruits.size()){
            mpp[fruits[r]]++;
            if(mpp.size() > 2){
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]] == 0){ 
                        mpp.erase(fruits[l]);
                    }
                    l++;
            }
            if(mpp.size() <=2){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }
        return maxlen;
    }
    // tc -0(N)
    // sc -0(3)
};