#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
        45 min
        info
            input
                - int array nums
                
            output
                - product, of subarray that has the alrgest product
                
            cosntraints
                - range of sizes the array can have? [1, 20k]
                - range of values that each num can have? [-10, 10]
                - is hte product inside the int_min and int_max range? yes
            
            43 min 10 sec left
            
        example
            Input: nums = [2,3,-2,4]
            Output: 6
            
            Input: nums = [-2,0,-1]
            Output: 0
            
            Input: nums = [1,-2,-3]
            Output: 6
            
            max_seen = 1
            max = 1
            min = 1
            
        brute force
            for each number
                set a curr product
                we traverse the rest of the numbers and multiply
                    we compare to a global max_seen variable
                    
            runtime: o(n^2)
            memory: o(1)
            
        optimize
            best conceivable runtime: o(n) we have to traverse all the elements at least once
            
            if we have to decide if the next value is going to give me the biigest ive seen or the min
            depending on the sign
            
            on each number we either start anew
            max comes from the product with the current num and max, or curr num and min
            min comes from prod of curr and max, or curr and min.
            
        walkthrough
        
            nums = [1,-2,-3,4]
            Output: 6
            
            max_seen = 1
            max = -2 * -3 = 6
            min = -2 * -3 = 6
            
            nums = [2,3,-2,4]
            Output: 6
            
            max_seen = 2
            min = 2
            max = 2
            
            is there a moment when we have to restart the count?
            for min
                min is 
                    - curr number
                    - curr number * min
                    - curr number * max
                
                max is
                    - curr number
                    - curr number * min (from a tmp variable)
                    - curr number * max
                    
                    we either restart, or continue from the max or continue from the min
            
        
        test
            - only positive numbers
            - only negative numbers
            - mix of positive and negative numbers
            
            33 min left
        */
        
        int max_seen = nums[0], maximum = 1, minimum = 1;
        
        for(int num : nums){
            int tmpMin = minimum;
            
            // set min
            minimum = min(num, minimum*num);
            minimum = min(minimum, maximum*num);
            
            // set max
            maximum = max(num, maximum*num);
            maximum = max(maximum, tmpMin*num);
            
            // compare
            max_seen = max(max_seen, maximum);
        }
        
        return max_seen; // 29 min 30 sec left after finish writing this one, passed with 27 min 44 sec. i accidentally left maximum and minimum with nums[0] i didnt analyze everything at the end. i have to
    }
};
