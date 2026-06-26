#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        info
            input
                - int array "nums"
            
            
            output
                - sum of subarray with the largest sum
            
            
            constraints
                - range of sizes the array can have? [1, 100k]
                - range of values each num can have? [-10k, 10k]
            
            
        example
        
        43 minutes 20 seconds left
        
            Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
            Output: 6
            
            Input: nums = [5,4,-1,7,8]
            Output: 23
            
            Input: nums = [-1]
            Output: -1
            
        brute force
            have an int to store the masSum
            for each num
                traverse the rest of the nums and keep getting a currSum 
                    that currSum is always compared against the maxSum
                    
            runtime: o(n^2) for each num, we traverse the rest of the nums
            memory: o(1)
            
        optimize
            best conceivable runtime: o(n) we have to at least traverse each num once
            
            is it possible?
            
            we have to traverse a calculate, while avoiding recomputation
            my instinct tells me this has to do with dp
            
        
            can i traverse with a single pointer
            and just update a variable when a condition is met on the next value?
            
            maxSum = -2, 1, 4, 5, 6
            currSum = -2 + 1 or 1 = 1, 1 + -3 or -3 = -2, -2 + 4 or 4 = 4
                        4 + -1 or -1 = 3, 3+2 or 2 = 5, 5+1 or 1 = 6
            
                                          i
            Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
            
            
            maxSum = -2, -1
            currSum = -2, -2+-1 or -1 = -1
                                i
            Input: nums = [-2, -1]
            
            
            
            
        test
            - only negative numbers
            - only positive numbers
            - mix
        
        */
        
        int maxSum = nums[0], currSum = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            currSum = max(currSum + nums[i], nums[i]);
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    } // 31 minutes left
};
