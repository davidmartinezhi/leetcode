#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*
        info
            input: array of int and an int target
            output: indices of two numbers that add up to target
            constraints:
                - the answer has to be in a specific order? no
                - what range of values can the numbers have in the array? between -10^9 and 10^9
            - how big can the array be? between 2 and 10^4 
                - what values negative or positive are the max
                and min? between -10^9 and 10^9
                - are the numbers sorted always? no

        example
                    j
                    i
            nums = [2,7,11,15], target = 9
            -> [0,1]

        brute force
            for each number, traverse the rest of the list
            runtime: O(n^2)

        optimize
            sort
            runtime: O(n log n)

            hashmap
            store each number as key and index as value

            {
                2:0,
                7:1,
                11:2,
                15:3
            }

            nums = [2,7,11,15], target = 9
            looking_for = target minus the current number
            if it exists, we have the answer

        walkthrough
            traverse to fill hashmap
            traverse array
                for each number do target - number
                check if the result of the operation is in the hm

            runtime: O(n)
            space: O(n)

        test:
            target with positive number
            target with negative number
            no target found?
        
        */
        
        // declare variables
        unordered_map<int, int> numbers_and_index;
        vector<int> result;

        // traverse to look for soultion number
        for(int i = 0; i < nums.size(); i++){
            int looking_for = target - nums[i];

            if(numbers_and_index.find(looking_for) != numbers_and_index.end()){
                result.push_back(i); 
                result.push_back(numbers_and_index[looking_for]); 
                break;
            }

            numbers_and_index[nums[i]] = i;
        }

        return result;

    }
};

/*
Terminado en 22 minutos

Genuinamente no recordaba la mejor solucion para este problema

Siento que aun estoy comodo con el sacar una solucion, lo que si me hizo ruido de ratos fue
el recordar el syntax o si es que algunas cosas si los podia hacer con c++.

Pero me imagino que esto viene con la experiencia y lo ire recordando poco a poco

runtime: O(n)
memory: O(n)

*/
