// rotate a Linked list
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

Node* findNthNode(Node* temp,int len){
    int64_t cnt = 1;
    while(temp!=NULL){
        if(cnt == len) return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}

Node* rotateLL(Node* head, int k){
    if(head == NULL || k == 0) return head;
    int length=1;
    Node* tail = head;
    while(tail->next != NULL){
        length++;
        tail = tail->next;
    }
    if(k& length == 0) return head;
    k = k% length;
    tail->next = head;
    Node* newLastNode = findNthNode(head,length-k);

    
    head = newLastNode->next;
    newLastNode->next = NULL;
    return head;
}


int main(){
    vector<int> arr = {2,5,8,7};
    Node* head =convertArr2ll(arr);
    head = rotateLL(head,2);
    print(head);
 
    return 0;
}