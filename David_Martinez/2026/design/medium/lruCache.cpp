#include <iostream>
#include <unordered_map>

using namespace std;

/*
25 min
info
    - design a DS that follows the constraints of a LRU cache

    - The functions get and put must each run in O(1) average time complexity.

    constraints
        - range of calues capacity can have? [1, 3k]
        - range of values key can have? [0, 10k]
        - range of values that the value can have? 0, 100k
        - at most 200k calls will be made to get and put

    brute force
        hashtable to get o(1) put and get operations

        but how can we keep track of what has been used the least?
            can we have a minHeap? for the timestamps of when something was last
used? and have it be a pair or timestamp and key. if it is used, we update the
timestamp

            this was when we are at max capacity we look in o(log n) and then we
reorder with (log n)

            runtime: o(1) + o(log n)
            memory: o(capacity)

    optimize
        how can we keep the o(1) average time?
            i saw that this problem involves linkedlists
            10 min left

            so with a linkedlist or a doubly linked list

            capacity 2
            cache = [
                2: 2,
                1: 1
            ]
            1<->2
            h   t

            what if to the cache. every time we add a value. taht value is a
node, and the last value we have worked with now points to this new one.

            1->2->3

            and if 1 is uses, we just make the last one point to it and update
wehre 1 is pointing to no prev last points to curr

            2->3->1

            and if we use 3

            2 now points to 1 and 1 to 3
            prev points to next
            last points to curr

            okay, the key or the valus is the node?
*/

struct Node {
    int key, val; // key, val, so we have all the info to look into cache
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* first; // dummy first
    Node* last; // dummy last

    void remove(Node* node){
        /*
        Disconect the node
        prev<->node<->next
        ->
        prev<->next
        */
        node->prev->next = node->next; // prev points to next
        node->next->prev = node->prev; // next points to prev
    }

    void insertLast(Node* node){
        /*
        Connect node between second to last and last
        prevLast<->last
        ->
        prevLast<->node<->last
        */
        node->prev = last->prev; // node prev is the prev of last
        node->next = last; // node next is last
        last->prev->next = node; // the node behind last now points to node
        last->prev = node; // last prev points to node
    }

public:
    LRUCache(int capacity) {
        /*
        Initialize the LRU cache with positive size capacity.
        */
        this->capacity = capacity;

        // create dummy pointers
        first = new Node(0,0);
        last = new Node(0,0);
        first->next = last;
        last->prev = first;
    }

    int get(int key) {
        /*
        Return the value of the key if the key exists, otherwise return -1.
        */
        // if no key, return -1
        if (this->cache.find(key) == this->cache.end()) return -1;

        Node* node = cache[key];
        remove(node); // remove node from doubly linkedlist
        insertLast(node); // add to the end

        return node->val;
    }

    void put(int key, int value) {
        /*
        Update the value of the key if the key exists. Otherwise, add the
        key-value pair to the cache. If the number of keys exceeds the capacity
        from this operation, evict the least recently used key.
        */
        
        // if it already exists, update and move it to the end
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->val = value; // update value
            remove(node); // remove from list
            insertLast(node); // add at the end of list
            return;
        }

        // if capacity is at its max, remove
        if(cache.size() == capacity){
            Node* lru = first->next; // point to the first value
            remove(lru); // remove it from doubly linked list
            cache.erase(lru->key); // remove from cache
            delete lru; // delete ListNode
        }

        // add value to the end
        Node* node = new Node(key, value); // create node with key, value
        cache[key] = node; // store it in the cache
        insertLast(node); // add to the end
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

 /*
 This is a very interesting problem. I really like all the creativity involved, I feel like design questions
 are one level above normal leetcode problems. Here we have to take everything we know and apply it to something
 similar to reality.

 I liked my analysis, I feel like I had the logic ready and only the implementation was at fault right now.

 I like the idea of having a first and last dummy pointer just for us to avoid worrying about going out of bounds

 The main operations are, disconnect a node from the list and connect it between the last and second to last
 node.

 I had a good idea with the minHeap but it didn´t complied with the runtime requirements.

 I knew this problem had to do with linkedlists so i dont know how to feel about my performance.

 But I like that even though i only knew that linkedlist were involved, I knew exactly how to apply this to 
 make it optimal

 How would I come up with this solution on my own? or what would be a good approach for this system
 design questions.


 1. Lista las operaciones y su complejidad requerida.
   (get O(1), put O(1))

2. Ataca cada operación por separado. ¿Qué estructura hace cada una eficiente?
   (buscar por key → hash map; rastrear orden → ?)

3. Para la operación difícil, razona por qué las estructuras obvias fallan.
   (heap es O(log n), array es O(n) para remover de en medio)

4. Busca la estructura que cumple el requisito exacto.
   (remover de en medio + insertar en extremo en O(1) → doubly linked list)

5. Conecta las estructuras. ¿Cómo va una a la otra?
   (hash map guarda punteros a los nodos de la lista)

6. Asegura la sincronización. ¿Qué info necesita cada estructura para 
   actualizar la otra?
   (el nodo necesita la key para borrar del map al evictar)
 
 */
