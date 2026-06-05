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
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /*
        info
                input:
                    - 2 non-negative ll representing 2 non-negative integers
                    - digits are stored in reverse order
                        - each of the nodes contains a single digit
                
                
                todo:
                    - add the 2 nums
                
                
                output:
                    - return sum as linkedlist
                
                
                constraints:
                    - range of sizes both ll can have? [1, 100]
                    - will they always be of the same length? no
                    - what ranges of values can the values inside the node have? [0,9]
                        - should i worry about overflowing the 32 bit int?
                        
                    - can the number have leading 0s? no
                    
                    
        example
                        11
                        346
                        564
                         9 1 0
            Input: l1 = [6,4,3], 
                   l2 = [4,6,5]
                    r = [0,1,9]
                        [9,1,0]
                   module 10 add
                   division by 10 to plus_one /10, this is plus one
                   plusOne = 0
                   r =  []
                   
                   if one node is nullptr, 
            Input: l1 = [6,4,3], 
                   l2 = [4,6,5,4]
                    r = [0,1,9]
                        [9,1,0]
                   
                   
            Output: [7,0,8]
                    3->4->6
                    5->6->4
                    8->0->1
                    plus_one = 1
            Explanation: 342 + 465 = 807.
              
            Input: l1 = [0], l2 = [0]
            Output: [0]                
        
            Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
            Output: [8,9,9,9,0,0,0,1] 
            
        brute force
            traverse both  lists
            while both are not nullptr
                sum both values
                module 10 stays
                division by 10 goes to plus_one
                
            if first is not nullptr, the next node y val plus_one and we keep the rest
            same if for second
            
            reverse both lists
            
            // 15 min left and i know how to implement it
            
        optimice
            bcr: o(n)
            runtime: o(n) traversal + reversal
            
        test
        - both ll are same size
        - lists have diff size    
        
        11 min remaining
        */
        
        // declare variables
        /*
        int to_add = 0;
        ListNode* head = l1;
        ListNode dummy(0, head);
        ListNode* prevToHead = &dummy;
        
        while(l1 && l2){
            
            // make sum
            int sum = l1->val + l2->val + to_add;
            
            // assign node val
            l1->val = sum%10;
            
            // assign value to add to next node
            to_add = sum/10;
            
            // move pointers
            l1 = l1->next;
            l2 = l2->next;
            prevToHead = prevToHead->next;
        }
        
        // if we still have a next node
        if(l1 || l2){
            if(l1){
                if(to_add > 0){
                    l1->val += to_add;
                }    
            }else{
                if(to_add > 0){
                    l2->val += to_add;
                }
                prevToHead->next = l2;
            }
        }
        else{
            // if we still have value on to_add add node at the end
            if(to_add > 0){
                prevToHead->next = new ListNode(to_add);
                prevToHead = prevToHead->next;
            }
            
        }
        
        
        return head;*/
/*
        ListNode dummy(0);
        ListNode* trav = &dummy;
        int carry = 0;
        
        while(l1 || l2 || carry){
            
            int sum = carry;
            
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum/10;
            trav->next = new ListNode(sum%10);
            trav = trav->next;     
        }
        
        return dummy.next;
*/

        ListNode dummy(0);
        ListNode* trav = &dummy;
        int to_add = 0;
        
        while (l1 || l2 || to_add) {
            int sum = to_add;
            
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;
            
            to_add = sum / 10;
            
            // reusa el nodo de la lista que exista, en vez de crear nuevo
            if (l1) {
                l1->val = sum % 10;     // reusa nodo de l1
                trav->next = l1;
                l1 = l1->next;
            } else if (l2) {
                l2->val = sum % 10;     // reusa nodo de l2
                trav->next = l2;
                l2 = l2->next;
            } else {
                trav->next = new ListNode(sum % 10);   // solo carry final
            }
            
            trav = trav->next;
        }
        
        return dummy.next;
    }
    
};


/*
Me senti bastante comodo en este problema

Cometi el error de hacer mal el ejemplo y leer mal, estoy muy desvelado hoy

Crei que tenia que recorrer las listas y luego reversear. ademas esrtaba tratando de no crear una list nueva


Pero me gusto que este ejercicio es similar al merge two linked lists
    en que abos recorren dos listas.

    Pero la diferencia es que en esta fucionas info de ambos nodos en otro.

    En el otro un pointer esta on hold mientras se trabaja con el otro.

    Esto hizo que quisiera hacer el approach de tomar hasta que uno sea nullptr y luego ya ver queonda
        con lo sobrante. que eso aplica cuando tienes un pointer esperando

    Pero para el approach con este problema de addTwoNumbers si aplica que ientras cualquier valor exista
    sigue el traversal, este es el valor que agregaremos al resultado. si este nodo existe usalo, sino
    ya lo omitimos.

    Me parecio muy interesante ese approach, creo que es una buena tecnica para distintos escenarios
    me facilita la vida en escenarios distintos. 

En fin, con mi approach de llegar hasta que uno sea nullptr y luego ver que hacer de ahi, me complique la vida
y estaba haciendo muchos ifs anidados, que si pueden funcionar pero me estaban complicando la vida y luego
por andarme peleando por como es que determino cuando agregar un nuevo nodo o solo sumar a uno restante, etc.
es que perdi mucho tiempo.

Si lo mejor es seguir creandolo. y ya luego puedo mencionar optimizacion y con eso ya pongo lo anidado.
mi solucion si funciona pero es checar el carry hasta el final.



Ambos: estructura dummy + trav + recorrer dos listas

Add:   COMBINA (suma), avanza AMBOS, crea nodos nuevos,
       while(l1 || l2 || carry), procesa todo hasta el final

Merge: SELECCIONA (menor), avanza UNO, reusa nodos,
       while(l1 && l2) + pega el resto, no necesita procesar el resto



*/
