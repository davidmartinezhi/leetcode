#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        info
            input: array prices, prices[i] is price of stock on the ith day
                - we have to max the profit by picking a single day to buy one and a 
                day in the future to sell it

            output:
                - max profit we can achieve from this transaction
                - if no profit is achievable, we return 0
            
            constraints:
                - how long can the prices array be? between 1 and 10^5
                - what ranges of values can prices[i] have? between 0 and 10^4
                - what if its not possible to get a profit? we return 0
                - is there anything else that i may be missing to ask?

        example
            Input: prices = [7,1,5,3,6,4]
            Output: 5
                

            Input: prices = [7,6,4,3,1]
            Output: 0

        brute force
            for each day (number), traverse the rest of numbers 
            and store the biggest possible number

            runtime n^2
            memory 1

        optimize
            best conceivable runtime O(n) we have to traverse
            the whole array at least once

                       j
               i
            [7,1,5,3,6,4] max_profit = 5


                     j
                     i
            [7,6,4,3,1] max=0

            runtime O(n)
            memory O(1)

        test
        - profit is possible
        - profit is not possible
        - distributions of large values to the right
        */

        // Check array of size 1
        if(prices.size() == 1) {return 0;}

        // declare variables
        int max_profit = 0;
        int i = 0;
        
        /*
                 j
               i
            [7,1,5,3,6,4] max_profit = 0
        */

        for(int j = 0; j < prices.size(); j++){
            // Get current profit and compare
            int current_profit = prices[j] - prices[i];
            max_profit = max(max_profit, current_profit);

            // check if price at j is less than price at i
            if(prices[j] < prices[i]){
                i = j;
            }
        }
        
        return max_profit;
    }
};

/*
Me tomo 20 minutos el resolverlo con explicacion y todo y checando el ejemplo

Si es real que me toma un poco llegar a la solucion pero una vez que la tengo o estoy cerca de la solucion

no hay nada que me detenga y es claro el approach

runtime o(n)
memory o(1)

Hacer estos problemas easy para volver a familiarizarme con todo siento que es bueno
para que no se me haga tan pesada la practica y ademas sirve que vuelvo a agarrar fuerza con c++

*/
