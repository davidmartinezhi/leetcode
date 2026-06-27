#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /*
        45 min left
        info
        
            input
                - integer array "nums" representing money on each house
            
            
            output
                - max amount you can rob tonight
            
            
            constraints
                - adjacent houses cannot be robbed
                - range of sizes that nums can have? [1, 100]
                - range of values that each house can have? [0, 400]
            
            
        example
            43 min 13 seconds left

            Input: nums = [1,2,3,1]
                          [1,2,4,4]
                          on each step we have to decide, do we have a bigger value in my current step
                          + the money 2 steps ago? or is the previous step more money
            Output: 4

            Input: nums = [2,7,9,3,1]
                          [2,7,11,11,12]
            Output: 12
            
            we have to get all possible combinations where we steal from one house and skip the next one to rob another
            
            it is a dp problem. we have to traverse without recomputing.
            
        brute force
            well i went to the dp solution first
            runtime: o(n)
            memory: o(n)
            
            i can have a dp aux array.
            on each step.
                if i - 2 is less than 0. the value is just nums[i]
                else the current value in dp[i] is dp[i-2] + nums[i] or dp[i-1] whichever is max
                
        optimize
            can we improve memory? we only need 3 states, so i could reduce the aux array
            to a fixed array of size 3 and make the memory: o(1)
            
        test
            - even houses have the largest sum
            - same with odd houses
            - a mix  
            
                  i
            [2,7,9,3,1]
            [2,7,11,0,0]
            
            currSum = 9+2 or 7 = 11, 
        */
        
        /*
        int n = nums.size();
        vector<int> dp(n);
        
        for(int i = 0; i < n; i++){
            int currSum = nums[i]; // current amount of money
            if(i - 2 >= 0) currSum += dp[i-2]; // add sum before adj house
            
            if(i > 0) dp[i] = max(currSum, dp[i-1]);
            else dp[i] = currSum;
        }
        
        return dp[n-1]; // 27 mins left
        */
            
        int n = nums.size();
        
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        
        for(int i = 2; i < n; i++){
            int currSum = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = currSum;            
        }
        
        return prev1;
    }
};
