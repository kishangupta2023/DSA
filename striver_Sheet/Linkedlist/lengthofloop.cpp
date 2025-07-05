// length of a loop in a given ll
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


// hashing 
int lengthofloop(Node* head){
     map<Node* , int>mpp;
     Node* temp = head;
     int timer = 1;
     while(temp!=NULL){
        if(mpp.find(temp) != mpp.end()){
            int value = mpp[temp];
            return (timer-value);
        }
        mpp[temp]= timer;
        timer++;
        temp = temp->next;
     }
     return 0;
}
//tc-o(n*2logn)
//sc-o(n)

int findlength(Node* slow,Node* fast){
    int count = 1;
    fast = fast->next;
    while(slow != fast){
        count++;
        fast = fast->next;
    }
    return count;
}

// tortoise and hare method by two pointer method
int optimiselengthofloop(Node* head){
      Node* slow = head;
      Node* fast = head;
      while(fast !=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return findlength(slow,fast);
        }
      }
      return 0;
}
 


int main(){
    Node* head1 = createListWithLoop();
    cout<<optimiselengthofloop(head1)<<endl;
    return 0;
}
