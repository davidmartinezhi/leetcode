#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
        info
            input
                - string 's'
                
                find longest substring without repeating chars
            
            output
                - size of that string
            
            
            constraints
                - type of characters? english letters, digits, symbols and spaces
                    - english letters?
                    - ascii?
                    - unicode? 
                - range of sizes that the string can have? 0 and 50k
            
            
        example
            ht = {
                
                b: 1,
                
                
            }
                           s  e
            Input: s = "abcabcbb"
            Output: 3
        
                         se
            Input: s = "bbbbb"
            Output: 1
            
            Input: s = "pwwkew"
            Output: 3
            
        brute force
            have a ht
            for each character
                traverse the rest of char 
                    add as key the letter and have value as counter
                    if counter is bigger than 1
                    check how many chars we have traversed and compare with a curr max
                    
            runtime o(n^2)
            memory o(n)
            
        optimize
            best conceivable runtime: o(n)
            
            dynamic window technicque: runtime: o(n) memory: o(n)
            
            
        test
            - empty string
            - all chars are unique
            - longest substring is bigger than 1
            - all chars are different
        
        */
    
        
        // 9 minutes
        int n = s.size();
        
        // check edge case: empty string
        if(n == 0) return 0;
        
        //declare variables
        int start = 0;
        unordered_map<char, int> counter;
        int longestSubstr = 0;
        
        /*
            ht = {
                
                b: 1,
                

            }
            1
                         e
                         s
            Input: s = "bbb"
        */
        
        // traverse the string
        for(int end = 0; end < n; end++){
            // increase counter of this char
            char curr_char = s[end];
            counter[curr_char]++;
            
            // check if the counter value is greater than 1
            while(start < end && counter[curr_char] > 1){
                char start_char = s[start];
                counter[start_char]--;
                start++;
            }
            
            longestSubstr = max(longestSubstr, end-start+1);
        }
        
        return longestSubstr; 
        
    }
};// 21 minutes checking with examples and all

/*
Me resulto muy satisfactorio el sacar la solucion con una implementacion muy limpia del dynamic window
technique y de 0 sin que lo haya revisado en años. 

el usar el for loop para seguir el traversal hasta llegar a un estado invalido, y cuando estemos en ese estado
invalido ahora si hacer el while loop hasta regresar al caso valido o que el primer pointer alcance al segundo
muy buena solucion y muy buen trabajo

*/
