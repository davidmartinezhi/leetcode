#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        /*
        30 min left

        info
            input
                - array nums
                    - all nums are unique
                - int target

            output
                - num of possible combinations that add up to target


            constraints
                - all numbers in the array are unique
                - is the num of combinations inside a 32 bit int?
                - range of sizes the array can have? [1, 200]
                - range of values each number can have? [1,1k]
                - range of values target can have? [1,1k]

        28 min left

        example
            Input: nums = [1,2,3], target = 4
            Output: 7
            Explanation:
            The possible combination ways are:
            (1, 1, 1, 1)
            (1, 1, 2)
            (1, 2, 1)
            (1, 3)
            (2, 1, 1)
            (2, 2)
            (3, 1)
            Note that different sequences are counted as different combinations. 

            This is an unbounded knapsack problem

        brute force
            recursively add a number until it reaches or passses target
            if it reaches exactly, we add one to sum

            runtime: o(target^n) we can add until target, all numbers

        optimize
            this problem can be solved using dp so we dont have to recompute

            This is an unbounded knapsack problem

            nums = [1,2,3], target = 4

            [1,2,3]
          [0,0,0,0] size target

          on each index starting from 1
          if index - number is equal or greater than 0. the sum in that position + 1
          is the value

          we return the last idx.

          runtime: o(target*size of vector)
          memory: o(target)

        test
            - we can reach target
            - we cannot reach target

        22 min left

            [1,2,3] target = 4
          
            [1,1,2,4,7]
             0,1,2,3,4

            [1,2,3] target = 4
          
            [1,1,2,0,0]
             0,1,2,3,4

             okay we set value at idx 0 as 1
             and we assign curr idx as curr idx + idx- num if that num is in bounds
        */

        /*
        nums = [1,2,3], target = 4
                  i
        dp = [1,1,1,0,0]
              0,1,2,3,4
        */

        vector<unsigned long long> dp(target+1, 0);
        dp[0] = 1;

        for(int i = 1; i <= target; i++){
            // traverse all nums
            for(int num : nums){
                if(i - num < 0) continue;
                dp[i] += dp[i-num];
            }
        }

        return dp[target];
    }
}; // 8 min left, only extreme edge case failed with integer overflow

/*
"cuántas formas/secuencias" y el orden cuenta        → target afuera
"cuántas combinaciones/conjuntos", orden no cuenta   → nums afuera

sería bueno checar las diferencias entre coin change 1 y 2. para ver diferencia entre tener target adentro y 
afuera.

*/
