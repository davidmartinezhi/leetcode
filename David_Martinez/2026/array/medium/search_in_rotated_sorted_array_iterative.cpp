#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        info
                input
                    - integer array nums, sorted in ascending order
                    - values are unique
                    - arrray may be rotated to the left

                    - int target

                output
                    - index of target if its in nums or -1 if its not in nums

                contstraints
                    - runtime must be o(log n)
                    - how big or small can the array be? between 1 and 5k
                    - what ranges of values can the numbers in the array have -10^4 and 10^4
                    - what ranges of values can target have? -10^4 and 10^4
                    - values are unique
                    - nums are in asencding order and probably rotated

        example
            start
            end
                                   m
                                   s e 
            Input: nums = [4,5,6,7,0,1,2], target = 0
            Output: 4  

            end greater or equal than m? move left
            end smaller than m? move right

            we find the picot, the smaller number
            after this.

            we have start, pivot and end. we check if the target is between
            start and pivot or pivot and end and look for it there

        brute force
            traverse the array and once we find target return it
                if target is not found then we return -1

            runtime o(n)

        optimize
            best conceivable runtime, o(log n) because numbers are sorted

            i have to find the pivot, the minimum number to see if
            the target may be on the left or right side and search there

        test
            - array rotated n times
            - array rotated even number of times
            - array rotated odd number of times
        
        */

        int n = nums.size();

        // check edge case of array size 1
        if(n == 1){
            if(nums[0] == target) return 0;
            else return -1;
        }

        // get index of pivot
        int pivot_idx = find_pivot(nums, n);

        // check where is our target located 
        int start = 0;
        int end = n-1;

        /*
                       s.      p   e
        Input: nums = [4,5,6,7,0,1,2], target = 0
        1, 2, 3
        */
        int left = binary_search(nums, target, start, pivot_idx - 1);
        int right = binary_search(nums, target, pivot_idx, end);

        //search for target
        return max(left, right);

    }

    int binary_search(vector<int>& nums, int& target, int start, int end){
        while(start <= end){
            int m = start + (end-start) / 2;
            if(nums[m] == target) return m;
            else if(nums[m] < target) start = m + 1;
            else end = m - 1;
        }

        return -1;
    }

    int find_pivot(vector<int>& nums, int n){
        
        int start = 0;
        int end = n-1;

        // edge case: array sorted n times
        if(nums[start] < nums[end]) return 0;

        while(start < end){
            int m = start + (end-start) / 2;
            // [4,5,6,7,0,1,2], n = 7
            // 2 + (4-2) / 2 = 2 + (2) / 2 = 2 + 1 = 3

            if(nums[m] > nums[end]) start = m + 1;
            else end = m;
        }

        return start;
        
    }
    
};

/*
45 minutes +

okay en find pivot nos deetnemos cuando ya encontramos el minimo y siempre habra un minimo.

en binary search cuando estamos en el ultimo elemento, cuando start y end son iguales.
ahi tenemos que hacer una ultima comparacion.

igual con binary search es que debo de comprarar siempre con el target, andaba yo comparando con el start o end.

Deberia de tratar de implementar esto con recursion, se que me sentia muy comodo con recursion
antes si que pudiese ser beneficial
*/
