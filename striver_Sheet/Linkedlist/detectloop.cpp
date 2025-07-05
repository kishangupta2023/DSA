// detect a loop in the ll

// we will use concept of hashing
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

 
// using hashing
bool detectloop(Node* head) {
    map<Node*, bool> visited;
    Node* temp = head;

    while (temp != nullptr) {
        if (visited[temp] == true) {
            return true; // Loop detected
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false; // No loop
}
// tc-o(2logn)
// sc - o(n)


// tortoise and hair algorithm 
// slow->1step , fast->2step as two pointer
bool optimisedetectloop(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}

//  tc- o(n) close to 
//  sc- o(1)


int main(){
    Node* head1 = createListWithLoop();
    if(optimisedetectloop(head1)){
        cout<<"Loop detected"<<endl;
    }else{
        cout<<"Loop is not present"<<endl;
    }
    
    return 0;
}