#include <vector>
using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
        info
            input
                - integer array nums

            output
                - product result of the subarray that has the largest product

            constraints
                - what range of sizes con the array have? from 1 to 20,000
                - what ranges of values can de numbers in the array have? between -10 and 10
                - is it certain that the result fits in a 32 bit integer? yes, it{s guaranteed}
                - Can we have negative numbers? yes

        example

            product = 
            Input: nums = [-2,0, -1]
                          [-2,0, 0]
            Output: 0

            Input: nums = [2,3,-2,4,8]
                          [2,6,-2,4,32, 32]
            Output: 6

        brute force:
            for each number
                traverse the rest of numbers and multiply on each one
                    always compare against the max we have seen

            runtime o[n^2]
            memory o(1)

        optimize
            best conceivable runtime o(n) we have to traverse each number at least once

            dp could be useful here, knapsack

        test
            - array of one number
            - array of all negatives
            - array of all positives
            - array with positive and negative
                - negative number in the middle
                -negative number on one side 
        */

        /*
        max_product = 2
        min 2
        max 2
                         i
        nums = [2,3,-2,4,8]
               [2,6,-2,4,32] 

        max = 0 
                     i
               [-2,0,-1]
               [-2,0, 0]  


            min_end=-2
            max_end=-2
            [-2,3,-4]
            

            okay we have to keep track of the max and min at all times
            that makes a ton of sense

        */

        /*
        max_product = 32
        min -96
        max 168
        tmp 32
                           i
        nums = [2,3,-2,4,8 -3]
        */

        int n = nums.size();
        int max_product = nums[0];
        int min_end = nums[0];
        int max_end = nums[0];

        for(int i = 1; i < n; i++){
            int temp = max_end;

            // get max
            max_end = max(nums[i], max_end * nums[i]);
            max_end = max(max_end, min_end * nums[i]);

            // get min
            min_end = min(nums[i], min_end * nums[i]);
            min_end = min(min_end, nums[i] * temp);

            max_product = max(max_product, max_end);

        }

        return max_product;

    }
};

/*
41 minutes

solucion optima, cheque el hint

for kadanes algorithm, a good question to ask myself is
me conviene seguir acumulando o empezar de nuevo? in the contiguous subarray

Si la operacion es multiplicacion, un solo valor puede flipear el signo. Necesitas trackear min y max simultaneamente porque el min de hoy puede ser el max de manana con un negativo. La pregunta ya no es "sigo o reinicio?", sino "cual de los tres candidatos (elemento solo, maxelemento, minelemento) es el mejor y peor?".
Knapsack no aplica aqui porque no tienes restriccion de capacidad ni decision de incluir/excluir elementos no contiguos. Knapsack es para cuando eliges subsets con alguna restriccion (peso, capacidad).


suma o resta contigua, kadanes algorithm
producto contiguo, tracking de max y min

Es bueno pensar en la naturaleza de lo que tenemos que hacer.
Pensar en que un numero negativo me puede voltear todo es importante para darse cuenta
de que es importante saber los extremos siempre.

Y si lo pude averiguar con los ejemplos que puse. pero debi de elegir un ejemplo con un numero non 
y otro con un numero par de numeros negativos. ese hubiera sido la clave.

Tratar de entender el comportamiento de los numeros segun las operaciones que estamos llevando
a cabo.

Hubiera sido bueno pensar en que posibles estados es que puedo estar en cada operacion
max puede ser el min times el curr, el curr o el max times el curr.

*/
