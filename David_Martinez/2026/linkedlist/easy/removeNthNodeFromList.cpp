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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        info
                input
                    - head of ll
                    
                to do
                    - remove the n node from the end of the list
                
                output
                    - return the head
                
                
                constraints
                    - range of sizes the ll can have? 1 <= 30
                    - range of sizes that n can have? 1 <= size of ll
                
                
        example
        
            head = [1,2,3,4,5], n = 1
                   [1,2,3,5]
                    5 - 1 = 4
            
            head = [1], n = 1
                   []
            
            head = [1,2], n = 1
                   [1]
                   
        brute force
            traverse to get the size
                whatever size  - n
                thats where we stop
                    we create a pointer to the next one
                    point to what the next one is pointing to
                    delete the next one
                    
                runtime: o(n)
                memory: o(1)
                    
        optimize
            best conceivable runtime: o(n)
            
        test
            - remove first element
            - remove last element
            - remove element in the middle
        */
        
        /*
        head = [1,2,3,4,5], n = 2
        
        [1], n = 1
        1
        1-1 = 0
        */          
       /*
       int sz = 0;
        ListNode* aux = head;

        // traverse to get size
        while(aux != nullptr){
            sz++;
            aux = aux->next;
        }
        
        // get number of nodes to traverse before deleting
        int m = sz - n;
        aux = head;
        
        // edge case: remove head
        if(m == 0){
            head = head->next;
            delete aux;
            return head;
        }
        
        // remove node in the middle
        while(m > 1){
            aux = aux->next;
            m--;
        }
        
        ListNode* auxNext = aux->next;
        aux->next = auxNext->next;
        delete auxNext;
        return head;*/

        ListNode dummy(0, head);
        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        
        // move fast n +1 nodes
        for(int i = 0; i <= n; i++){fast = fast->next;}
        
        // move both until fast is a nullptr
        while(fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // slow is on the node prev to the one to delete
        ListNode* toDelete = slow->next;
        slow->next = toDelete->next;
        delete toDelete;
        
        return dummy.next;
        
    }
}; // 25 min

/*

slow and fast pointer, con un dummy node, es una gran tecnica

llegue a usar el dummy node para el merge de linkedlists, pero no habia pensado el utilizarlo aqui
igual para hacer la lectura de datos similar a con un array

o para siempre quedar justo detras del nodo que ocupas borrar.

muy interesane la tecnica y definitivamente la seguire usando.

*/
