struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        /*
        info
          input
            - head of 2 sorted ll
          
          todo
            - merge both into one sorted ll
          
          
          output
            - head of merged ll
          
          constraints
            - range of sizes the ll can have? 0, 50
            - range of values inside the node? -100 and 100
            - both lists are sorted in increasing order? or do i have to sort? they are sorted
            writen in 2:20 mins
            
        example 
                                                   p
                                p               
            Input: list1 = [1,2,4], list2 = [1,3,4]
            1, 1, 2, 3, 4, 4
            Output: [1,1,2,3,4,4]  
            
            just merge and when one hits nullptr, add everything left from the other list
            
        brute force
            have two pointers
            compare values
            the smaller gets added to the new list and that pointer traversed.
            do this until one hits nullptr
            then add everything else
            
            runtime: o(n)
            memory: o(1)
            
        optimize
            best conceivable runtime: o(n)
            its optimal
            
        test
            - both ll are the same size
            - one is empty
            - both have diff sizes
        */
        
        // edge case: one or both list are empty
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;
        
        // declare variables for comparisons and new head
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        
        ListNode newHead(0);
        ListNode* trav = &newHead;
        
        /*
                                               p
                            p
            Input: list1 = [1,2,4], list2 = [1,3,4]
            
            head  0->
            trav = 0-> 1
                       t
            
            Output: [1,1,2,3,4,4]         
        */
        
        // while not at the end of either list
        while(p1 != nullptr && p2 != nullptr){
            if(p1->val < p2->val){
                trav->next = p1; // set as new next node
                p1 = p1->next; // traverse p1
            } else{
                trav->next = p2; // set as new next node
                p2 = p2->next; // traverse p2                
            }
            
            trav = trav->next;
        }
        
        // if we are out, put everything from the list that still has node
        
        trav->next = (p1 != nullptr) ? p1 : p2;
        
        return newHead.next;
    }
}; // 17 min, 25 min refactorizando para quitar los while

/*
I felt really comfortable with this problem. I still remember the concepts of the basic traversals
but this practice sessions are helping me a lot to refresh my memory and be more aware of the patterns

*/
