#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*
        info 
                input
                    - int array nums
                    
                    - we have to rotate the array to the right k times, k is positive
                
                output
                    - no output, just the array rotated
                
                
                constraints
                    - range of sizes the array can have? 1 and 100,000
                    - ranges of values that k can have? 0 and 100,000 included
                    
        example
            nums = [1,2,3,4,5,6,7], k = 3
            [5,6,7,1,2,3,4]
            [4,3,2,1,7,6,5]
                    
        brute force
            - create a new array
                - add the number from n -k-1 onward
                - then add from 0 to k
                copy all that dfata onto the original array
                
                runtime o(n)
                memory o(n)
                
        optimize
            reverse the last k numbers
            reverse the first numbers before those k numbers
            reverse everything
            
            runtime: o(n)
            memory: o(1)
            
        test
            k is equal to the length of the array
            k = 0
            k is in between
        */
        
        int n = nums.size();
        k = k % n;
        
        //reverse the last k elements
        reverse(nums.end() - k, nums.end());
        
        //reverse the numbers before k
        reverse(nums.begin(), nums.end()-k);
        
        //reverse everything
        reverse(nums.begin(), nums.end());
        
        return;
    }
};
// 13 min
