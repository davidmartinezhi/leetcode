#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        /*
        info
                input
                    - linekdlist node to be deleted
                    
                
                output
                    - void
                
                
                constraints
                    - all values in ll are unique
                    - its guaranteed that we are not in the last node
                    - number of nodes in the list that i could have? 1 and 1000
                    
        example
            head = [4,5,1,9], node = 5
                  c n
            -> [4,1,9]
            
        test
            - we are in a node second to last
            - we are in a node wither at the beginning or in the middle of the body
        
        */
        
        // point to next node
        ListNode* nextNode = node->next;
        
        //move all its values to the current node
        node->val = nextNode->val;
        node->next = nextNode->next;
        
        //delete the next node
        delete nextNode;
        
    }
}; // 7 min

/*
Super easy and good just to warmp up
*/
