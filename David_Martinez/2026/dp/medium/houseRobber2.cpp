#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /*
        28 min left
        info
            input
                - int array "nums"

            output
                - max amount of money we can rob without crobbing adj houses

            constraints
                - range of sizes the array can have? [1, 100]
                - range of values each house can have? [0, 1k]


        example
            Input: nums = [1,2,3,1]
            Output: 4

            nums = [1,2,3]
            -> 3


        brute force
            do backtracking
                on each idx rob or not rob.
                not rob if the prev idx was robbed
                we can have an array to dictate what we have visited or robbed

            runtime: o(2^n)
            memory: o(n) stack calls

        optimize
            we need to get max from all possible combinations of robs
            its dp

            best conceviable runtime: o(n) we have to traverse all houses at least once
        23 min left
            [1,2,3,1]
            [1,2,4,4]

            we can get rid of the last house being connected to the first one thing
            by running twice.

            one from idx 0 to n-2
            another from 1 to n-1

        have an array of size n with all values as 0
        each index is nums at that index plus dp at 2 prev or 1 prev

        test
            - odd number size
            - even number size

        */

        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        return max(robTraversal(nums,0, n-2), robTraversal(nums, 1, n-1));
    }


    int robTraversal(vector<int> & nums, int start, int end){
        /*
           s   e 
        [1,2,3,1]
        [0,2,3,3]

        v = 1
        */

        int prev1 = 0, prev2 = 0;

        for(int i = start; i <= end; i++){
            int value = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = value;
        }

        return prev1;

    }
}; // 8 minutes left

/*
Solo creas el array cuando todos los estados previos son genuinamente relevantes. Si la recurrencia mira una ventana fija hacia atrás, comprimes a esas variables.


se me habia olvidado que habia quedado en checar los estados relevantes y comprimirlo a solo esos estados en lugar de crear todo el array. solo se crea el array cuando genuinamente todos los estados previos posibles son relevantes
*/
