#include <vector>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        /*
        info
        
        
            input
                - integer array 'nums'
            
            output
                - true
                    - if there existts a triplet of indices (i,j,k) such that i < j < k
                        and nums[i] < nums[j] < nums[k]
                        
                -false
                    - if no such indices exist
            
            
            constraints
                - range of sizes that the array can have? 1 and 500k
                - ranges of values that the numbers in the array can have? int_min to int_max
            
        example
                               k
                             j
                           i
            Input: nums = [1,2,3,4,5]
            Output: true     
            
            Input: nums = [5,4,3,2,1]
            Output: false
            
            ht = {
            
            }
            
            
            nums[i] < nums[j] < nums[k]
            i < j < k
            
            k 6 idx 5
            j 4 idx 4
            i 0 idx 3     
            
            static i
                traverse j
                    - nums j is smaller than nums i: i set to j
                    - nums j is the same as nums i: ignore
                    - nums j is greater than nums i: static j and deploy k
                    
                    static j
                        traverse k
                            - nums k is greater thatn nums[i] and less than nums[j]: k set to k
                            - num k is greater than nums[j]: return true
            return false
                            
                            
                                 k
                               j    
                             i
            Input: nums = [2,1,5,0,4,6]
            Output: true
            
            // 5 min
            
        brute force
            for each number
                traverse the rest of numbers, and for that second traversal
                    traverse the rest of numbers
                        check that the condition is true
                        
            runtime: o(n*n*n)
            memory: o(1)
            
            
        optimize
            best conceivable runtime: o(n), is this possible?

        test
            - ascending order
            - descending order
            - mixed order
            
            8 min and still no idea of a optimized approach
            10 min and i know i need 3 variables and store info, i know how to optimize
            20 minutes and just figure out the algorithm to do
        
        */
        
        int n = nums.size();
        
        /*
                                 k = 1
                                 j = 0  
                          
            Input: nums = [1,5,0,4,1,3]
                                     i
        */
        int j = INT_MAX, k = INT_MAX;
        
        for(int num : nums){
            if(num <= j) j = num;
            else if(num <= k) k = num; 
            else return true;
        }
        
        return false;
    }
}; // 44 min
/*
Me hizo mucho sentido hasta el final.
Literalment no habra nada menor que j
y lo que aparezca que no sea menor pero le sigue es k
y lo que apareza y sea mayor que k, ya con eso se cumplieron las condiciones

Pero como es que debo de pensar al hacer este tipo de problemas? como es que se puede llegar a esa logica?

Igual pude hacer mas esfuerzo en los ejemplos para sacar un ejemplo con el que pudiera ver 
el patron o que algo no iba a funcionar.
*/
/*
FEEDBACK NOTES

Solution quality
    - Reached the optimal O(n) time, O(1) space solution
    - 44 min total, justified by the genuine difficulty of the insight
    - Final code is clean and elegant (4-line core logic)

The meta-pattern: "greedy with minimal state"
    The key question to ask when stuck on these problems:
    "How much of the past do I actually need to remember to make
    the correct decision at this step?"
    
    Brute force keeps redundant info. The optimization is realizing
    you only need a fixed, small state to commit to an optimal decision.

How to train this intuition
    Step 1: question what past information you actually use to decide
    Step 2: think about the possible states at each step
    Step 3: think in terms of "what makes future success easier"
    Step 4: verify with dry-run examples
    
    After every brute force, before coding ask:
        1. What info from the past do I actually use right now?
        2. Can I summarize it in 1-2 fixed variables?
        3. What update rule keeps the "optimal decision still possible"
           invariant?

Subtle point in this specific problem
    When j updates to a smaller value, the previously stored k may no
    longer be preceded by the new j in the array. The algorithm still
    works because k captures "some value greater than some earlier
    smaller value", which is enough for any future bigger value to
    complete a triplet. This is the trickiest mental hurdle.

Pattern family (greedy O(n) with minimal state)
    Same meta-pattern applies to:
        - Best Time to Buy and Sell Stock (1 var: min so far)
        - Maximum Subarray / Kadane's (2 vars: current sum, best sum)
        - House Robber (2 vars: prev, curr)
        - Container With Most Water (2 pointers, greedy move)
        - Longest Mountain in Array (state for up/down phases)

For future problems
    - First exposure to a new pattern always costs more time
    - Once internalized, similar problems collapse to 10-15 min
    - Resist the urge to add more variables; ask "is this redundant?"
    - The simplest-looking solutions (3-5 lines) often hide the
      hardest insight
*/
