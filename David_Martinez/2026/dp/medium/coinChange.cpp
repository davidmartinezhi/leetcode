#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /*
        30 min 10 seconds left
        info
            input
                - int array coins, represents coins of different denominations
                - int amount
                
            output
                - fewest number of coins to make that amount
                - if amount of money cannot be made by any combination return -1
                
            constraints
                - range of sizes of coins array? [1,12]
                - range of values each coind denomination can have? [1, int_max]
                - range of values that amount can have? [0, 10k]
                - we can assume we have an infinitre amount of each coin
                
        example
            coins = [1,2,5], amount = 11
            -> 3
            
            5+5+1
            
            26 minutes left with 30 seconds
            
            coins = [2], amount = 3
            -> -1
            
           coins = [1], amount = 0
           -> 0
           
         brute force
            do a backtracking permutation until we have reached amount with the coins.
            runtime exponential
            memory o(amount) in stack calls
        
        optimize
            we want to avoid recalculating info so much
            sounds like a dp knapsack problem unbounded
            
            coins = [1,2,5], amount = 7
            
             0,1,2,3,4,5,6,7
          [1,0,1,1,2,2,1,2,2]
            
        walkthrough
            create an array of size amount
            first value , in index 0 is 1.
            on each index we traverse the coins array and if not out of bounds.
            value is the min between index-coin + 1. we start with every value set to inf
            
            runtime: o(n*amount)
            memory: o(amount)
            
        test
            - amount 0
            - amount unreachable
            - amount within reach
            
            15 min left
        */
        
        // edge case: amount 0
        if(amount == 0) return 0;
        
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        
        // traverse each value in amount, index
        for(int i = 1; i < amount+1; i++){
            //traverse all coins
            for(int coin : coins){
                // if index - coin is inbounds
                if(i-coin >= 0){
                    dp[i] = min(dp[i-coin] + 1, dp[i]); // set min
                }
            }
        }
        
        return (dp[amount] > amount) ? -1 : dp[amount];
    }
}; // the size of the dp table, has to be of the possible status.
