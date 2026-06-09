
struct ListNode{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        /*
        info
        
            input
                - head of a ll
                
            todo
                - group all the nodes of odd idx in a group and the nodes of even idx in another
                - return reordered list with orr indices first
                - relative order of even and odds must be kept
                
                - first node is even, second is odd...
            
            
            output
                - head of reordered_list
            
            
            constraints
                - range of sizes the ll can have? between 0 and 10k 
                - range of values each node can have? not relevant rn
                
                
            // 3min
            
        example
            
            trav -> 1
            odd -> 1
            even ->
                                     t
            Input: head = [1,2,3,4,5]
            1->3->5->
            2->4
            Output: [1,3,5,2,4]
            
            int counter = 1
            oddsList 1 3 5 -> 
            evenList 2 4
            
            
            Input: head = [2,1,3,5,6,4,7]
            Output: [2,3,6,7,1,5,4]
            
        6 min ecample and walkthrough
        
        brute force
            do the counter to check if a node is odd or even
            and build a new list from there and just assign the values
            
            runtime: o(n)
            memory: o(1)
            
        optimize
            best conceivable runtime: o(n)
            memory, how can we improve it? not using a new ll
            
            have a traversal pointer that is just sending to their respective list each node
            then traverse odd list until last node and connect to first node of even list
            
            memory: o(1)
            runtime: o(1)
            
        test
            - 0 size ll
            - even size ll
            - odd size ll
            
            10 min, about to implement, sure how to do it
        
        */
        
        /*
        counter = 3
        odd = 1
        oddTrav = 1->3->2
        even = 2
        evenTrav = 2->nullptr
        
        h
        t
        
        counter = 1
        e 2->
        o 1->3
        
                e
              o
        1->2->3
        
        */
        
        // Edge case: head or head->next is nullptr
        if(!head || !head->next) return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        
        while(even && even->next){
            odd->next = even->next;
            odd = odd->next;
            
            even->next = odd->next;
            even = even->next; 
        }
        
        ListNode* odd = evenHead;
        
        return head;
        
        
            
        /*
        // Edge case: head or head->next is nullptr
        if(!head || !head->next) return head;
        
        // Declare vaiables
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        ListNode* trav = head->next->next;
        
        int counter = 0;
        
        while(trav != nullptr){
            counter++;
            
            if(counter%2 == 0){
                even->next = trav;
                even = even->next;
            }
            else{
                odd->next = trav;
                odd = odd->next;
            }
            
            trav = trav->next;
        }
        
        odd->next = evenHead;
        even->next = nullptr;
        
        return head;
        */
        
        
        
        
        /*
        // Declare variables
        int counter = 0;
        
        ListNode* odd = nullptr;
        ListNode* even = nullptr;
        
        ListNode* trav = head;
        ListNode* oddTrav = nullptr;
        ListNode* evenTrav = nullptr;
        
        while(trav){
            counter++;
            
            // Check if even
            if(counter%2 == 0){
                if(!even){
                    even = trav;
                    evenTrav = trav;
                }else{
                    evenTrav->next = trav;
                    evenTrav = evenTrav->next;
                }
            }else{
                if(!odd){
                    odd = trav;
                    oddTrav = trav;
                }else{
                    oddTrav->next = trav;
                    oddTrav = oddTrav->next;
                }
            }
            
            trav = trav->next;
        }
        
        // set both traversals to nullptr
        oddTrav->next = nullptr;
        evenTrav->next = nullptr;
        
        
        // Join both ll. 20 min mark
        oddTrav = odd;
        while(oddTrav->next){
            oddTrav = oddTrav->next;
        }
        oddTrav->next = even;
        
        return head;
        */
    }
}; 

/*
// 27 min, with tests and all. 
i know i coulve simplified eerything by checking from the start if we have between 0 ans 2, 
that made me lose time with added complexity
*/
