// check if a ll is palindrome 

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

// bruteforce approach 
bool palindrome(Node* head){
   Node* temp= head;
   stack<int>st;
   while(temp!=NULL){
    st.push(temp->data);
    temp = temp->next;
   }
   temp =head;
  
    while(temp!=NULL){
        if(st.top() != temp->data){
            return false;
        }
        temp = temp->next;
        st.pop();
    }
    return true;
}
// tc- o(2n)
// sc- o(n)




// optimise way 
Node* reversell(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!=NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

bool optimisePalindrome(Node* head){
     Node* slow = head;
     Node* fast = head;
     while(fast->next !=NULL && fast->next->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
     }
    Node* newHead = reversell(slow->next);

    Node* first = head;
    Node* second = newHead;
    while(second !=NULL){
        if(first->data != second->data){
            reversell(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reversell(newHead);
    return true;
}

// tc- o(2n) 
// sc- o(1)


int main(){
    vector<int> arr = {2,5,8,5,2};
    Node* head =convertArr2ll(arr);
    print(head);
    if(palindrome(head)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}