#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /*
        info
            input: integer array "coins", and integer "amount"
            
                each index represents different denominations
                
            output: fewest nummber of coins that you need to make up the amount given
                If the amount of money cannot be made, return -1
                
            constraints:
                -We have infinite number of each kind of coin
                -array coins length is between 1 and 12
                -each coin index has value between 1 and INT_MAX
                -integer amount is in range go from 0 to 10,000
                
            
                
        example
            coins = [1,2,5], amount = 11
            -> 3
            
            coins = [2], amount = 3
            -> -1
            
            coins = [1], amount = 0
            -> 0
            
        brute force
            resursivity where we tak each possible path for all coins
            include to collection or exclude
            
            complexity:
                time: O(2^n)
                extra space: O(>n)
        
        optimize
            It's a dp problem
            Unbounded knapsack problem
            
            time: O(coins * amount)
            extra space: O(coins * amount)
            
        walktrhough
            create matrix
            traverse matrix
                for each index get minimum of index to the left and from index up
            return result or -1
            
        test
            amount can't be made
            amount can be made
            
            special cases:
                amount is 0
                coins length is 1
            
            hot-spots:
                 initialization of vector inside another vector
                 coins size + 1 or coins size in traversal
                
        */
       
        /*
        //set variables
        int n = coins.size();
        
        //matrix
        vector<int> aux(amount+1);
        vector<vector<int>> dp(n+1, aux);
        
        //traverse the matrix
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= amount; j++){
                //first col
                if(j == 0){
                    dp[i][j] = 0;
                }
                //first row
                else if(i == 0){
                    dp[i][j] = 1e5;
                }
                //if current value is greater, we skip
                else if(coins[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }
                //comparison
                else{
                    dp[i][j] = min(1 + dp[i][j - coins[i-1]], dp[i-1][j]);
                }   
            }
        }
        
        //check if the amount of money could be made
        if(dp[n][amount] > 1e4) return -1;
        
        
        return dp[n][amount];
        */

        //declare aux vector for dp
        vector<int> dp(amount+1, 1e5);
        dp[0] = 0;
        
        
        //traverse the array
        for(int i = 1; i < dp.size(); i++){
            
            //traverse from first index to i
            for(int j = 0; j < coins.size(); j++){
                
                if(i>=coins[j]){
                    //si la moneda puede completar la cantidad de dinero actual
                    //checa si usa menos monedas con la cantidad actual o con la que llega al valor anterior
                    //más agregar la nueva. ej: min(1+2+2, 0 + 5) 2 (0+5)
                    
                    //en la celda actual de i, el numero que tratamos de alcanzar
                    //checamos todas las monedas para ver si alguna lo lleva a esa cifra
                    //si una cifra previa, más una nueva moneda lo lleva a la cifra
                    //pone el que ocupe menos monedas
                    dp[i] = min(dp[i],1+dp[i-coins[j]]);    
                    
                }
                            
            }
        }
        
        
        if(dp[amount] == 1e5) return -1;
        
        return dp[amount];
    }
};

/*
Time: 37 minutes with notes
Complexity: 
    time: O(array size * amount)
    extra space: O(array size * amount)

Notes:
    Este problema me encantó porque me hizo crecer mucho.
    Tuve que adentrarme a estudiar y comprender temas que ni siqueira sabía que existían.
    Por ejemplo tuve un mejor entendimiento de programación dinamica y lo que la conforma
        Como backtracking, memoization, tabulation. Top-down and bottom-up approach.

    Seguiré practicando y mejorando mis habilidades aún más. Pero por el momento solo puedo decir
    que hice un buen trabajo agarrandole la onda a este problema, trataré de hacer más dp problems.

    Dp me hizo hacer pensar muy diferente sobre como solucionar problemas

*/