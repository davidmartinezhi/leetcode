#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
        info
            input:
                - integer array "nums"
            
            output: 
                - length of longest strictly increasing subsequence

            constraints:
                - what range of size can the array have? [1, 2500]
                - what range of values to expect on each cell? [-10000, 10000]

        example
            nums = [10,9,2,5,3,7,101,18]
            -> 4

            nums = [0,1,0,3,2,3]
            -> 4

            nums = [7,7,7,7,7,7,7]
            -> 1

            brute force
                we need to get all prev numbers that are lower in value on each cell
                its a dp problem 

                nums = [0,1,0,3,2,3]
                       [1,2,1,3,3,4]

                on each cell i
                    traverse all previous cells j
                        if(nums[j] < nums[i])
                            dp[i] = max(dp[i], dp[j]+1)

                complexity:
                    runtime: O(n^2)
                    extra space: O(n)

            optimize
                best conceivable runtime: O(n)

            test
                one repeating int on all the array
                different increasing sequences
        */

        /*
            nums = [0,1,0,3,2,3]
                   [1,2,1,3,1,1]
        */

        //creamos vector para guardar valores
        vector<int> dp;

        //recorremos cada valor de nums
        for (int num : nums) {

            //regresamos la unicación del valor donde num puede ser insertado sin romper el orden ascendente
            auto it = lower_bound(dp.begin(), dp.end(), num);

            //si es mayor que todos los numeros, lo agregamos al final
            if (it == dp.end()) {
                dp.push_back(num);
            } 
            //si no es mayor al resto de numeros, lo agregamos a su posición sin romper orden ascendente
            else {
                *it = num;
            }
        }
        return dp.size();
    /*
        //Declare variables
        int n = nums.size();
        vector<int> dp(n+1,1);

        //traverse all elements
        for(int i = 0; i < n; i++){
            //traverse all previous elements
            for(int j = 0; j < i; j++){
                //check if its a valid comparison
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                }

                dp[n] = max(dp[i], dp[n]);
            }
        }

        return dp[n];
        */
    }
};

/*
Notas:
    Time: 45+

    complexity
        time: O(n^2)
        extra space: O(n)

    Tuve la idea de un approach que también servía en tiempo O(n^2) y extra space O(n)
    Entonces estuvo bien la intuición. Solo me falto la ejecución en ese algoritmo

    La solución es muy simmilar a la solución de coinchange cuando usas memoria O(n)
    Debería de observar ambos patrones para identificarlos mejor. Hacer matríz o no

    En coin change, quería checar todas las monedas siempre, por eso el segundo loop es hasta el final
    En increasing subsequence, solo es, hasta el index actual. por eso esa es la diferencia.

    Debería de repasar dp y hacer una lista pequeña de patrones importantes y el setup



8 meses despues volcí a ver este problema y lo resolví en 20 minutos.
El concepto lo entendói bien y la solución quedo aún más limpia.
A seguir trabajando.


4 meses despues lo acabo de volver a hacer y salio igual en 20 minutos

Agregada solución O(n log n) debería investigar que otros metodos existen para ver cuales puedo usar
y simplificar trabajo
*/