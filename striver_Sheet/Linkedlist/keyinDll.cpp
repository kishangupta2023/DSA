// delete all ocurence of a key in DLL -> delete the given number whereever prensent in ll
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

Node* deleteKey(Node* head,int key){
     Node* temp = head;
     while(temp !=NULL){
        if(temp->data == key){
            if(temp == head){
                head = temp->next;
            }
            Node* nextNode = temp->next;
            Node* prevNode = temp->back;
            if(nextNode !=NULL){
                nextNode->back = prevNode;
            }
            if(prevNode !=NULL){
                prevNode->next = nextNode;
            }
            free(temp);
            temp = nextNode;
        }
        else{
            temp = temp->next;
        }
    }
    return head;

}
// tc- o(n)
// sc-o(1)

int main(){
    vector<int> arr = {10,2,10,5,10,8,7,10};
    Node* head =convertArr2ll(arr);
    head = deleteKey(head,10);
    print(head);
    return 0;
}