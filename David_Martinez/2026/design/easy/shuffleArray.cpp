/*
45 min left
info
    input
        - int array "nums"
        
    todo
        - randomly shuffle the array
        - all permutations of the array should be equally likely as a result of the shuffling

    operations?
    
        - constructor, initialize the obj with int array
        - reset, reset array to its initial configuration
        - shuffle, return a random shuffling of the array
        
    constratins
        - range of sizes the array can have? [1,50]
        - range of values each num in the array can have? [-10^6, 10^6]
        - all elements in the array are unique?
        - how many calls can we have? at most 10k in total for reset and shuffle
        
    40 min left
    
    brute force
        store the original array 
        store the array used for operations
        
        memory: o(n)
        
        reset
            do a reassignment of the working array, to be the same as the original
            
        shuffle
            do a random shuffle, how can i do this?
                traverse the array
                    get a random index
                        swap
                        
            shuffle o(n)
            we have to traverse
            
            34 min left
            
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> original;
    vector<int> v;

public:
    Solution(vector<int>& nums) {
        this->original = nums;
        this->v = nums;
    }
    
    vector<int> reset() {
        this->v = this->original;
        return this->v;
    }
    
    vector<int> shuffle() {
        int n = this->v.size();
        for(int i = n - 1; i > 0; i--){
            int j = rand() % (i+1);
            swap(this->v[i], this->v[j]);
        }
        
        return this->v;
        // 29 min left. finished first implementation, its the first time i implement a shuffle alg
        // accepted 27 min left. but i asked claude how to do and the complexity of the shuffle alg.
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
