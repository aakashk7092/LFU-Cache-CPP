#pragma once
#include <unordered_map>
#include "../Data_Structures/LinkedList/DoublyLinkedList.h"

class LFUCache{
private:    
    int capacity;
    int minFreq;

    std::unordered_map<int,Node*> keyNode;
    std::unordered_map<int,DoublyLinkedList> freqList;
public:
    LFUCache(int capacity);
    int get(int key);
    void put(int key ,int value);
};
