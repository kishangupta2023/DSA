// odd & even linked list 
// group the odd index nodes and even index nodes 

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

// iterative method
Node* oddevenll(Node* head){
    if(head == NULL || head->next ==NULL){
        return head;
    }

    vector<int>arr;

    Node* temp = head;
    while(temp !=NULL && temp->next !=NULL){
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) arr.push_back(temp->data);
    temp = head->next;
    while(temp!=NULL && temp->next !=NULL){
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp) arr.push_back(temp->data);
    int i =0; 
    temp = head;
    while(temp!=NULL){
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }

    return head;
}
// tc- (o(2n)
// sc-o(n)


// optimise solution

Node* optimiseoddeven(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;
    while(even !=NULL && even->next !=NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
// tc - o(n/2)*2 = o(n)
// sc - o(1)





int main(){
    vector<int> arr = {2,5,8,7,9,1,3};
    Node* head =convertArr2ll(arr);
    head = optimiseoddeven(head);
    print(head);
   
   
    return 0;
}