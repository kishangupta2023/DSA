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


// delete or remove head 

Node* removeHead(Node* head){
    if(head==NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp); // delete temp;
    return head;
}

Node* removeTail(Node* head){
    if(head==NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next !=NULL){
        temp = temp->next;
    }
    // in c++ we need to free space not in java 
    delete(temp->next->next);
    temp->next = nullptr;
    return head;
}


// delete kth element 

Node* removek(Node* head, int k){
    if(head == NULL) return head;
    if(k==1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int count =0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp !=NULL){
        count++;
        if(count == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}


// remove element from ll
Node* removeElement(Node* head, int k){
    if(head == NULL) return head;
    if(head->data == k ){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp !=NULL){
          if(temp->data == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}





int main(){
    vector<int> arr = {2,5,4,9,2,8,7};
    Node* head = convertArrLL(arr);

     // remove head 
    head = removeHead(head);
    print(head);
    cout<<endl;

    // remove tail
    head=removeTail(head);
    print(head);
    cout<<endl;
    // remove kth 
    head = removek(head,3);
    print(head);
    cout<<endl;

    // remove element
    head = removeElement(head,8);
    print(head);

   
}


