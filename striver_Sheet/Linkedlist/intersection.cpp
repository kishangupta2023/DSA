// find the intersection point of X & Y LinkedList 
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


// using hashing we can solve by storing nodes

Node* intersection(Node* head1,Node* head2){
    map<Node*, int>mpp;
    Node* temp = head1;
    while(temp !=NULL){
        mpp[temp] =1;
        temp = temp->next;
    }
    temp = head2;
    while(temp !=NULL){
        if(mpp.find(temp) != mpp.end()){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
//tc-o(n1*may be constant depend on map)+ o(n2)
//sc - o(n1) or o(n2)



// another way with sc - o(1)
Node* collisionPoint(Node* temp1,Node* temp2,int d){
   while(d){
    d--;
    temp2 = temp2->next;
   }
   while(temp1 !=temp2){
    temp1 = temp1->next;
    temp2 = temp2->next;
   }
   return temp1;
}


Node* optIntersection(Node* head1,Node* head2){
    if(head1 ==NULL || head2 == NULL) return NULL;
    Node* t1 = head1;
    int n1 = 0;
    Node* t2 = head2;
    int n2 = 0;
    while(t1 !=NULL){
        n1++;
        t1 = t1->next;
    }
    while(2 !=NULL){
        n2++;
        t2 = t2->next;
    }
    if(n1<n2){
       return collisionPoint(head1,head2,n2-n1);
    }else{
       return collisionPoint(head2,head1,n1-n2);
    }
}
// tc-o(n1) + o(n2) + o(n2-n1) + o(n1)
// sc-o(1)



// optimise way
Node* optimiseIntersection(Node* head1,Node* head2){
     if(head1 ==NULL || head2 == NULL) return NULL;
     Node* t1 = head1;
     Node* t2 = head2;
     while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
        if(t1 == t2) return t1;
        if(t1 == NULL) t1 = head2;
        if(t2 == NULL) t2 = head1;
     }
     return t1;
}
// tc - o(n1+n2) length of both the ll
// sc -o(1)

int main() {
    // Create first list
    vector<int> arr = {2, 5, 8};
    Node* head1 = convertArr2ll(arr);

    // Create second list
    vector<int> arr2 = {3, 2};
    Node* head2 = convertArr2ll(arr2);

    // Create common intersection part
    vector<int> commonPart = {7, 5, 3};
    Node* common = convertArr2ll(commonPart);

    // Attach common part to both lists
    Node* temp = head1;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = common;

    temp = head2;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = common;

    // Now both lists intersect at node with value 7

    Node* intersectNode = intersection(head1, head2);

    if (intersectNode) {
        cout << "Intersection at node with data = " << intersectNode->data << endl;
    } else {
        cout << "No intersection found" << endl;
    }

    return 0;
}
