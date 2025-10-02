// find second largest and second minimum in an array 
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int secondLargest(vector<int>&a,int n){
        int largest = a[0];
        int secondlargest= -1;
        for(int i=1;i<n;i++){
            if(a[i] > largest){
                secondlargest = largest;
                largest = a[i];
            }
            else if(a[i] < largest && a[i] > secondlargest){
                secondlargest = a[i];
            }
        }
        return secondlargest;
    }
    int secondSmallest(vector<int>&a,int n){
        int smallest = a[0];
        int secondsmallest = INT_MAX;
        for(int i=1;i<n;i++){
            if(a[i] < smallest){
                secondsmallest=smallest;
                smallest = a[i];
            }
            else if(a[i] > smallest && a[i] < secondsmallest){
                secondsmallest = a[i];
            }
        }
        return secondsmallest;
    }

    vector<int>getSecondOrderElement(int n,vector<int>a){
        int slargest = secondLargest(a,n);
        int ssmallest = secondSmallest(a,n);
        return {slargest,ssmallest};
    }
    // tc -0(N)


    // bruteforce 
    int secondLarg(vector<int>arr){
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int largest = arr[n];
        int secondLargest = -1;
        for(int i = n-1;i>=0;i--){
            if(arr[i] != largest){
                secondLargest = arr[i];
                break;
            }
        }
        return secondLargest;
    }
    // 0(N*logN) + 0(N)



};