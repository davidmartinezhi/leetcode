#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    /*
    info

        input
            - int array nums

        output
            - return all triplets that sum up to 0
            - they all have to be in different indexes


        constraints
            - it must not contain duplicate triplets
            - how big can the array be? 3<= array length <= 3000
            - what ranges of values can the numbers have? -100,000 and 100,000 inclusive
            - what if no triplets are found? we return empty array


    example
        Input: nums = [-1,0,1,2,-1,-4]

            {
                -1: [0,1,2,3,4,5]
            }
                      [-4,-1,-1,0,1,2]
                                i   
                                j
                           k
                    sum = 0
            result array = [[-1, -1, 2], [-1, 0, 1]]


        Output: [[-1,-1,2],[-1,0,1]] 

        runtime o(n log n) + o(n^2) = o(n^2)
        memory = o(1) 


    brute force
        for each number, traverse the rest of numbers
            inside that traversal, for that other number, travers all the numbers
                whenever nums[i] + nums[j] + nums[k] = 0, add it to result array

        runtime o(n^3)
        memory o(1)

    optimization
        best conceivable runtime: O(n), we have to traverse all numbers at least once


        Test
            - array with all repited numbers
            - array with one triplet suming up to 0
            - array with multiple triplets suming up to 0
    */

        // sort array
        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<vector<int>> result(0);

        // traverse the array
        for(int i = 0; i < n; i++){

            // run when we are on first value or a new value
            if(i == 0 || nums[i] != nums[i-1]){
                int j = i+1;
                int k = n-1;

                while(j < k){
                    // get curr sum
                    int sum = nums[i] + nums[j] + nums[k];

                    //sum is 0
                    if(sum == 0){
                        // append triplet
                        result.push_back({nums[i], nums[j], nums[k]});

                        // move both j and k to new values
                        int temp_j = nums[j];
                        int temp_k = nums[k];

                        while(j < k && nums[j] == temp_j) j++;
                        while(j < k && nums[k] == temp_k) k--;
                    }

                    // sum is less than 0
                    else if(sum < 0){
                        // move j to a bigger value
                        j++;
                    }
                    else{
                        // move k to a smaller value
                        k--;
                    }

                }
            }
        }

        return result;

    }
};

/*
45 minutes +
todo el razonamiento iba por el camino correcto

pero la implemetacion la hice mal
quise comenzar con pointers en los extremos y con otro solo recorrder el in-between

si es mucho mas sencillo tener un pointer que sea un ancla, una base.
y que a partir de ahi el resto se mueva.

debo de tomar eso en cuenta para este tipo de problemas donde se tenga
un array ordenado y se busque que que se encuentre info en el resto.

Siento que haciendo los medium de golpe estoy topando un poco con pared.
Si dberia de comenzar con los easy, para agarrar la onda con los conceptos basicos y el syntax
y tener boost de confidence. ya de ahi salto a los medium y los domino papita.
*/
