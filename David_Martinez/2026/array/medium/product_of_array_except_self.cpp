#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        info
            input
                - integer array nums

            output
                - array answer
                - answer[i] should be equal to the product of all the elements except itself

            constraints
                - algorithm must run in o(n)
                - how big can the array size be? between 2 and 100,000
                - how small can the array size be? 2
                - what ranges of values can i expect of the numbers? -30 and 30 inclueded
                - anser[i] is guaranteed to fit in a 32 bit integer

        example
            Example 1:

            Input: nums = [1,2,3,4]
                          [1, 2, 6, 24]
                          [24,24,12,4]

            Output: [24,12,8,6]

            Example 2:

            Input: nums = [-1,1,0,-3,3]
                          [-1, -1, 0, 0, 0]
                          [0, 0,  0, -9, 3]
                          [0,0, 9, 0, 0]
            Output: [0,0,9,0,0]

        walkthhrough
            create 2 arrays of the same size as nums
            one array has on each position the product from left to right
            the other array has the product from righ to left
            the first element in answe is the index 1 of right to left
            the last element in answet is the index size - 2 of left to right
            the rest is the product of nums[i-1] * nums[i+1]

            runtime o(n)
            memory o(n)

        test
            - array with two elements
            - array with more than two elements and size even
                - the same but with odd size
        */

        int n = nums.size();

        // Declare product arrays
        vector<int> left_to_right(nums.begin(), nums.end());
        vector<int> right_to_left(nums.begin(), nums.end());
        vector<int> ans;

        // Set the product
        for(int i = 1; i < n; i++){
            left_to_right[i] = left_to_right[i-1] * left_to_right[i];
        }

        for(int i = n-2; i >= 0; i--){
            right_to_left[i] = right_to_left[i+1] * right_to_left[i];
        }

        // set value of first element
        ans.push_back(right_to_left[1]);

        // set the values in the body
        for(int i = 1; i < n-1; i++){
            ans.push_back(left_to_right[i-1] * right_to_left[i+1]);
        }

        // set the value at the last element 
        ans.push_back(left_to_right[n-2]);

        return ans;
    }
};

/*
26 MINUTES, pero ya me sabia la respuesta highkey
*/
