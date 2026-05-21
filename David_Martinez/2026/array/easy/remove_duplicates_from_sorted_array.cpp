#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
        info
        
            input
                - integer array nums sorted in non-decreasing order
                - remove duplicates in-place so only unique values stay
                
            
            output
                - k, which is the number of unique elements
                - the remaining elements after nums[k], can be ignored
            
            constraints
                - relative order of the numbers should stay the same
                - nums is always sorted? yes, in non-decreaing order
                - how big or small can the array be? between 1 and 10k, included
                - what ranges of values can i get in the nums? - 100 to 100, included
            
            
        example
            
            nums = [1,1,2]
            
                                       j
                            i
            nums = [0,1,2,3,4,2,2,3,3,4]  
            nums[i] == nums[j] move j
            nums[i] == nums[j] move i once, copy value from j into i
            
        brute force
            create an array of the same size, and add the first number
            traverse nums and every time the num is different from the one in our current position
            we add it.
            
            then we copy the new array numbers into nums
            
            runtime: o(n)
            memory: o(n)
            
        optimization
            bcr: o(n)
            memory could be improved? 2 pointer technique
            
        test
            array size 1
            all unique numbers
            all numbers different
            mix of repeated numbers
        
        */
        
            int n = nums.size();
        
            // create pointer
            int i = 0;
        
            // traverse
            for(int j = 0; j < n; j++){
                if(nums[i] != nums[j]){
                    i++;
                    nums[i] = nums[j];
                }
            }
            
        return i + 1;
    }
};

// 15 minutes
