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

    string longestCommonPrefixVertical(vector<string>& strs) {
        
        int n = strs.size();
        
        // edge case: see if array is empty
        if(n == 0) return "";
        
        // traverse all the characters of the first word
        for(int i = 0; i < strs[0].size(); i++){
            
            // get char to compare
            char c = strs[0][i];
            
            // traverse all the other words
            for(int j = 1; j < n; j++){
                // base cases:
                // curr word is shorter than initial word
                // curr word char is different from the base char
                if(i >= strs[j].size() || strs[j][i] != c){
                    return strs[j].substr(0, i);
                }
            }
            
        }
        return strs[0];  // if the original word is the longest common prefix      
    }
};
// 25 min
/*
El approch vertical hace muchisimo sentido y nunca se me habia ocurrido
si considero muy interesante la idea de haberlo visto todo como una matrix la cual
vamos escaneando columna por columna, no lo habia pensado pero si esta muy interesante.

Probablemente me sea muy util para otros problemas, el poder pensar de este tipo de recorrido igual

La complejidad del vertical es la misma pero es mas agresivo en cuanto en que etapa encontrar fallos
*/
