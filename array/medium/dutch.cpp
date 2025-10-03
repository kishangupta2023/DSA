//dutch national flag Algorithm 
// sort an array of 0's 1's 2's 
// [0 to low-1] -> 0
// [low to mid-1] -> 1
// [high+1 to n-1] -> 2

#include<bits/stdc++.h>
using namespace std;

class Solution{
     vector<int> algo(vector<int> &nums){
        int low =0;
        int mid =0;
        int high = nums.size()-1;
        while(mid < high){
            if(nums[mid] == 0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
     }
     // tc -0(N)
     // sc -(3)
};