// FInd the number that appears ones and the other twice ;
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  // bruteforce
    int search(int n, int arr[]) {
        int ans =0;
        for(int i=0;i<n;i++){
            int cnt =0;
            for(int j=0;j<n;n++){
                if(arr[i] == arr[j]){
                    cnt++;
                }
            }
            if(cnt == 1){
                ans = arr[i];
            }
        }
        return ans;
    }
    // use hash or map for better solution
    // when number are long then use map with <long long,int>
     // tc-> 0(n/2+1)

     // optimal solution 
    //  just xor the number the single element will be left 


};