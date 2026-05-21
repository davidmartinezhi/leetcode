#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        info
            input
                - integer array nums

            output
                - sum of subarray with the largest sum

            constraints
                - range of sizes the array can have?  1 and 100,000
                - range of values a number in the array can have? -10,000 and 10,000
                - can the sum surpass the max value an int can surpass?
                - can we have negative numbers also?

        example
            max = 6
            Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
            Output: 6
        
            Input: nums = [1]
            Output: 1

            max = 23
            Input: nums = [5,4,-1,7,8]
            Output: 23

        brute force
            - have a variable with the max number
                - for each number traverse the rest of numbers and create a current sum 
                    each time, that sum will be compared against max always

            -return

            runtime: o(n^2)
            memory: o(1)

        optimize
            - best conceivable runtime: o(n)
            - I´m thinking about a dynamic sliding window technique being valuable here
            - if not, then with dp have an array?

            I dont remember the name of this algorithm, but basically we keep adding until
            we get a negative number or 0, then we start counting again from the next number

        test
            - array with one element
            - array with numbers getting to 0 and -1
            -arrays with non-negative numbers 
        */

        /*
            max = 6
            curr = 5 
                                                 i 
            Input: nums = [-2,1,-3,4,-1,2,1,-5,4]

            max = 0
            curr_sum = -2 
                    i
            [-1, 0, -2]

                 i
            [-2, -1]
                  
        */

        int n = nums.size();
        int max_sum = nums[0];
        int curr_sum = 0;

        for(int i = 0; i < n; i++){

            curr_sum += nums[i];

            if(curr_sum > max_sum){
                max_sum = curr_sum;
            } 
            if(curr_sum < 0){
                curr_sum = 0;
            }            
        }

        return max_sum;


    }
};

/*
34 minutes

runtime: o(n)
memory: o(1)

I came up with the brute force solution really fast, and I had the idea that kadanes algorithm was 
necesary here.

The only thing is that i didn´t remembered the algoritm. I just knew that the concept is to
keep suming and comparing and if we get below 0, we set the current sum to 0 so we can start again.

i came up with the solution, but after realizing that the answer was wrong when i bunmitted twice
That is not good, but good thing is that after i had an error i got to the answer by myself

I have to come up with good examples so i can trust my logic, instead of just hoping that it works.

Great job coming up with the solution once i knew that something was wrong, but trying to remember the
answer is the wrong approach and not remembering it well affected my solution.

Next time dont try to remember and actually try to do it, having a good example

*/
