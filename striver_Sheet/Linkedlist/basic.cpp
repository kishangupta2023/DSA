#include<bits/stdc++.h>
using namespace std;
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

Node* convertArr2ll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr);
        prev->next = temp;
        prev = temp;
    }
    return head;
}


void print(Node* head){
    while(head!= NULL){
        cout<<head->data<<" ";
        head= head->next;
    }
    cout<<endl;
}


int main(){
    vector<int> arr = {2,5,8,7};
    Node* head =convertArr2ll(arr);
 
    return 0;
}