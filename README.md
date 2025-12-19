# LFU Cache Implementation in C++

This repository contains my implementation of an **LFU (Least Frequently Used) Cache** written in **C++**.

I built this project to understand how LFU eviction actually works internally and how it can be implemented efficiently using multiple data structures while keeping all operations in **O(1)** time.

This project focuses on real design thinking rather than just solving a single DSA problem.

---

## 1. What is an LFU Cache?

An LFU cache removes the key that has been used the **least number of times** when the cache reaches its capacity.

If multiple keys have the same frequency, the cache removes the **least recently used (LRU)** key among them.

So LFU works as:
- Frequency-based eviction
- LRU as a tie-breaker

---

## 2. Why LFU is Harder than LRU

LRU cache only needs to track recent usage.

LFU cache needs to track:
- Access frequency of each key
- Ordering of keys with the same frequency
- The minimum frequency currently present in the cache

Maintaining all of this efficiently without increasing time complexity makes LFU more complex than LRU.

---

## 3. High Level Design (O(1) Approach)

To achieve constant time complexity for both `get()` and `put()`, the cache uses three main components:

### Key to Node Mapping
```cpp
unordered_map<int, Node*> keyNode;
This allows direct access to cache entries.

Frequency to Doubly Linked List Mapping
unordered_map<int, DoublyLinkedList> freqList;


Each frequency has its own doubly linked list.
Nodes inside the same frequency follow LRU order.

Minimum Frequency Tracker
int minFreq;


This keeps track of the lowest frequency currently present and allows efficient eviction.

4. Node Structure

Each node stores:
.key
.value
.frequency
.previous pointer
.next pointer

class Node {
    int key;
    int value;
    int freq;
    Node* prev;
    Node* next;
};

5. Role of Doubly Linked List

Each frequency bucket uses a doubly linked list to:

Insert nodes at the front (most recently used)

Remove nodes in O(1)

Remove the least recently used node from the back

This is required to correctly handle tie cases.

6. Cache Operations

get(key)
Returns the value if the key exists
Increases the frequency of the key
Moves the node to the next frequency list
Updates minFreq if the old list becomes empty
put(key, value)
Updates value if the key already exists
If the cache is full, removes the LFU key
Uses LRU as a tie-breaker within the same frequency
Inserts new keys with frequency = 1
Resets minFreq to 1

7. Time and Space Complexity

Operation	Complexity
get()	O(1)
put()	O(1)
Space	O(N)

8. Build and Run

g++ -std=c++17 LFU_Cache/main.cpp \
LFU_Cache/LFUCache.cpp \
Data_Structures/LinkedList/DoublyLinkedList.cpp \
-o lfu

./lfu

## Sample Output
10
-1
30
10
-1
40
10

10. What I Learned

How LFU eviction works internally
Why frequency tracking alone is not enough
Combining multiple data structures for performance
Handling edge cases like empty frequency lists
Writing pointer-safe and modular C++ code
Thinking in terms of system design

11. Possible Improvements

Add unit tests
Make the cache thread-safe
Compare performance with LRU cache
Improve memory handling

Author

Aakash Kumar
C++ | Data Structures

GitHub: https://github.com/aakashk7092
