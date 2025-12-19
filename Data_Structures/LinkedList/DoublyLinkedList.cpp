#include "DoublyLinkedList.h"

void DoublyLinkedList::addFront(Node *node){
    if (head == nullptr){
        head = tail = node;
    }else{
        node->next = head ;
        head->prev = node;
        head = node;
    }
    size++;
}
void DoublyLinkedList::removeNode(Node* node){
    if(node == nullptr){
        return;
    }
    if(head == node && tail == node){
        head = nullptr ;
        tail = nullptr;
    }else if(head == node){
        head = head->next;
        if(head) head->prev = nullptr;
    }else if(tail == node){
        tail = tail->prev;
        if(tail) tail->next = nullptr;
    }else{
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    node->next = nullptr;
    node->prev = nullptr;
    size--;
}
Node* DoublyLinkedList::removeLast(){
    if(tail == nullptr) return nullptr;
    Node* lastNode = tail;
    if(head == tail){
        head = tail = nullptr;
    }else{
        tail = tail->prev;
        tail->next = nullptr;
    }
    lastNode->next = nullptr;
    lastNode->prev= nullptr;
    size--;
    return lastNode;

}