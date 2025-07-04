// reverse a linked list using iterative methodz
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

// reversing using stack 

Node* reverseLL(Node* head){
    Node* temp = head;
    stack<int> st;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    // tc- o(n)
    temp = head;
    while(temp!=NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    //tc-  o(n)

    // overall tc-o(2n) and sc-o(n)
    return head;
}


// optimise algorithm->by changing the node 
// tc-o(n)  sc -o(1)
Node* reversell(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!=NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}


// recursive method to reverse a linked list 
Node* reverse(Node* head){
    if(head == NULL || head->next ==NULL){
        return head;
    }
    Node* newHead = reverse(head->next);
    Node* front =head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
}

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head =convertArr2ll(arr);
    head= reversell(head);
    print(head);
    head= reverse(head);
    print(head);
    return 0;
}