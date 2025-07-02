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

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArrLL(vector<int> &arr){
     Node* head = new Node(arr[0]);
     Node* mover = head;
     for(int i =1; i<arr.size();i++){
        Node* temp = new  Node(arr[i],nullptr);
        mover->next = temp;
        mover = temp; // or  mover = mover->next
     }
     return head;
}

// length of a linked list 

int lengthOfLL(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp){
        temp = temp->next;
        count ++;
    }
    return count;
}

// search an element in a ll 

int checkIfPresent(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}
// print function for printing ll
void print(Node* head){
    while(head!= NULL){
        cout<<head->data<<" ";
        head= head->next;
    }
    cout<<endl;
}


// delete or remove head 

Node* removeHead(Node* head){
    if(head==NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp); // delete temp;
    return head;
}


int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArrLL(arr);
    // cout<< head->data;
    

    // traversal 
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
 // length of ll
    // cout<<endl<<lengthOfLL(head);


   
}


