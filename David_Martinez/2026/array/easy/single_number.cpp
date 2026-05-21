#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*
        info
                input
                    - non empty array of integers 
                
                output
                    - the single digit
                
                constraints
                    - every element appears once except one
                    - linear runtime has to be implemented
                    - ranges of sizes of the array? 1 and 30k
                
                
        example
        Example 1:
            Input: nums = [2,2,1]
            Output: 1

        Example 2:
            Input: nums = [4,1,2,1,2]
            Output: 4

        Example 3:
            Input: nums = [1]
            Output: 1   
            
        brute force
            we have to traverse at least once every element
            
            - ht with number and count
            - traverse the array and for each number, increase one
            - traverse at the end to look for the one with count 1
            
            runtime o(n)
            memory o(n)
            
        optimize
            bcr o(n)
            can we improve memory? we could do operations with bits
            
            ^= xor operator?
            
        test
            single digit
        
        */
        
        unordered_map<int, int> digits;
        
        for(auto num: nums){
            if(digits.find(num) == digits.end()) digits[num] = 1;
            else digits[num]++;
        }
        
        for(const auto &digit: digits){
            if(digit.second == 1) return digit.first;
        }
        
        return 0;
    }
};

//17
