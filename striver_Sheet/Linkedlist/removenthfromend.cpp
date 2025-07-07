// remove the nth node from the end 

// reverse a linked list using iterative methodz
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

Node* removenthfromEnd(Node* head,int n){
    int count = 0;
    Node* temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    if(count == n){
       Node* newhead = head->next;
       free(head);
       return newhead;
    }
    int res = count - n;
    temp = head;
    while(temp!=NULL){
        res--;
        if(res == 0) break;
        temp = temp->next;
    }
    Node* delNode= temp->next;
    temp->next = temp->next->next;
    free(delNode);
    return head;
}
//tc - o(n) + o(len - n) = o(2n)
// sc-O(1)


// optimise way use slow and fast pointer 
// first move fast pointer for nth step and then move slow and fast by one step untill fast reaches null 
Node* optimiseremoventh(Node* head,int n){
    Node* slow = head;
    Node* fast = head;
    for(int i =0;i<n;i++) fast = fast->next;
    while(fast->next !=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    if(fast ==NULL){
        Node* newhead = head->next;
        free(head);
        return newhead;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    free(delNode);
    return head;
}
//tc -o(n)


int main(){
    vector<int> arr = {2,5,8,7};
    Node* head =convertArr2ll(arr);
 
    return 0;
}