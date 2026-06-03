struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /*
        info
            input
                - head of a singly linked list
                
            todo
                - reverse the list
            
            
            output
                - returned reversed list
            
            
            constraints
                - range of sizes of the list? [0, 5k]
            
            
        example
        
            Input: head = [1,2,3,4,5]
                                1->n
                             p  c  n
                         
                            
            Output: [5,4,3,2,1]
            
        bf
            get every node to an array and move the directions
            
            runtime: o(n)
            memory: o(n)
            
        optimize
            best conceivable runtime: o(n)
            prev curr and next node
            curr points to prev
            prev becomes curr
            curr becomes next
            next advances
            we return when curr is nullptr
            we return prev
            
        test
            - ll of size 0
            - ll of size 1
            - ll of size bigger than 1
            
                  p  c  n
            n<-1<-2<-3->n
        */
        
        // edge case: head is nullptr
        if(head == nullptr) return head;
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while(curr != nullptr){
            ListNode * nxt = curr->next;
            
            // set new direction
            curr->next = prev;
            
            // rearrange pointers
            prev = curr;
            curr = nxt;
            
        }
        
        return prev;
    }
}; // 12 min

/*
This problem was really easy, specially when you remember the pattern of having the prev curr and next.
I guess having a prev here is almost as it being a dummy value that´s useful.

*/
