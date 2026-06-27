#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       /*
       27 mins 15 sec left
       info
            input
                - array of int "nums" sorted in non-decreasing order
            
            output
                - starting and ending position of a given target value
                - if not found return [-1, -1]
            
            
            constraints
                - algorithm must be of log n
                - range of sizes that nums can have? [0, 100k]
                - range of values each element in array can have? [-10^9, 10^9]
                - range of values of target? [-10^9, 10^9]
                - array is in ascending order
            
        example
        24 minutes with 23 seconds left
        
        Input: nums = [5,7,7,8,8,10], target = 8
        Output: [3,4]        
        
        Input: nums = [5,7,7,8,8,10], target = 6
        Output: [-1,-1]
        
        brute force
            traverse and mark first value when we first see the value
            at the last value we mark as end
            
            runtime: o(n)
            memory: o(1)
            
        optimize
            best conceivable runtime: o(log n) we have a sorted array
            we could use binary search.
            we just have to find the starting and ending value
            
        test
            - values exist
            - values don´t exist
            - every num in the array is that value
            - just one element in the array s the value
            
        21 minutes 22 seconds left
        
        walkthrough
        Input: nums = [5,7,7,8,8,10], target = 8
        Output: [3,4]   
       
            [5,7,7,8,8,10]
                     4
                     m
                   3
                   s
                      e
                      5
            less than target, move right
       
            [5,7,7,8,8,10]
                     4
                     m
                   3
                   s
                      e
                      5
            if we want first val of answer, check with left
            value on left is the same,
            
            ---------------   
            [5,8,8,8,8,10]
                 2
                 m
            0
            s
                        5
                        e
                        
        after middle. if middle is target and right side is target
        move right
        
            [5,8,8,8,8,10]
                     4
                     m
                   3
                   s
                        5
                        e
        middle is target and right side is not target or out of bounds.
        we have found right value in the answer
        [?,4]
        
        now we do the same but opposite for the left side
        
            [5,8,8,8,8,10]
                 2
                 m
            0
            s
                        5
                        e
                        
        middle is target and left side too, move left            
            [5,8,8,8,8,10]
               1
               m
            0
            s
                 2
                 e
                 
        target is middle and left is not target, we have left side
       
       12 min remaining
       
       
       [0,1,1,2,3] 2
              m
              s
                e
     [3,3]
     
     anew
       [0,1,2,2,3] 2
              m
              s
                e   
                
    [2, ]
        6 min 53 sec left
       */ 
        
        /*
        int n = nums.size();
        
        if(n == 0) return {-1, -1};
        
        vector<int> result = {-1, -1};
        int start = 0;
        int end = n-1;
        
        // find first value
        while(start <= end){
            int m = start + (end-start) / 2;
            
            if(nums[m] == target){
                result[0] = m;
                end = m - 1;
            }
            else if(nums[m] < target){
                 // times up, ill finish it
                start = m + 1;
            }
            else{
                end = m - 1;
            }   
        }
        
        start = 0;
        end = n-1;
        
        // find second value
        while(start <= end){
            int m = start + (end-start) / 2;
            
            if(nums[m] == target){
                result[1] = m;
                start = m + 1;
            }
            else if(nums[m] < target){
                 // times up, ill finish it
                start = m + 1;
            }
            else{
                end = m - 1;
            }   
        }
        
        return result;
        // completed, the code is very ugly. ill refactor
        */
        int n = nums.size();
        
        if(n == 0) return {-1, -1};
        
        vector<int> result = {-1, -1};
        int start = 0;
        int end = n-1;
        
        // find first value
        while(start <= end){
            int m = start + (end-start) / 2;
            
            if(nums[m] == target){
                if(m-1 < 0 || nums[m-1] != target){
                    result[0] = m;
                    break;
                }else{
                    end = m - 1;
                }                
            }
            else if(nums[m] < target){
                 // times up, ill finish it
                start = m + 1;
            }
            else{
                end = m - 1;
            }   
        }
        
        start = 0;
        end = n-1;
        
        // find second value
        while(start <= end){
            int m = start + (end-start) / 2;
            
            if(nums[m] == target){
                if(m+1 >= n || nums[m+1] != target){
                    result[1] = m;
                    break;
                }else{
                    start = m + 1;
                }
            }
            else if(nums[m] < target){
                 // times up, ill finish it
                start = m + 1;
            }
            else{
                end = m - 1;
            }   
        }
        
        return result;        
    } 
};

/*
runtime: o(log n)
memory: o(1)

I had the logic, i knew that i had to do 2 binary searches. one to find the left boundary and another
one to find the right boundary.

The things that i had trouble with was with defining the conditions of when we are done with the binary search. I was thinking that to find the left boundary i have to check if the value to the left side is either out of bounds less than 0 or not the target, we found it. else if we are in the target and the left is the target also then we send to the left again.

and doing the same for the right side. but i struggled defining the logic, i was defininf everything in the same place

okay the seconde version i just wrote is my original idea of what i wanted to do. i was trying to add both conditions inside nums[m] == target in one condition. but i had to put it as a nested if else, i wanted to be very explicit.

it took me a lot of time on the walkthrough to come up with the algorithm correctly.

it was a good idea the claude solution where i store the result and just send it to the left or right and if we dont find something earlier that means that that value was the right one.
*/
