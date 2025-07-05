// starting point of the loop 
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

// Function to create a linked list with a loop for testing
Node* createListWithLoop() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third; // Creating a loop here (back to third node)

    return head;
}

Node* startnode(Node* head){
    map<Node*,int>mpp;
    Node* temp = head;
    while(temp!= NULL){
        if(mpp.find(temp) != mpp.end()){
            return temp; // Node is alredy visited: start of the loop
        }
        mpp[temp] = 1; // mark the node the visited
        temp = temp->next;
    }
    return nullptr;
} 
// tc-o(n*2*c) c is constant 
// sc-o(n)



// optimise & hare alogorithm 
//1. detect the loop
// 2. finding the start point by putting slow at head and moving fast one step 
// the place where they collide is the start of loop 

Node* optimseStartnode(Node* head){
    Node* slow = head;    
    Node* fast = head;
    while(fast !=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
               slow = head;
               while(slow != fast){
                slow = slow->next;
                fast = fast->next;
               }
               //starting point 
               return slow;
        }
    }
    return nullptr;
}




int main(){
    Node* head = createListWithLoop();
    Node* ans = startnode(head);
    cout<<ans->data<<endl;
    
    return 0;
}