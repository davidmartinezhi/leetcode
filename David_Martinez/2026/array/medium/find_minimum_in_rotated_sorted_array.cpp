#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
        info
            input
                - int array
                - sorted
                - it´s rotated between 1 and n tunes
                - unique elements

            output
                - minimum element of this array

            constraints
                - algorithm must be in log n
                - how big or small can the array be. between 1 and 5k
                - what ranges of values can the ints have between -5k and 5k


        example
                               i.j.k. 
            Input: nums = [3,4,5,1,2]
            Output: 1

                            .    i.  j        
            Input: nums = [4,5,6,7,0,1,2]
            Output: 0  
                            i
                          i.     j.  k    
            Input: nums = [11,13,15,17]
            Output: 11    

            on each number we can be on this states
                - left and right bigger, move to the left
                - left and right smaller, move to the right
                - left smaller, right bigger, move left

        brute force
            traverse the array once and store the min
                on each number compare against the min

            runtime o(n)
            memory o(1)

        optimize
            best conceivable runtime: o(log n)
            im sure i can do a binary search
        
        */

        int n = nums.size();

        // set marks
        int start = 0;
        int end = n-1;

        // look for edge cases
        if (n == 1) return nums[0]; // array of size 1
        if (nums[start] < nums[end]) return nums[start]; // array is sorted

        while(start < end){
            int m =  start + (end-start) / 2;

            if(nums[m] > nums[end]) start = m+1;
            else end = m;
        }

        return nums[start];
        
    }
};

/*

45+ minutes

Tenia la intuicion de la solucion muy solida, solo si me tarde en salir con los estados en los que podiamos estar, me comence a cuatrapear yo solo un poco

Pero me gusto que si pense en los estdo en cada step, si pude hacerlo recursivo pero
me la quise riar iterativo y si se vio bien la verdad, iba en buen camnino.

Pero bueno,  cuando hice este ejercicio en 2023 el dyi me habia ayudado a sacar
que solo importaba comparar con el ultimo

La verdad mi razonamiento y la intuicion estaban por el camnio correcto, mi error fue de implementacion con la matematica. pero eso fue principalmente por estar algo rusty. aunque en realidad si andaba super bien con la logica.
*/
