// We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.
// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
// Example 1:
// Input: asteroids = [5,10,-5]
// Output: [5,10]
// Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n =asteroids.size();
        vector<int>st;
        for(int i=0;i<n;i++){
            if(asteroids[i] > 0) st.push_back(asteroids[i]);
            else {
                while(!st.empty() && st.back() > 0 &&  st.back() < abs(asteroids[i])){
                    st.pop_back();
                }
                if(!st.empty() && st.back() == abs(asteroids[i])){
                    st.pop_back();
                }
                else if(st.empty()  || st.back() < 0){
                    st.push_back(asteroids[i]);
                }
            }   
        }
        return st;
    }
    // tc -> 0(2N)
    // sc -> 0(N)
};