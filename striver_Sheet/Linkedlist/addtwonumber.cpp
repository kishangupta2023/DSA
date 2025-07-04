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

Node* addtwonumber(Node* head1,Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummyNode = new Node(-1);
    Node* current = dummyNode;
    int carry = 0;
    while(t1 !=NULL || t2 !=NULL){
        int sum = carry;
        if(t1) sum += t1->data;
        if(t2) sum += t2->data;
        Node* newNode = new Node(sum % 10);
        carry = sum/10;
        current->next = newNode;
        current = current->next;

        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
        
    }
    if(carry){
        Node* newNode= new Node(carry);
        current->next = newNode;
    }

    return dummyNode->next;

}


int main(){
    vector<int> arr = {3,5};
    Node* head1 =convertArr2ll(arr);
    vector<int> arr1 = {4,5,9,9};
    Node* head2 =convertArr2ll(arr1);
    Node* head = addtwonumber(head1,head2);
    print(head);
    return 0;
}