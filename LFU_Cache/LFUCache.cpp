#include "LFUCache.h"

LFUCache::LFUCache(int capacity){
    this->capacity = capacity;
    this->minFreq = 0 ;
}
int LFUCache::get(int key){
    if(keyNode.find(key) == keyNode.end()){
        return -1;
    }
    Node* node = keyNode[key];
    int currFreq = node->freq;

    freqList[currFreq].removeNode(node);

    if(currFreq == minFreq && freqList[currFreq].size() ==0){
        minFreq++;
    }
    node->freq++;
    freqList[node->freq].addFront(node);
    return node->value;
}
