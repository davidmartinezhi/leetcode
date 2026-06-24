#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
        info
        
            input
                - int array "nums"
                - int k
            
            output
                - return k most frequent elements
            
            
            constraints
                - answer can be in any order
                - range of sizes the array can have? [1, 100k]
                - range of values that k can have? [-10k, 10k]
                - k is in range [1, num of unique characters]
                - its guaranteed that the answer is unique
                
                may be good to know what to ask if something like this comes up in interviews
                
        example
            Input: nums = [1,1,1,2,2,3], k = 2

            Output: [1,2]   
            
            
        brute force
            use a ht and have for each number a counter
            traverse to set counters
            traverse ht to get biggest counter and once we get the number, we set counter to 0
                meaning we have visited this
                
            do this k times
            
            runtime: o(n*k)
            memory: o(k)
            
        optimize
            the nature of the problem implies that we need a maxHeap, so we always have the biggest
            value on top. I could have a pair that includes the counter, followed by the number
            
            then just extract the top, k times.
            
            runtime: o(n) to fill the counter, o(n log n)? to reorder the heap when we take the biggest
                element
                
            memory: o(n)
            
        test
            - k is n
            - k is one
            - k is something in between
        */
        
        priority_queue<pair<int, int>> maxHeap;
        unordered_map<int, int> counter;
        
        // fill counter
        for(int num : nums){
            counter[num]++;
        }
        
        // fill maxHeap
        for(auto c : counter){
            pair<int, int> tmp = {c.second, c.first};
            maxHeap.push(tmp);
        }
        
        // get k values
        vector<int> result;
        
        for(int i = 0; i < k; i++){
            pair<int,int> mostFrequent = maxHeap.top();
            result.push_back(mostFrequent.second);
            maxHeap.pop();
        }
        
        return result;
        
    } // 7 min left
};

/*
More precise runtime description:

runtime:
    - o(n) to traverse all the array and crate counter
    - o(u log n) to fill max heap with unique numbers and their counters
    - o(k log u) to remove k numbers

    so in the worst case it is o(n log n)


I felt really good with this problem and i finished fast, I just need to refresh my memory working with
queue and pair
*/
