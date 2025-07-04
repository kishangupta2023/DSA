// find middle of the Linked List 
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


Node* middleElement(Node* head){
    Node* temp= head;
    int count =0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    // here time complexity is o(n)
    int middle = (count/2) + 1;
    temp = head;
    while(temp != NULL){
        middle = middle-1;
        if(middle == 0) break;
            temp = temp->next;
    }
    // here time complexity is o(n/2)
    return temp;
    //overall time complexity o(n+n/2)
}


// optimesed way to solve it -> Tortoise & Hare algorithm 
// using slow and fast pointer where slow->1step and fast->2 step when linked list odd
// for odd fast pointer will reach at last node
//for even fast pointer will be reaching null
Node* middlebyTortoise(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast !=NULL && fast->next !=NULL){
        slow = slow->next;
        fast =fast->next->next;
    }
    return slow;
}

int main(){
    vector<int> arr = {2,5,8,7};
    Node* head =convertArr2ll(arr);
    // Node* middle = middleElement(head);
    Node* middle = middlebyTortoise(head);
    cout<<middle->data<<endl;
    return 0;
}