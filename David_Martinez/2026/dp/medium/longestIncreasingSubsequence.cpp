#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
        info
            input
                - int array "nums"
            
            output
                - length of longest strictly increasing subsequence
            
            constraints
                - range of sizes the array can have? [1, 2500]
                - range of values that each number can have? [-10k, 10k] 
                
            43 min 32 sec left
            
            
        example

            Input: nums = [10,9,2,5,3,7,101,18]
            Output: 4    
            
            Input: nums = [0,1,0,3,2,3]
            Output: 4
            
            Input: nums = [7,7,7,7,7,7,7]
            Output: 1
            
        brute force
            for each number
                traverse the rest of the list. but keep a min price seen with the floor being
                        the current number
                        
                        compare longest increasing subsequence against current.
                        
            runtime: o(n^2)
            memory: o(1)
            
        optimize
            best conceivable runtime: o(n) we have to at least traverse all the array once
            
            can i do a binary search esque search? for each min until we get to the end of array?
            
            38 min left
        test
            - longest subsequence is on consecutive numbers
            - it is not in consecutive numbers   
            
            
            10
            
            [10,9,2,5,3,7,101,18]
            [1, 1,1,2,2,3, 4 ,4]
            
            [0,1,0,3,2,3]
            [1,2,1,3,3,4]
            
            for each number, traverse backwards, if we find a value thats smaller.
            the dp value in that index is max between dp value at the index of that smaller number + 1
            or the dp[i] number.
            
            runtime: o(n^2)
            memory: o(n) for the dp array
            
            the state in eaach index from dp array is how many prev smaller values we have
            
        */
        /*
        int n = nums.size();
        
        // create dp aux vector
        vector<int> dp(n,1);
        int maxSeen = 1;
        
        // traverse all numbers
        for(int i = 0; i < n; i++){
            // traverse from this number, backwards
            for(int j = i; j >= 0; j--){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxSeen = max(maxSeen, dp[i]);
        }
        
        return maxSeen; // accepted, 26 min left. i should see how to solve this in o(n log n)
        */
        
        vector<int> tails;
        
        for(int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if(it == tails.end()) tails.push_back(num);
            else *it = num;
        }
        
        return tails.size();
    } 
};

/*
lower_bound makes a binary search in a sorted range to return an iterator to the first element which value is greater or equal to the value we are looking for.

*/
