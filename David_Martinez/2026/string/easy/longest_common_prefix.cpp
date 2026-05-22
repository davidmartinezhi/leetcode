#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /*
        info
            input
                - array of strings 'strs'
            
            output
                - longest common prefix string among array of strings
                - if no prefix, return empty string
            
            
            constraints
                - what ranges of sizes can the str have? 1 and 200 included
                - what ranges of sizes can the array have? 0 and 200, included both
                - what set of characters can the string have? lowercase english letters, if not empty
            
            
        example
            Input: strs = ["flower","flow","flight"]
            Output: "fl"   
            
            Input: strs = ["dog","racecar","car"]
            Output: ""
            
        brute force
            traverse to get the shortest string
                use that as base
                for each word
                    traverse char by char on both strings and stop when the chars are not the same 
                        or we have reach the end of a str
                        compare the shortest string with the current longest prefix and set smaller
                        
            runtime: o(n*m) n being the size of the array and m being the num of chars in smallest str
            memory: o(1)
            
        optimize
            best conceivable runtime: o(n*m)
            
        test
            - no longest preffix exists
            - longer prefix exists
            - other things to test?
        */
        
        
        int n = strs.size();
        
        // edge case: see if array is empty
        if(n == 0) return "";
        
        /*
        ["flower","flow","flight"]
        shortest = "flow" size 5
                      j
                    
        curr = "flight" size 6
                  j
        
        */

        string shortest = strs[0];
        
        // traverse array of strings
        for(int i = 1; i < n; i++){
            
            // get info of both strings
            string curr_str = strs[i];
            int shortest_size = shortest.size();
            int curr_str_size = curr_str.size();
            
            int j = 0;
            while(j < shortest_size && j < curr_str_size){
                // when value is different, get that substring
                if(shortest[j] != curr_str[j]){
                    break;
                } 
                j++;
            }
            
            if(j < shortest_size){
                shortest = curr_str.substr(0, j);
            }
                      
        }
        
        return shortest;
        
    }
};
// 25 min
