//reverse a doubly linked list 

#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
//constructor
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArr2ll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
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

Node* reversedll(Node* head){
    if(head == NULL || head->next ==NULL) return head;
    Node* prev = NULL;
    Node* current = head;
    while(current !=NULL){
        prev = current->back;
        current->back = current->next;
        current->next = prev;
        current = current->back;
    }
    return prev->back;
    
} 


int main(){
    vector<int> arr = {2,5,8,7};
    Node* head =convertArr2ll(arr);
   
    head= reversedll(head);
    print(head);
    return 0;
}