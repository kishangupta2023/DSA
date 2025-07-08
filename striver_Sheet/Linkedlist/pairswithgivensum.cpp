// find the pairs with given sum in DLL 

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


list<pair<int,int>> sumpairs(Node* head,int sum){
    Node* temp1 = head;
    list<pair<int,int>> ds;
    while(temp1!=NULL){
         Node* temp2 = temp1->next;
         while(temp2 !=NULL && (temp1->data + temp2->data <=sum)){
            if(temp1->data + temp2->data == sum){
                   ds.push_back({temp1->data,temp2->data});
            }
            temp2 = temp2->next;
         }
         temp1 = temp1->next;
    }
   return ds;
}
//tc -o(n2) near about , sc-o(1)


// optimise code
vector<pair<int,int>> optsumpairs(Node* head,int sum){
    Node* left = head;
    Node* right = head;
    vector<pair<int,int>> ds;
    while(right->next!=NULL){
        right = right->next;
    }
    while(left->data < right->data){
        if(left->data + right->data == sum){
            ds.push_back({left->data,right->data});
            left = left->next;
            right = right->back;
        }
        else if(left->data + right->data < sum){
            left = left->next;
        }
        else{
            right = right->back;
        }
    }
    return ds;
} 


int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    Node* head =convertArr2ll(arr);
    print(head);
    // list<pair<int,int>> ans =  sumpairs(head,5);
    vector<pair<int,int>> ans = optsumpairs(head,5);
    for(auto &num :ans){
        cout<<"("<<num.first<<","<<num.second<<")"<<endl;
    }

    return 0;
}