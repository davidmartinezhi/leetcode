#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        45 min left
        info
        
            input
                - int array nums sorted in ascending order
                - it may be left rotated at an unknown index
                
                - int target
            
            output
                - index of target or -1 if not in nums
            
            
            constraints
                - range of sizes that nums can have? [1, 5k]
                - range of values that each num can be? [-10k, 10k]
                - range of values taht target can be? [-10k, 10k]
                - all values of nums are unique
                
        example
        42 min 19 sec left
        
            Input: nums = [4,5,6,7,0,1,2], target = 0
            Output: 4
            
            nums = [4,5,6,7,0,1,2] target= 0
            
        brute force
            traverse array and return index of value with target, -1 if we traverse and dont find
            runtime: o(n)
            memoty: o(1)
            
        optimize
            best conceivable runtime: o(log n) the array is in ascending order, even if its rotated
            
        walkthrough
        39 min 26 sec left
        
            nums = [4,5,6,7,0,1,2] target= 0
                    0,1,2,3,4,5,6
                            s
                            e
                            m
                                
                        m = 0 + (6-0)/ 2 = 3
                        m = 4 + (6-4)/2 = 4 + (2/2) = 5
                        m = 4 + (5-4)/2 = 4 + (1/2) = 4 + 0 = 4
                        
                        states
                            - m is greater than end, s = m+1. we know that is not the start so we skip
                            - m is less than end, end = m, that may be the smallest
                            
            now we know in what part of the array the target may be
            
            now do binary search on that area.
                            
        34 min 20 sec left
        
        test
            - array is not rotated
            - array is rotated
            - target does not exist
        
        */
        
        int pivotIdx = findPivot(nums);
        return max(binarySearch(nums, target, 0, pivotIdx-1), 
                   binarySearch(nums, target, pivotIdx, nums.size()-1));
    }
    
    int binarySearch(vector<int>& nums, int & target, int start, int end){
        while(start <= end){
            int m = start + (end-start)/2;
            if(nums[m] == target) return m;
            else if(nums[m] > target) end = m - 1;
            else start = m + 1;
        }
        return -1;
    }
    
    int findPivot(vector<int>&nums){
        int start = 0, end = nums.size()-1;
        
        while(start < end){
            int m = start + (end-start)/2;
            if(nums[m] > nums[end]) start = m+1;
            else end = m;
        }
        return start;
    } // 25 min 52 seconds left, just finished writing everything. 24 min left, accepted and all
};
