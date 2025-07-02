#include<bits/stdc++.h>
using namespace std;
// we can use class at the place of struct 
// struct Node{
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }
//constructor
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

int main(){
    vector<int> arr = {2,5,8,7};
    Node* y = new Node(arr[0],nullptr);
    cout<<y<<endl;
    // cout<<y->data<<endl;
    // cout<<y->next<<endl;
}