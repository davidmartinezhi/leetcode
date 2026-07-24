#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /*
        45 min

        info
            input
                - int array "nums" representing amnt of money of each house

            output
                - max amount of money you can rob withouth alerting police


            constraints
                - range of sizes the array can have? [1, 100]
                - range of values each number can have? [0, 400]
                - answer is valid in a 32 bit int? ill assume yes

        42 min left

        example
            Input: nums = [1,2,3,1]
            Output: 4  

            [1,2,3,1]
            []

            Input: nums = [2,7,9,3,1]
            Output: 12      

        brute force
            backtracking
                on each idx we decide if we rob this house or not, until we get to the end
                    we cannot rob if the prev house has been robbed

                have a global maxSum variable

                runtime: o(2^n)
                memory: o(n) stack calls

        optimize
            we have subproblems that solve a problem so it is perfect for dp
            we need the max from all possible combinations

            best conceivable runtime: o(n) we have to traverse all houses at least once


        walkthrough
            [1,2,3,1]
            [1,2,4,3]
             0,1,2,3

             on each index
             we set value as max between idx and prev prev index summed
             or prev

             [2,7,9, 3, 1]
             [2,7,11,11,12]

             

        test
            - odd number of houses
            - even number of houses

        34 min left
        */

        /*
        [2,1,1,2]
        [2,2,3,0]
             i
        */
        int n = nums.size();

        int prev1 = 0;
        int prev2 = 0;

        for(int i = 0; i < n; i++){
            int curr = max(nums[i]+prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
}; // 28 min left
