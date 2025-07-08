// add 1 to a given LL 
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

Node* addone(Node* head){
    if(head == NULL || head->next == NULL) return head;

    head = reversell(head);
    Node* temp = head;
    int carry = 1;
    while(temp !=NULL){
        temp->data = temp->data + carry;
        if(temp->data <10){
            carry = 0;
            break;
        }
        else{
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }
    if(carry == 1){
        Node* newNode = new Node(1);
        head = reversell(head);
        newNode->next = head;
        return newNode;
    }
    head = reversell(head);
    return head;
}
//tc - o(3N)
// sc - o(1)

int helper(Node* temp){
      if(temp == NULL) return 1;
      int carry = helper(temp->next);
      temp->data = temp->data + carry;
      if(temp->data < 10) return 0;
      temp->data = 0;
      return 1;
}
// optimise way - recursion
Node* recursiveadd(Node* head){
    int carry = helper(head);
    if(carry == 1){
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;
}
// tc-o(n)
// sc -o(n) recursive stach space 



int main(){
    vector<int> arr = {9,9,9,9};
    Node* head =convertArr2ll(arr);
    head = recursiveadd(head);
    print(head);
    return 0;
}