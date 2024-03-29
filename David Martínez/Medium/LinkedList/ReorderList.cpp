#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode * next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution {
public:
    void reorderList(ListNode* head) {
    /*
    
    info
        input: head of a singly linked-list   
        
        reorder the list:
            original: 0 -> 1 -> 2 -> ... -> n-2 -> n-1 -> n
            reordered: 0 -> n -> 1 -> n-1 -> 2 -> n-2 -> ...
        
        
        constraints:
            number of nodes in range [1, 50000]
            node.val ranges [1, 1000]
        
    example
        
        1 -> 2 -> 3 -> 4 
        ouput: 1 -> 4 -> 2 -> 3
        
        1 -> 2 -> 3 -> 4 -> 5
        output: 1 -> 5 -> 2 -> 4 -> 3
    
    brute force:
        
        for each next node, reverse the rest of the linked list
        runtime: O(n^2)
        space: O(1)
        
    optimmize:
        
        Reverse the second half of the list
        Now having 2 lists, merge them
        
        runtime: O(n)
        space: O(1)
        
    walkthrough:
        traverse to find size
        move a pointer to the middle of the list and reverse it
        
        now we have a reference to the head of both heads
            first head point it to second and move to next
            second head point it to first and move to next
            
            At last check if we need to point to any nodes that need mergin
            
    test:
        Todo:
            -Check correct index of middle. correct
            -Check correct reversal of the half. correct
        
    
    */
            //declare variables
        vector<ListNode*> nodes;
        ListNode * node = head;

        //fill array
        while(node){
            nodes.push_back(node);
            node = node->next;
        }

        //traverse until middle of array
        //get size of array
        int n = nodes.size();

        /*
        head = [1,2,3,4]
        4/2 = 2-1 = 1

        head = [1,2,3,4,5]
        
        */

        //even size
        for(int i = 0; i < n/2; i++){
            nodes[i]->next = nodes[n-i-1];
            nodes[n-i-1]->next = nodes[i+1];
        }

        //set last value pointer
        nodes[n/2]->next = nullptr;   

    /*
        ListNode* aux = head;
        
        //Get size
        int size = 0;
        
        while(aux != nullptr){
            size++;
            aux = aux->next;
        }
        
        //Reverse second half 
        ListNode * head2 = reverseAtPosition(size/2, head);
        
        //Merge both lists
        ListNode * prevAux;
        ListNode * prevHead2;
        
        aux = head;
        
        while(aux != nullptr && head2 != nullptr){
            prevAux = aux;
            aux = aux->next;
            prevAux->next = head2;
            
            prevHead2 = head2;
            head2 = head2->next;
            prevHead2->next = aux;
        }
        
        //merge difference in nodes
        if(size % 2 != 0){

            prevHead2->next = head2;
            head2->next = nullptr;
        } 
    */
   
    }
    
    ListNode * reverseAtPosition(int middle, ListNode * node){
        //reverse linked list from any point, returns pointer
        ListNode * prev = nullptr;
        ListNode * curr = node;
        
        
        //move to middle
        int count = 1;
        while(count < middle){
            curr = curr->next;
            count++;
        }
        
        //start reversing
        while(curr != nullptr){
            
            ListNode * next = curr->next;
    
            curr->next = prev;
            
            prev = curr;
            curr = next;
          
        } 
        
        //return node to the reversed second half of the list
        return prev;
    }
};

//50 minutes

/*

    -Solución optima diseñada en 20 minutos
    -Implementación fue lo tardado, pero si estaba para terminar a tiempo en 40 minutos total

    -Mi error fue no poner que el ultimo nodo a nullptr, debo ser explicito.

    -Otra manera de llegar a la mitad de la lista es con un apuntador fast y otro slow
        slow recorre la lista 1 x 1
        fast recorre la lista 2 x 2

        cuando fast sea nullptr o fast->next sea nullptr, slow estará en la mitad
        Esto quiere decir que así sabemos si la length es size even or non

        El reverse sería en el slow pointer, que es la mitad


Nueva nota:
Se nota que he agarrado más experiencia en la solución de problemas, lo hice en 22 minutos y con muchas
menos lineas de codigo. 

Buena respuesta.

*/