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

 


// print function for printing ll
void print(Node* head){
    while(head!= NULL){
        cout<<head->data<<" ";
        head= head->next;
    }
    cout<<endl;
}

Node* insertHead(Node* head,int val){
    Node* temp = new Node(val,head);
    return temp;
}

Node* insertTail(Node* head, int val){
    if(head == NULL) {
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    Node* tail = new Node(val);
    temp->next = tail;

    return head;
}


Node* insertatk(Node* head,int val,int k){
    if(head == NULL){
        if(k==1){
            return new Node(val);
        }else{
            return NULL;
        }
    }

    if(k==1){
        Node* temp = new Node(val,head);
        return temp;
    }
    int count = 0;
    Node* temp = head;
    while(temp!=NULL){
        count++;
        if(count == k-1){
           Node* x = new Node(val);
           x->next = temp->next;
           temp->next = x;
           break;
        }
        temp = temp->next;
    }
    return head; 

}



int main(){
    vector<int> arr = {2,5,8,7};
    Node* head = convertArrLL(arr);

    // insert at head 
    head = insertHead(head,20);
    print(head);

    // insert at tail 
    head = insertTail(head,13);
    print(head);

    // insert at kth 

    head = insertatk(head,96,9);
    print(head);


   
}


