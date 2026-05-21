#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*
        info
            input
                int array nums
                move all zeroes to the end, while mantaining the order
                
            output
                - none, just moved values in place
                
            constaints
                poossible sizes of array 1 and 40k
                possible rangge of values of numbers? int min and int max
                
        example
                            j
                        i
            nums = [1,3,12,0,0]
        
        brute force, traverse array and add to a new array every non-0 number
            then add 0 until the arrays are of the same size
        then traverse new array and copy values to original array
        
            runtime: o(n)
            memory: o(n)
            
        optimize
            bcr: o(n)
            
        test
            all zeros on the left
            all zeroes in between numbers
            
        */
        /*
        int n = nums.size();
        
        int i = 0;
        
        // move i to first 0
        while(i < n && nums[i] != 0) i++;
        
        if(i == n) return; // no 0s
        
        // traverse the rest of numbers
        for(int j = i; j < n && i <= j; j++){
            if(nums[j] != 0){
                nums[i] = nums[j];
                nums[j] = 0;
                while(i < n && nums[i] != 0) i++;
            }
        }
        
        return;
        */

        // simplified solution

        int n = nums.size();
        int i = 0;
        
        for(int j = 0; j < n; j++){
            if(nums[j] != 0){
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};

// 13 min

/*
okay, muy important y no habia pensado en el que es importante poner siempre el check de que
el pointer se detenga una vez que llega al limite.

Que hace mucho sentido que exista la verdad, pero por un momento lo olvide y no lo puse

La solucion simplifidaca es hermosa porque mientras avanza j si es distinto a 0
lo hace swap con i y mueve i uno

Okay esta es la solucion similar a el problema de los k unique numbers
y todo lo duplicado al final

este es el approach del pointer estaticvo que solo se mueve para colocar valores en un lugar
mientras el otro pointer es el que se encarga de la exploracion y el traversl.

Pero si hace bastante sentido que literal solo se encargue de poner lo que no sea 0 en su lugar.
*/
