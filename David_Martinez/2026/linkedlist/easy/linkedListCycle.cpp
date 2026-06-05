#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        /*
        info
        
                    input
                        - head of ll
                    
                    todo
                        - determine if theres a cycle, a node we have seen before can be reached
                            from the next position from the tail
                    
                    
                    output
                        - true if there is a cycle in the ll, else false
                    
                    
                    constraints
                        - range of sizes the ll can have? [0, 10k]
                        - range of values inside nodes? not relevant rn
                        
        example
                                          f
                                          s 
                    Input: head = [3,2,0,-4], pos = 1
                    -> true
                    
                            f
                            s
                    head = [1,2], pos = 0
                    -> true
                    
                    Input: head = [1], pos = -1 
                    -> false
                    
        brute force
            slow and fast node
            slow moves 1
            fast moves 2
            
            move until fast or fast->next is nullptr
            or until fast and slow are the same node
            
            runtime: o(n)
            memory: o(1)
            
            5 min mark
            
        optimize
            best conceivable runtime: O(n)
            
        test
            - even number of nodes list
            - odd number of nodes list
            - only one node
            - head is nullptr  
            
                       f
                 s
            [3,2,0,-4], pos = -1
        */
        
        
        // edge case: head is nullptr
        if(!head) return false;
        
        // edge case: only one node
        if(!head->next) return false;
        
        // set pointers to traverse
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) return true;
        }
        
        return false;
        
    }
}; // 14 min with test and all
