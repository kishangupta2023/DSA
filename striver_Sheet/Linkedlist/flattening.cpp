// flattening a linked list 
// 3-> 2 -> 1 ->4 -> 5 ->X
// |   |    |   |    |
// X   10   7   9    6
//      |   |   |    |
//      X   11  X    8
//           |       |
//          12       X
//           |
//           X
// here every child node is in sorted order and have its nexr to null

#include<bits/stdc++.h>
using namespace std;
class Node{
     public:
    int data;
    Node* next;
    Node* child;
   
    public:
    Node(int data1,Node* next1,Node* child1){
        data = data1;
        next = next1;
        child = child1;
      
    }
//constructor
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        child = nullptr;
    }
};

Node* convert(vector<int> &arr){
    if(arr.size() == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<arr.size();i++){
        Node* newNode = new Node(arr[i],nullptr,nullptr);
        temp->child = newNode;
        temp = temp->child;
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

Node* flatten(Node* head){
    vector<int> arr;
    Node* temp = head;
    while(temp!=NULL){
        Node* t2 = temp;
        while(t2 !=NULL){
            arr.push_back(t2->data);
            t2 = t2->next;
        }
        temp = temp->next;
    }
    sort(arr.begin(),arr.end());
    head = convert(arr);
}
// tc-o(2*(n*m) + xlog(x)) where x is n*m
//  sc - o(n*m*2)




//  optimise code using merge to list

Node* merge2Lists(Node* list1,Node* list2){
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    while(list1 !=NULL && list2 !=NULL){
        if(list1->data < list2->data){
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = nullptr;
    }
    if(list1) res->child = list1;
    else res->child = list2;
    if(dummyNode->child) dummyNode->child->next = nullptr;
    return dummyNode->child;
}
//tc - o(n+m) 

Node* optimiseFlatten(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* mergedhead = optimiseFlatten(head->next);
    head = merge2Lists(head,mergedhead);
    return head;
}

// overall tc-o(n* merge-tc) ==n*o(2m) === o(2nm)
// sc - o(n)


int main(){
    vector<int> arr = {2,5,8,7};
    Node* head =convert(arr);
 
    return 0;
}