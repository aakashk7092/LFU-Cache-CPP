#include "LFUCache.h"

LFUCache::LFUCache(int capacity){
    this->capacity = capacity;
    this->minFreq = 0;
}

int LFUCache::get(int key){
    if(keyNode.find(key) == keyNode.end()){
        return -1;
    }

    Node* node = keyNode[key];
    int currFreq = node->freq;

    freqList[currFreq].removeNode(node);

    if(currFreq == minFreq && freqList[currFreq].size == 0){
        minFreq++;
    }

    node->freq++;
    freqList[node->freq].addFront(node);

    return node->value;
}

void LFUCache::put(int key ,int value){
    if(capacity == 0) return;

    if(keyNode.find(key) != keyNode.end()){
        Node* node = keyNode[key];
        node->value = value;
        get(key); 
        return;
    }

    if (keyNode.size() == capacity) {
        DoublyLinkedList &list = freqList[minFreq];
        Node* nodeToRemove = list.removeLast();

        if (nodeToRemove != nullptr) {
            keyNode.erase(nodeToRemove->key);
            delete nodeToRemove;
        }
    }

    Node* newNode = new Node(key, value);
    minFreq = 1;

    freqList[1].addFront(newNode);
    keyNode[key] = newNode;
}
