#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        /*
        info
        
            input
                - array nums of distinct integers
            
            
            output
                - all possible permutations of the array numbers
                - answer can be in any order
            
            
            constraints
                - range of sizes the array can have?[1,6]
                - range of values each num can have?[-10,10]
                - all nums are unique
                
            2 min
                
        example
            Input: nums = [1,2,3]
            Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
            
            Input: nums = [0,1]
            Output: [[0,1],[1,0]]
            
            Input: nums = [1]
            Output: [[1]]    
            
            
        brute force
            This is a permutation problem.
            the complexity is factorial, we have to reorder n elements
            runtime: o(!n)
            memory: o(n) on stack calls
            
        optimize
            best conceivable runtime
                for the nature of this problem, factorial is the best we can do.
                we are reordering all the n values and getting all possible combinations
                
        tests
            - nums of size 1
            - nums of size greater than 1
            
        walkthrough
            Input: nums = [0,1]
            Output: [[0,1],[1,0]]  
            
            39 min left
            
            [0, 1, 2]
             
            base case, curr array is of the same size ad nums
            
            traverse all nums in array if its not self
            
            include curr num
            [0]
            ->
            [0,1]
            [0]
            -->
            [0,1,2]
            []
            -->
            [0,2]
            [0]
            
            
            do not include curr num
            []
            ->
            [1]
            []
            
            
            [0, 1]
            
            ->
            [0]
                ->
                    [0,1]
                    [0] x
                
            
            []
                ->
                    [1]
                        ->
                            [1,0]
                            [1]
                    []      
           30 min left, i know how to implement it 
           
           I could have an unordered set to check in o(1) if a permutation already exists
        */
        
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> currP;
        //fillPermutations2(nums, result, currP, used);
        fillPermutations(nums, result, {}, 0);
        return result;
    }
    
    /*
    result = 
    i
    [0,1,2]
    currIdx = 0
    currP = [
    
    */
    void fillPermutations2(const vector<int>& nums, 
                           vector<vector<int>> &result, 
                           vector<int> &currP, 
                           vector<bool> &used
                          ){
        // base case: permutation found
        if(currP.size() == nums.size()){
            result.push_back(currP);
            return;
        }
                
        // traverse all numbers in nums
        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue; // skipped num that was already used
            
            // set current as used
            used[i] = true;
            currP.push_back(nums[i]); // add number
            
            fillPermutations2(nums, result, currP, used); // recursive call
            
            // remove from being used
            used[i] = false;
            currP.pop_back();
        }
    }
    
    void fillPermutations(const vector<int>& nums, vector<vector<int>> &result, vector<int> currP, int currIdx){
        // base case: permutation found
        if(currP.size() == nums.size()){
            result.push_back(currP);
            return;
        }
                
        // traverse all numbers in nums
        for(int i = 0; i < nums.size(); i++){
            if(i != currIdx){                
                currP.push_back(nums[currIdx]);
                fillPermutations(nums, result, currP, i);
                currP.pop_back();
            }
        }
    } // 21 minutes left, i thinks something is missing
}; // 9 minutes left and im still trying to figure out how to make it work

/*
https://www.youtube.com/watch?v=Nabbpl7y4Lo

Gran video

Literal es bueno lo que dice el video

Tener el goal

Traversal de las opciones

Guardar si es que ya checamos algo, para no repetirlo (constraints)
*/
