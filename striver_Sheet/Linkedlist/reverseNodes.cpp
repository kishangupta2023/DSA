// reverse Nodes in k-groups 
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

Node* findkthNode(Node* temp,int k){
      k-=1;
      while(temp!=NULL && k>0){
        k--;
        temp = temp->next;
      }
      return temp;
}

Node* reverse(Node* head){
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

Node* reverseKGroup(Node* head,int k){
    Node* temp = head;
    Node* prevNode =NULL;
    while(temp!=NULL){
        Node* kthNode = findkthNode(temp,k);
        if(kthNode ==NULL){
            if(prevNode) prevNode->next = temp;
            break;
        }
        Node* nextNode = kthNode->next;
        kthNode->next = NULL;
        reverse(temp);
        if(temp == head){
            head = kthNode;
        }else{
            prevNode->next = kthNode;
        }
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}
// tc-o(2n)


int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    Node* head =convertArr2ll(arr);
    head= reverseKGroup(head,3);
    print(head);
    return 0;
} 