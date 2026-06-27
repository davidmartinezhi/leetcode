#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
        31 minutes left
        
        info
            input
                - int array "nums"
                - int "k"
            
            
            output
                - kth largest element in the array
                - kth largest element in value, in the sorted order. not of unique numbers
            
            
            constraints
                - range of sizes that nums can have? [1, 10k]
                - range of values each num can have? [-10k, 10k]
                
        example
            Input: nums = [3,2,1,5,6,4], k = 2
            Output: 5
            
            Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
            Output: 4
            
        brute force
            sort
            runtime: o(n log n)
            memory: o(1)
            
        optimize
            best conceivable runtime: o(n) we have to traverse the list at least once
            27 minutes 23 seconds left
            
            how can we improve memory? 
                - a heap? (n log n) to fill it and (k log n) to get the value
                - multiset is like a set but allows duplicates. 
                    i could put all the values there. still o(n log n) so sorting would be the same
                    
            i could traverse once to look for the amount of unique numbers we have. and the max
            create an array from 0 to the max. similar to when an array is used as a counter
            and do a counter so we traverse backwards the array, and remove 1 each tiem from each counter we see until k is cero and return the index we are at
            
            runtime: o(largest number)
            memory: o(largest number)
            
            this would depend a lot on the requirements and the context if this would be applied
            
        test
            - numbers are not ordered
            
            
        ill do the approach without sorting, with the heap.
        
        [3,2,1,5,6,4], k = 2
        
        1 2 3 4 5
        
            
        */
        
        /*
        // runtime: o(n log n + k log n)
        // memory: o(n)
        priority_queue<int> maxHeap;
        
        // get all the values into the max heap
        for(int num : nums){
            maxHeap.push(num);
        }
        
        // get the k num
        for(int i = 0; i < k-1; i++){
            maxHeap.pop();
        }
        
        return maxHeap.top();
        // 13 minutes left, solved completely
        // after this everything is just learning on how i could have done it differently
        */
        
        /*
        // runtime : o(n log k)
        // memory: o(k)
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // traverse all numbers but only keep k in the minHeap
        for(int num : nums){
            minHeap.push(num);
            if(minHeap.size() > k) minHeap.pop();
        }
        return minHeap.top();
        */
        
        // quick select, the optimal approach for runtime average time o(n)
        
        
    } 
};
