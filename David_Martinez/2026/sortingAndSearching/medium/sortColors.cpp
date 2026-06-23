#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
       /*
       info
        input
            - array "nums" with n objects, colored red white and blue
            - sort them in place so obj of same color are adjacent
            - order must be red(0), white(1) and blue(2)
        
        output
            - void
        
        
        constraints
            - do not use the libraries sort function
            - range of sizes the array can have? [1,300]
            - range of items of each color we can have? inside that range, ill assume
            - values are only 0 or 1 or 2
        
        
        example
                             i
                           r
            Input: nums = [2,0,2,1,1,0]
            
            Output: [0,0,1,1,2,2]
            
                             i
                             r
            Input: nums = [0,2,2,1,1,0]
            
        brute force
            have a ht counter for how many of each color we have
            traverse the array and place each color until the counter returns to 0
            
            runtime: o(n)
            memory: o(n)
            
        optimize
            best conceivable runtime: O(n)
            how can we improve memory? can i use two pointer techniques?
            
            implementing a sorting algorithm will make this
            runtime: o(n log n)
            memory: o(1)
            
            let me try a walkthrough with 2 pointers to see if its something doable in this scenario
            
        6 minutes
        
        test
            - we only have 1 color
            - we only have 2 colors
            - we have the 3 colors
            
        walkthrough
                                i
                        r
            nums = [0,0,2,1,1,2]. have red at first non 0 value, move i, when we find a 0 switch and
                                        move r pointer to the next non 0,  until we traverse all
                                        
                            i
                            w
            nums = [0,0,1,1,2,2].  do the same, from where we left off, thats for white 
                                    move until we find a non 1. then from there move i
                                    if i finds a 1, switch and move white pointer until we have a non
                                    white value

                                  i
                                w
            nums = [0,0,1,1,1,1,2,2,1].
            
            32 min left, i got the algorithm
            
            runtime: o(n)
            memory: o(1)
       */ 
        
        int idx = 0;
        
        /*
                   i
               r
        [0,0,0,1,1,2]
        
        i
        r
        [1,1,1,2]
        */
        /*
        while(idx < nums.size() && nums[idx] == 0) idx++;
        
        // make red be the first values
        for(int i = idx; i < nums.size(); i++){ // traverse the array
            if(nums[i] == 0){ // if value is red
                swap(nums[idx], nums[i]); // swap with current value
                while(idx < nums.size() && nums[idx] == 0) idx++; // move until we find a non 0 val or out of b
            }
            
            if(idx >= nums.size()) break; // if out of bounds, break
        }
        
        // now we are in blue, do the same
        while(idx < nums.size() && nums[idx] == 1) idx++; // move until we find non-2 value
        
        // make red be the first values
        for(int i = idx; i < nums.size(); i++){ // traverse from there
            if(nums[i] == 1){ // if we find 1
                swap(nums[idx], nums[i]); // swap
                while(idx < nums.size() && nums[idx] == 1) idx++; // move til we find non 1 or out of bounds
            }
            
            if(idx >= nums.size()) break; // if out of bounds, stop
        }        
        
        return;
        */

        /*
                           i
                        x
        nums = [0,0,1,1,2,2]
        
        */

        // My original approach, but simplified 
        // make red be the first value
        for(int i = idx; i < nums.size(); i++){
            if(nums[i] == 0){
                swap(nums[idx], nums[i]);
                idx++;
            }
        }
        
        
        // make white be the second value
        for(int i = idx; i < nums.size(); i++){
            if(nums[i] == 1){
                swap(nums[idx], nums[i]);
                idx++;
            }            
        }        
        
        return;

        /*
        
        //declare variables
        int n = nums.size();
        vector<int> freq(3);
        
        //traverse to fill frequency counts
        for(int i = 0; i < n; i++){
            freq[nums[i]]++;
        }
        
        //construct based on frequency counts
        int index = 0;
        for(int i = 0; i < 3; i++){
            while(freq[i] > 0){
                nums[index] = i;
                index++;
                freq[i]--;
            }
        }
            
        this was a good alternative also
        
        */
        
    } // done with 19 min left
};

/*
Si era buena solucion la de los 2 pointers con uno estatico y el otro no estatico.

pero ahora haciendolo dos veces.

el dutch flag sirve para tener 3 pointers y en una pasada sacarlo. aparentemente hace mucha mas rapida
la implementacion


The pattern for two pointers with one static and the other traversing/exploring normally
is very basic and useful.

the fast pointer traverses until a condition is met, if its met, we place that value in static and
move static once

this will keep on basic always the values that meet the criteria

*/
