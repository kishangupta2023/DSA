// LFU Cache 
// (least frequently used cache )
// Design and implement a data structure for a Least Frequently Used (LFU) cache.

// Implement the LFUCache class:

// LFUCache(int capacity) Initializes the object with the capacity of the data structure.
// int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
// void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
// To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

// When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

// The functions get and put must each run in O(1) average time complexity.
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key,value,freq;
    Node* next;
    Node* prev;
    Node(int k,int v) : key(k),value(v),freq(1),next(nullptr),prev(nullptr) {}
};

class DLL{
public:
    Node* head;
    Node* tail;
    int size;
    DLL(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addNode(Node* node){
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
        size++;
    }

    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }

    Node* removeLast(){
        if(size == 0) return nullptr;
        Node* node = tail->prev;
        deleteNode(node);
        return node;
    }
};

class LFUCache {
private:
    int capacity,minFreq;
    unordered_map<int,DLL*>freqTable;
    unordered_map<int,Node*>keyTable;

    void updateFreq(Node* node){
        int freq = node->freq;

        // remove node from current freq DLL
        freqTable[freq]->deleteNode(node);

        // update minFreq if needed
        if(freq == minFreq && freqTable[freq]->size == 0){
            minFreq++;
        }

        node->freq++;

        // create new DLL if not exists
        if(freqTable.find(node->freq) == freqTable.end()){
            freqTable[node->freq] = new DLL();
        }
        // always add the node to new freq DLL
        freqTable[node->freq]->addNode(node);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }
    
    int get(int key) {
        if(capacity == 0 || keyTable.find(key) == keyTable.end()) return -1;
        Node* node = keyTable[key];
        updateFreq(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;

        if(keyTable.find(key) != keyTable.end()){
            Node* node = keyTable[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        if(keyTable.size() == capacity){
            Node* toRemove = freqTable[minFreq]->removeLast();
            keyTable.erase(toRemove->key);
            delete toRemove;
        } 

        Node* newNode = new Node(key,value);
        if(freqTable.find(1) == freqTable.end()){
            freqTable[1] = new DLL();
        }
        freqTable[1]->addNode(newNode);
        keyTable[key] = newNode;
        minFreq = 1;
    }
};
