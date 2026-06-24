#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        45 minutes to go
        
        info
            - input
                - array prices where array[i] is price of a stock on the ith day
            
            - todo
                - max profit by picking a single day where to buy and a single day in the fut to sell
            
            - output
                - max profit we can achieve from this transaction
                - if no profit can be achieved, return 0
            
            
            - constraints
                - range of sizes the array can have? [1, 100k]
                - range of values each ith element can have? [0, 10k]
            
            
        example
        
            prices = [7,1,5,3,6,4]
             42 minutes to go
             
             prices = [7,1,5,3,6,4]
             -> 5
             
             
             prices = [7,6,4,3,1]
             -> 0
             
            brute force
                - have a max profit variable
                - for each number
                    - traverse every number to the right
                        compare the diff to determine max profit variable
                        
                runtime: o(n^2)
                memory: o(1)
                
            optimize
                best conceivable runtime: o(n) we have to traverse all numbers at least once
                
                [7,1,5,3,6,4]
                
                minIdx = 1
                maxIdx = 4
                1
                6
                diff = 5
                
                we traverse once
                we have a value with the index in the min value we have seen
                if a value is greater thatn that, we make it our max and get diff
                
                if a value is greater than max, set as new max and get diff
                
                if a value is smaller than smallest, set as new min and make max be invalid again
                
                runtime: o(n)
                memory: o(1)
                
            test
                - profit can be made
                    - just one min and max
                    - multiple sections with min and max
                - profit cannot be made
                    
            33 minutes and 50 seconds to go
            
            maybe the index position doesnt matter, only the number
            [7,2,5,3,6,1,4]
            min = 2 1
            max = 6 -1 4
            
             
        */
        
        /*               i
            [7,2,5,3,6,1,4]
            min 2 1
            max 6 -1 4
            maxProfit = 4
        */
        /*
        int maxProfit = 0;
        int min = prices[0];
        int max = -1;
        
        for(int num : prices){
            
            // we find a new min
            if(num < min){
                min = num;
                max = -1;
            }
            
            // we find a new max
            if(num > max){
                max = num;
            }
            
            maxProfit = (maxProfit < max-min) ? max-min : maxProfit;
        }
        
        return maxProfit;
        */
       /*

       // This one is even more efficient
        int i = 0;
        for(int j = ...){
            max_profit = max(max_profit, prices[j] - prices[i]);
            if(prices[j] < prices[i]) i = j;
        }
       
       */
        
        // simplififed solution
        
        int minPrice = prices[0];
        int maxProfit = 0;
        
        for(int price : prices){
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }
        
        return maxProfit;
    } // 23 min left, all checked with walkthrought
};

/*
It´s good to think: For each day, if we sell, what was the best day to buy?
profit is always, price_sell - price_buy 

So i just care about thinking, if i sell today, whats my best possible profit


I just needed to track min, the max doesnt matter, just if selling today would give me the max profit

Yeah, i just need to keep track of min until today and how much profit i would get if i sell today

For each end point, whats the best starting point++

It would be good to think if there´s a reformulation where a condition is met by itself.
Instead of me having to do it so explicit.

Overall it was a good solution
*/
