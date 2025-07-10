// Clone a linkedList with Next and Random pointer


#include<bits/stdc++.h>
using namespace std;
class Node{
     public:
    int data;
    Node* next;
    Node* random;
   
    public:
    Node(int data1,Node* next1,Node* random1){
        data = data1;
        next = next1;
        random = random1;
      
    }
//constructor
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        random = nullptr;
    }
};

Node* convertArr2ll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,nullptr);
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


Node* clone(Node* head){
    Node* temp = head;
    map<Node*,Node*> mpp;
    while(temp !=NULL){
        Node* newNode = new Node(temp->data);
        mpp[temp] = newNode;
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        Node* copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;  
    }
    return mpp[head];
}


// optimse way 
//1-> insert the copy node in between the nodes
//2-> point the random pointers
//3-> make sure next pointer are connected or connect it

void insertCopyInbtw(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        Node* nextElement = temp->next;
        Node* copy = new Node(temp->data);
        copy->next = nextElement;
        temp->next = copy;

        temp = nextElement;
    }
}

void connectRandomPointers(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* copyNode = temp->next;
        if(temp->random !=NULL) {
        copyNode->random = temp->random->next;
        }
        else{
            copyNode->random = nullptr;
        }   
        temp = temp->next->next; 
    }
}

Node* getDeepCopyList(Node* head){
    Node* temp = head;
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    while(temp !=NULL){
        res->next = temp->next;
        res = res->next;

        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummyNode->next;
}

Node* optclone(Node* head){
   insertCopyInbtw(head);
   connectRandomPointers(head);
   return getDeepCopyList(head);
}
// tc - o(3n)
// sc-o(n)


int main(){
    vector<int> arr = {2,5,8,7};
    Node* head =convertArr2ll(arr);
 
    return 0;
}