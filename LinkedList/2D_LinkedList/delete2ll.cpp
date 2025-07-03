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

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* tail = head;
    while(tail->next !=NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    tail->back = nullptr;
    prev->next = nullptr;
    delete tail;

    return head;
}


Node* deleteKthElement(Node* head,int k){
    if(head == NULL){
        return NULL;
    }
    int count = 0;
    Node* kNode = head;
    while(kNode !=NULL){
        count++;
        if(count == k) break;
        kNode = kNode->next;
    } 
    Node* prev = kNode->back;
    Node* front = kNode->next;

    if(prev == NULL && front == NULL){
        return NULL;
    }
    else if(prev == NULL){
        return deleteHead(head);
    }
    else if(front == NULL){
        return deleteTail(head);
    }
    prev->next = front;
    front->back = prev;
    kNode->next = nullptr;
    kNode->back = nullptr;
    return head;
}


void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;
    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
    }
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    free(temp);
}


int main(){
    vector<int> arr = {2,5,4,3,6,8,7};
    Node* head =convertArr2ll(arr);

    head = deleteHead(head);
    print(head);

    head = deleteTail(head);
    print(head);

    head = deleteKthElement(head,2);
    print(head);


    return 0;
}