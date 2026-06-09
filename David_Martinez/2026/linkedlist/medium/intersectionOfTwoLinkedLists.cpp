/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode{
    int val;
    ListNode* next;

    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next){}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*
        info
            input
                - head of two singly ll a and b
                
            todo
                
            
            output
                - node where both lists intersect
                - nullptr if no intersection? no, node with value 0
            
            
            constraints
                - range of sizes the ll can have? 1 and 30k
                - is it guaranteed we have no cycles on the linkedlists?
                - ranges of values the nodes can have? 1 and 100k
                
            4 min
            
            example
                Input: 
                intersectVal = 2, 
                listA = [1,9,1,2,4], 
                listB =     [3,2,4], 
                skipA = 3, 
                skipB = 1
                
            brute force
                have a counter for each list until the end
                whichever list is shorter, 
                    move the long list this many nodes: long list size - short list size 
                    
                then until both lists are nullptr
                
                traverse and check if the node is the same
                
                runtime: O(n+m)
                memory: o(1)
                
            optimize
                best conceivable runtime: o(n+m)
                
            test
                - list A is shorter than B
                - list B is shorter than A 
                - both lists are the same size
                
                a = 3
                         travA
                1->2->3->4->nullptr
                
                   b= 3
                         travB
                   1->2->4->nullptr
        
        */
        
        /*
        int sizeA = 0;
        int sizeB = 0;
        
        // Traverse lists to get their sizes
        ListNode* travA = headA;
        while(travA){
            sizeA++;
            travA = travA->next;
        }
        
        ListNode* travB = headB;
        while(travB){
            sizeB++;
            travB = travB->next;
        }
        
        // return trav pointers to start
        travA = headA;
        travB = headB;
        
        // move traversal of longer list to catchup with size
        while(sizeA > sizeB){
            travA = travA->next;
            sizeA--;
        }
        
        while(sizeB > sizeA){
            travB = travB->next;
            sizeB--;
        }
        
        // now traverse both pointers until the end or until they connect
        while(travA && travB){
            if(travA == travB) return travA;
            travA = travA->next;
            travB = travB->next;
        }
        
        return nullptr;
        */
        
        ListNode* a = headA;
        ListNode* b = headB;
        
        while(a != b){
            // both pointers will move until they are both nullptr or both are the same
            // both will have traverse the same distance
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }
        
        return a; // nullptr or intersection
        
    }
}; // 20 min
/*
Two travelers approach is really interesting and I would like to explore more use cases for this.

My original approach was still very explicit and understandable.

*/
