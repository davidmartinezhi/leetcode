#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      /*
      45 min left
        INFO
            input
                - array prices where prices[i] is the price of a stock on the ith day
                
            
            output
                - max profit we can achieve
                    - we can do as many transactions as we want but there's a cooldown
                        - the cooldown is, if we sell, we cannot inmediately buy the next day
            
            constraints
                - range of sizes the array can have? [1, 5k]
                - range of values each price could be? [0, 1k]
            
            
        example
            Input: prices = [1,2,3,0,2]
            Output: 3
            transactions = [buy, sell, cooldown, buy, sell]  
            
            this problem feels like i have to use backtracking, but im sure i can precompute
            previous states and get a value from that.
            so the problem is a dp problem.
            
            Input: prices = [1]
            Output: 0    
            
        brute force
            backtracking
                - on each day we decide if we sell, and if we sell, we dont buy the next day
                and do that for all prices and possible profits or losses.
                
                runtime: o(2^n) we buy or sell for each price
                memory: o(1)
                
        optimize
            best conceivable runtime: o(n) we have to traverse all prices at least once
            
            what are the possible states we can have?
                we buy
                we sell
                we skip
                
                we buy when we see the lowest current value
                we sell when we see a profit
                    , but in this case we skip the next value as a possible sell
                    , so we have to decide if this profit is bigger than the profit from the prev day
            
            currMin = 1
            
               i
            [1,2,3,0,2]
            [0,0,0,0,0]
            
            currMin = 1
            we get to value 2 and theres a profit
            
            2-1 = 1
            
            
            
                 i
            [1,2,3,0,2]
            [0,1,0,0,0]
            
            currMin = 1
            we get to value 3
                we have a profit
                whats bigger, this profit or the profit from selling yesterday
                3-1 = 2
                 
                   i
            [1,2,3,0,2]
            [0,1,2,0,0]
            
            currMin > current number
            we set a new min
            currMin = 0
            
            we cant buy , but what if we didnt buy yesterday? what the biggest profit until now?
            1
            
            
                     i
            [1,2,3,0,2]
            [0,1,2,1,2] 
            1 is the current profit if we bought yesterrday and we are abt to sell
            
            currMin = 0
            
            we have a profit
            2-0 = 2
            if we sell today, 2
            
            
            okay, i feel like im very close
            
            26 min left
            
            min = 1
            [1,2,3,0,2]
          [0,0,0,0,0,0]
          
          1-1 = 0
          
            [1,2,3,0,2]
          [0,0,1,0,0,0]
          
          2-1 = 1
          
            [1,2,3,0,2]
          [0,0,1,2,0,0]
          [f,f,t,t,f,f]
          3-1 = 2
          
          
            [1,2,3,0,2]
          [0,0,1,2,0,0]
          [f,f,t,t,f,f]
          3-1 = 2
          
            [1,2,3,0,2]
          [0,0,1,2,0,0]
          min = 0     
          
            [1,2,3,0,2]
          [0,0,1,2,0,2]
          [f,f,t,t,f,t]
          
          min = 0  
          2-0 = 2
          
          [0,0,1,2,0,2]
          [f,f,t,t,f,t]
          [0,0,1,2,1,3]
          
          now the profit im sure must be calculate from this resulting array
          
          is t, sum and see how much profit, but skip the next value, i could do this recursively
            and runtime would still be o(n)
            memory: o(n) stack calls in worst case
            
            if we have a true and the next one is a true, we skip it, until we get to the end
            we have a max always with us
                
                
          [0,0,1,2,0,2]
          [f,f,t,t,f,t]
          [0,0,1,2,1,3]
          
          the value of a true is the true + the value in a previous false
          the value in a false is the value of the last true, if that true is not yesterday
            
            
       test
        - profit can be made
        - profit cannot be made

      */  
        /*
        int n = prices.size();
        int currMin = prices[0];
        int maxProfit = 0;
        
        vector<int> dp(n,0);
        vector<bool> sold(n,false);
        
        for(int i = 0; i < n; i++){
            int price = prices[i];
            
            // price is less than currMin
            if(currMin > price){
                currMin = price;
            }
            
            //
            else{
                int profit = price - currMin;
                if(profit > 0){
                    dp[i] = profit;
                    sold[i] = true;
                }
            }
        }
        
        // now we have all possible profits, and we know when we sold
        
        // now we want a mix that get´s the biggest profit
        // 11 minutes left
        vector<int> dp2(n,0);
        
        for(int i = 0; i < n; i++){
            for(int j = i-1; j >= 0; j--){
                if(sold[i]){
                    if(!sold[j]){
                        dp2[i] = dp[i] + dp[j];
                        break;
                    }
                }
                else{
                    // j is i-1 and its false
                    if(j == i-1 && sold[j]) {continue;}
                    else {dp2[i] = dp[j]; break;}
                }
            }
        }
        
        
        int maximumVal = 0;
        for(int num : dp2){
            maximumVal = max(maximumVal, num);      
        }
        
        return maximumVal;
        */
        
        int n = prices.size();
        if(n <= 1) return 0;

        int held = -prices[0];   // si compro el día 0
        int sold = 0;            // no puedo haber vendido el día 0 con ganancia real
        int rest = 0;            // no hago nada

        for(int i = 1; i < n; i++){
            int prevHeld = held, prevSold = sold, prevRest = rest;

            held = max(prevHeld, prevRest - prices[i]);   // mantengo o compro (desde rest)
            sold = prevHeld + prices[i];                   // vendo lo que tenía
            rest = max(prevRest, prevSold);                // descanso o vengo de cooldown
        }

        // al final, el mejor es haber vendido o estar descansando (no tener acción)
        return max(sold, rest);
    }
};

/*
Cada variable (held, sold, rest) guarda la mejor ganancia posible si terminas el día en ese estado



*/
