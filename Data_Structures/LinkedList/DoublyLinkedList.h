class Node{
public:    
    int key;
    int value;
    int freq;
    Node* next;
    Node* prev;

    Node(int key,int value){
        this->key = key;
        this->value =value;
        this->freq = 1;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
class DoublyLinkedList{
public:
    Node* head;
    Node* tail;
    int size;
    
    DoublyLinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
};

