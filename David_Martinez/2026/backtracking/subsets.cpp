#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
        info
            input
                - int array "nums" of unique elements
            
            output
                - all possible subsets (the power set)
            
            
            constraints
                - all numbers are unique
                - result must not contain duplicate subsets
                - we can return in any order? yes
                - range of sizes that the array can have? [1, 10]
                - range of values that each num can have? [-10, 10]
                
            2 mins
            
        example
            Input: nums = [1,2,3]
            Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]  
            
            
            Input: nums = [0]
            Output: [[],[0]]    
            
        brute force
            this is a backtracking problem
            
            so we know the runtime is going to be exponential.
            
        walkthrough
            nums = [1,2,3]
            1 
            -> [] we do not add it
                
                2
                    ->
                     [] we do not add it
                        3
                        ->
                        [] we do not add it
                        [3] we add it
                        
                     [2] we add it
                        3
                        -> 
                        [2] we do not add it
                        [2,3] we add it
            
            
            -> [1] we add it
                
                2
                    ->
                    [1] we do not add it
                        3
                        ->
                        [1] we do not add it
                        [1,3] we add it
                        
                    [1,2] we add it
                        3
                        ->
                        [1,2] we do not add it
                        [1,2,3] we add it
                        
                        [,,,,,,[] 
                        
            this is the walkthrough
            
            base case, reaching the end of the list (goal)
            
            options, add the number or not add it for the next call
            
            runtime: o(2^n) we have to options for every number that we have
            memory: o(n) on stack 
            
            
            test
                - have 1 number
                - have 2 numbers
                - have 3  numbers
                
            32 minutes left
        */
        
        int sz = nums.size();
        vector<vector<int>> result;
        findSubsets(nums, result, sz, 0, {});
        return result;
    }
    
    /*
        [1,2]
        sz = 2
        currIdx = 1
        subset = [1,2] [1] [2]
    */
    
    void findSubsets(const vector<int> & nums, 
                     vector<vector<int>> &result, 
                    int & sz,
                    int currIdx,
                    vector<int> subset){
        
        // base case: we reached the end of nums
        if(currIdx == sz){
            result.push_back(subset);
            return;
        }
        
        // for the current number 
        // make a call adding it. can i use just one array and add or remove values from there?
        subset.push_back(nums[currIdx]);
        findSubsets(nums, result, sz, currIdx+1, subset);
        subset.pop_back();
        
        // make a call not adding it
        findSubsets(nums, result, sz, currIdx+1, subset);
        
    } // 21 minutes left
};

/* 
I felt comfortable with this problem, I knew how to solve it and from reasoning alone
I knew how to implement it differently from the permutations problem.

The complexity could have been more precise
O(2^n * n) we have 2 options for every n and the other n is the compelxity to copy each array

memory: O(n) stack

*/
