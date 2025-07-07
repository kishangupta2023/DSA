// sorting a linked list 

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

Node* sortLL(Node* head){
    vector<int>arr;
    Node* temp = head;
    while(temp !=NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    // above  o(n)
    // if we use merge sort or quick sort then o(nlogn)
    // dont use this sortcut merthod use merge or quick sort 
    sort(arr.begin(),arr.end());
    int i=0;
    temp = head;
    while(temp !=NULL){
        temp->data = arr[i];
        i++;
        temp =temp->next;
    }
    return head;
}

// overall tc - o(n+nlogn+n)
// sc - o(n)



// find middle 
Node* findmiddle(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast !=NULL && fast->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* merge(Node* left,Node* right){
      Node* dummyNode = new Node(-1);
      Node* temp = dummyNode;
      while(left !=NULL && right !=NULL){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
      }
      if(left) temp->next = left;
      if(right) temp->next = right;

      return dummyNode->next;
}

// optimise solution using mergesort for ll 
Node* MergeSortLL(Node* head){
     if(head == NULL || head->next == NULL) return head;

     Node* middle = findmiddle(head);
     Node* leftHead = head;
     Node* rightHead = middle->next;
     middle->next = nullptr;
    leftHead = MergeSortLL(leftHead);
    rightHead =  MergeSortLL(rightHead);

    return merge(leftHead,rightHead);
}
// tc -o((n+n/2)logn)
// sc - o(1) as inplace 


int main(){
    vector<int> arr = {2,5,8,7,1,4,6};
    Node* head =convertArr2ll(arr);
    // head = sortLL(head);
    print(head);
    head = MergeSortLL(head);
    print(head);
 
    return 0;
}