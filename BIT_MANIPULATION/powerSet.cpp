// PowerSet (print all subsets)
// iterator till 0->2pow(n) then store them in list by putting value as set bit in list 


#include<bits/stdc++.h>
using namespace std;
    vector<vector<int>>subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        int subset = 1<<n;
        for(int i=0;i<subset;i++){
            vector<int>v;
            for(int j=0;j<n;j++){
                if(i & (1<<j)){
                    v.push_back(nums[j]);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
    // tc -> n*2pow(n)
// sc -2pow(n)*n
int main(){
    vector<int>list = {1,2,3};
    vector<vector<int>> a =subsets(list);
    for(int i=0;i<a.size();i++){
        cout<<"[";
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j];
        }
        cout<<"]"<<endl;
    }
}