#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        /*
        info
            input
                - integer array "nums"

            output
             - bool
             - true if any value appears at least twice in the array
             - false if every element is distinct
            
            
            constraints
                - What range of sizes can the array have? from 1 to 10^5
                - What range of values can each number have? between -10^9 to 10^9
                - Nums are ordered? no

        example
                        
            Input: nums = [1,1,1,3,3,4,3,2,4,2]

        brute force
            traverse array
            store each number we see in a set
            if we reach a number that already exists in the set, we return true

            runtime o(n)
            memory o(n)

        optimize
            best conceivable runtime o(n)
            can memory be improved?
                it could be improved by sorting the array
                runtime would be n log n, and memory o(1)

        test
            - array with 1 element
            - array with all values being distinct
            - array with duplicate values
        */

        /*
        unordered_set = {
            1,
            2,
            3,

        }
               i 
        [1,2,3,1]
        */

        unordered_set<int> nums_set;

        for(int i = 0; i < nums.size(); i++){
            if(nums_set.contains(nums[i])){return true;}
            nums_set.insert(nums[i]);
        }

        return false;
    }
};

/*
10 minutos

easy, y ya me estoy agarrando la onda con el lenguaje nuevamente
*/
