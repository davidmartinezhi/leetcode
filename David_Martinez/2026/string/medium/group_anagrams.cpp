#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        /*
        info
        
            input
                - array of strings
            
            output
                - group anagrams and return answer in any order
            
            constraints
                - ranges of sizes of array? 1 and 10k
                - ranges of sizes of strings 0 and 100
                - what type of chars will be in the strings? lowercase english letters
                
        example
            Input: strs = ["eat","tea","tan","ate","nat","bat"]

            Output: [["bat"],["nat","tan"],["ate","eat","tea"]]  
            
        brute force
            sort every string and have that be a key, add all words whos sorted order are that key
                then add it.
                
            then traverse the ht and push every array into an array of answers
            
            runtime: o(n * m log m)
            memory: o(n)
            
        optimize
            we could do a math operation? no
            best conceivable runtime: o(n) we have to traverse all words at least once
            
        test
            - no anagrams exist
            - anagrms exist
                - mulitple anagrams 
                - just one anagram
        
        */
        
        int n = strs.size();
        unordered_map<string, vector<string>> ht;
        vector<vector<string>> result;
        
        for(string str : strs){
            // string sortedStr = str;
            // sort(sortedStr.begin(), sortedStr.end());
            // ht[sortedStr].push_back(str);
            
            string key(26, '0');
            for(char c : str) key[c - 'a']++;
            ht[key].push_back(str);
            // this change makes the runtime: o(n*m*)
        }
        
        for(auto element : ht){
            result.push_back(element.second);
        }
        
        return result;
    }
};

// 17 min

/*
I resolved the problem pretty fast and knew about the concept on how to implement the optimal solution
but i never thought of it with strings, only with arrays.

its good to add to my toolkit the concept of not just using arrays for counters but also strings and
it is smart to use the char - 'a' to turn a letter into a number so we can use it in index.

just first hand, to see if i remember. to get index of a char is char - 'a'
to get an int from a char that represents a string is char - '0'

*/
