#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /*
        13 min left
        info
                - peak element is greater than its neighbors
        
            input
                - int array "nums" 
                
            todo
                - find a peak element
            
            output
                - index of peak element
            
            constraints
                - if a neighbour is out of bounds its considered lesser in value
                - range of sizes the array can have? [1, 1000]
                - range of values that the numbers can have?  [int_min, int_max]
                - there are no adjacent numbers with the same value
                
            example
                Input: nums = [1,2,3,1]
                Output: 2    
                
                index of 3 is 2
                
                Input: nums = [1,2,1,3,5,6,4]
                Output: 5    
                index 5 is where the value 6 is
                
            brute force
                8 min left
                
                check if array is of size 1, if so thats the peak
                check if its more
                    on first element check if element to the right is lesser
                    on last element check if element on the left is lesser
                send a fixed window of 3 places i-1, i, i+1 to check for peaks in the body
                
                runtime: o(n)
                memory: o(1)
                
            test
                - peak if on left corner
                - peak is on right corner
                - peak is in the body
                - no peak?
        
        */
        
        /*
        int n = nums.size();
        
        // edge cases
        
        // array of size 1
        if(n == 1) return 0;
        
        // peak in the first element
        if(nums[0] > nums[1]) return 0;
        
        // peak in the last element
        if(nums[n-2] < nums[n-1]) return n-1;
        
        // look in the body
        for(int i = 1; i < n-1; i++){
            // 3 minutes left
            if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
                return i;
            }
        }
        
        return -1; // not found ?
        // 2 minutes left, accepted and all tests apssed. this problems felt pretty easy
        */
        
        /*
             e
             s
             m
        [1,2,3,1]
        
        2 + (3-2)/2 = 0 = 1
        
        */
        int left = 0, right = nums.size() - 1;
        
        while(left < right){
            
            int mid = left + (right - left) / 2;
            
            if(nums[mid] > nums[mid+1]){ // right is lesser: peak on mid or left
                right = mid;
            } else { // right is bigger: peak is to the right
                left = mid + 1;
            }
        }
        return left;
    } 
};

/*
Exacto, esa imagen de olas (o montañas) es perfecta y captura la lógica completa. Tu intuición está bien.
Tu modelo mental:
elijo el valor medio y miro la pendiente:

derecha bajando (nums[mid] > nums[mid+1]):
   la cima está hacia la IZQUIERDA (o es mid mismo)
   → right = mid

derecha subiendo (nums[mid] < nums[mid+1]):
   la subida sigue hacia la DERECHA, la cima está allá
   → left = mid + 1
Eso es justo el algoritmo. La imagen de la montaña funciona porque:
Si vas bajando hacia la derecha, sabes que venías de algo más alto (o mid es la cima). La cima está donde estabas o detrás. Vas hacia la izquierda.
Si vas subiendo hacia la derecha, la cima está más adelante (la subida tiene que terminar en una cima, porque el array acaba y el borde es -∞). Vas hacia la derecha.
Un detalle que refuerza tu imagen:
Cuando subes a la derecha y mueves left = mid + 1, descartas mid con seguridad porque mid NO puede ser la cima (su vecino derecho es mayor, así que mid no es pico). Por eso mid + 1 y no mid.
Cuando bajas y mueves right = mid, dejas mid incluido (mid, no mid - 1) porque mid SÍ podría ser la cima (su vecino derecho es menor; falta confirmar el izquierdo, pero mid sigue siendo candidato).
Esa asimetría (mid+1 cuando subes, mid cuando bajas) sale directo de tu imagen: subiendo, mid no es cima, lo descartas; bajando, mid puede ser cima, lo conservas.
Tu imagen de olas es la forma correcta de recordarlo. "Sigo la pendiente hacia arriba hasta llegar a una cresta." Como las olas suben y bajan y el array termina en bordes -∞, siempre hay una cresta hacia donde subes. Guarda esa imagen, es la que te va a hacer reconstruir el algoritmo en interview sin memorizarlo.

okay, this is a slope, we just want to continue going up the mountain until we find the point of falling.
eventually we´ll find a peak or we'll get to the border where everything after that is lesser

Very interesting problem, i never thought of binary earch this way.

if we can ignore half of the rest of the values all the time with a good certainty. that means that
binary search is the way to go.

runtime: log n
memory: o(1)
*/
