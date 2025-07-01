#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cin>>n;
     int arr[n];
     map<int,int> mpp;
    //  we can do it here to 
     for(int i=0;i<n;i++){
        cin>>arr[i];
        mpp[arr[i]]++;
     }

     //pre-compute
    //  map<int,int> mpp;
    //  for(int i=0;i<n;i++){
    //     mpp[arr[i]]++;
    //  }


     //sorted order
    //  for(auto it:mpp){
    //     cout<<it.first << "->" << it.second << endl;
    //  }

    // if we use unordered_map then the sorted order is not present it can change to every run   

     int q;
     cin>>q;
     while(q--){
        int number;
        cin>>number;
        //fetch
        cout<<mpp[number]<<endl;
     }


    return 0;
}