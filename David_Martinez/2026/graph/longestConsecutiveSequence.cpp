#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        /*
        info
            input
                - unsorted array of int "nums"

            output
                - length of longest consecutive elements sequence

            constraints
                - range of sizes array can have? [0, 100k]
                - range of values each number in the array can have? [-10^9, 10^9]
                - runtime must be o(n)


        example

            Input: nums = [100,4,200,1,3,2]
            Output: 4
            Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

            Input: nums = [0,3,7,2,5,8,4,6,0,1]
            Output: 9

        brute force
            sort the array
            runtime: o(n log n)
            memory: o(1)

        optimize
            best conceivable runtime: o(n) we have to traverse each num at least once

            can I add all the numbers to unordered_set
            then traverse unordered_set
                and for each number, check if the number above exists,
                    if it exists, continue climbing and get the length with curr - start
                    and compare to the max length until now

                    dont visit everything we have already visited, this could be an
                    unordered_map with bools if it was visited. thats how we
                    avoid repeating all the checks.

            complexity: 
                runtime: o(n)
                memory: o(n)

            
            with a graph
                100 -> 200
                1->2->3->4


        test
            - longest secuecnce is 1
            - longest is all the array
            - longest is in between
        */

        unordered_map<int, bool> ht;
        int longest = 0;

        // add all nums to unordered map and set flags as false
        for(int n : nums){
            ht[n] = false;
        }
        /*
        [100,4,200,1,3,2]
        unordered_map = {
        100 = t
        4 = t,
        200 = t, 
        1 = t,
        3 = t,
        2 = t
        }

        start = 200
        curr = 201
        longest = 4
        */

        for(auto [num, visited] : ht){
            if(visited) continue; 

            int start = num;

            // go to lowest number
            while(ht.contains(start-1)) start-=1;

            // go up 
            int curr = start;
            while(ht.contains(curr)){
                longest = max(longest, curr-start+1);
                ht[curr] = true;
                curr+=1;
            }
        }

        return longest;

    }

    int longestConsecutiveUnorderedSet(vector<int>& nums) {
    
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for(int num : s){
            if(s.contains(num-1)) continue; // dont visit if not the first num in seq

            int curr = num, len = 1;

            // go up 
            while(s.contains(curr+1)){
                len++;
                curr++;
            }

            longest = max(longest, len);
        }

        return longest;

    }  
};

/*
Im very happy with my performance on this one and how i was able to find the dfs abstraction
in the sequence of numbers.

I feel very fluent in graphs


*/
