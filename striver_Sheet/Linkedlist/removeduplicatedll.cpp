// remove the duplicates from a sorted DLL 
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

Node* removeDuplicate(Node* head){
    Node* temp = head;
    while(temp !=NULL && temp->next !=NULL){
        Node* nextNode = temp->next;
        while(nextNode !=NULL && nextNode->data == temp->data){
            Node* del = nextNode;
            nextNode = nextNode->next;
            free(del);
        }
        temp->next = nextNode;
        if(nextNode) nextNode->back = temp;
        temp = temp->next;
    }
    return head;
}
// tc-o(n) sc-o(1)


int main(){
    vector<int> arr = {1,1,1,2,3,3,4};
    Node* head =convertArr2ll(arr);
    head= removeDuplicate(head);
    print(head);
    return 0;
}