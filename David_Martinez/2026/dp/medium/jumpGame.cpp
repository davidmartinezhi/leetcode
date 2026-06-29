#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        /*
        info
        
            input
                - int array "nums"
                - we start in the first index
                - each element in the array represents your max jum len at that position
            
            output
                - true, if we can reach the last index, else false
            
            
            constraints
                - range of sizes the array can have? [1, 10k]
                - range of values each num in the array can have? [0, 100k]
                
        example
            Input: nums = [2,3,1,1,4]
            Output: true            
            
            Input: nums = [3,2,1,0,4]
            Output: false       
            
        walkthrough
            
                     i
            [2,3,1,1,4]
                   1 is there a one or more? yes. we know we can make it from here
                 1 is there a one or more? yes. we know we can make it from here
               1 is there a one or more? yes. we know we can make it from here
             1 is there a onr or more? yes. we know we can make it from here
                 
        
            [3,2,1,0,4]
                   1 is there a one or more? no
                 2 is there a 2 or more? no
               3 is there a 3 or more? no
             4 is there a 4 or more? no
             
             
             i can do this approach of traversing from right to left and every time we can reach the
             last index, we look for an index that can reach that other index until we
             get to the first index.
             
            maybe i could traverse normally and the anount of jumps i do depends based on each index
            if my current available jumps are less than the available at that index. we switch so the curr available are the value in the curr index
            
            available = 2
                    i
           [2,3,1,1,4]
            we move and now available is 1, which is bigger 1 or 3? we take 3
            available is 3
            we move and its either 2 or 1
            we do the same and compare 1 or 1
            then we reach the end
                 
            available = 3
                   i
            [3,2,1,0,4]     
            jump and now we have 2
            compare 2 or 2, available is 2
            jump and now we have 1
            1 or 1, 1
            jump and we have 0
            0 or 0, 0
            
            
        optimize
            best conceivable runtime: o(n) we have to traverse all numbers at least once
            
        test
            - we can make it to the last index
            - we cannot make it
        */
        /*
        int n = nums.size();
        
        if(n == 1) return true;
        
        int available = nums[0];
        
        if(available == 0) return false;
        
        // traverse all nums
        for(int i = 1; i < n-1; i++){
            // update available, we just jumped
            available--;
            
            // set available as the max between available and nums[i]
            available = max(available, nums[i]);
            
            // check if available is 0
            if(available == 0) return false;
        }
        
        return true;*/ // 30 min left, about to check logic. 28 min left, all passed. cometi el error de no poner la condicion si el first available es 0, luego recorrer todo, no hasta el el penultimo y checar que el salto no fuera 0.
        /*
        int n = nums.size();
        
        if(n == 1) return true;
        
        int available = nums[0];    
        
        int i = 0;
        
        
        while(i < n-1){
            if(i > 0) available = max(nums[i], available - 1);
            if(available <= 0) return false;
            i++;
        }
        
        return true; // improved version finished with 22 mins left
        */
        /*
        int maxReach = 0; // current max reach
        for(int i = 0; i < nums.size(); i++){
            if(i > maxReach) return false; // if we cannot reach this index, return false
            maxReach = max(maxReach, i + nums[i]); // max reach is curr max reach, or from this idx + the available jump
        }
        return true;
        */
        
        int available = 0, i = 0;
        
        while(i < nums.size()-1){
            if(i == 0) available = nums[i];
            else available = max(nums[i], available - 1);
            if(available <= 0) return false;
            i++;
        }
        
        return true;
    } 
};

/*
This was an interesting problem. I knew how to solve it but my first implementation was a little clumsy.

either way i corrected it, but i still feel like i could be faster with it.

*/
