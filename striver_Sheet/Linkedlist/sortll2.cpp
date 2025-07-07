// sort a LL of 0's , 1's,2's 
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

Node* sorting(Node* head){
    int count0=0;
    int count1=0;
    int count2=0;
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == 0) count0++;
        if(temp->data == 1) count1++;
        if(temp->data == 2) count2++;
        temp = temp->next;
    }
    temp = head;
    while(temp !=NULL){
        if(count0){
            temp->data = 0;
            count0--;
        }
        else if(count1){
            temp->data = 1;
            count1--;
        }
        else{
            temp->data = 2;
            count2--;
        }
        temp =temp->next;
    }
    return head;
} 
//tc - o(2n)
// sc - o(1)

// optimise way 
// by taking 3 dummynode

Node* optimisesort(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    while(temp!=NULL){
        if(temp->data == 0){
            zero->next = temp;
            zero = temp;
        }
        if(temp->data == 1){
            one->next = temp;
            one = temp;
        }
        if(temp->data == 2){
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }
    zero->next =(oneHead->next)?oneHead->next:twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;
    Node* newHead =zeroHead->next;
    free(zeroHead); 
    free(oneHead); 
    free(twoHead); 
    return newHead;
}
// tc -o(n)
//sc -o(1)


int main(){
    vector<int> arr = {0,1,0,2,0,2,1,0,1};
    Node* head =convertArr2ll(arr);
    head = optimisesort(head);
    print(head);
 
    return 0;
}