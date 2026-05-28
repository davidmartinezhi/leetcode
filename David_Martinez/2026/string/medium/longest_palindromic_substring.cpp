#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        /*
        24 inutes to do this
        
        info
            input
                - string 's'
            
            output
                - longest palindromic substring in 's'
            
            
            constraints
                - ranges of sizes that the string can have? 1 and 1k, included
                - type of characters that the string can have? digits and english letters
            
           
         example
            Input: s = "babbabd"
            Output: "bab"
        
            Input: s = "cbbd"
            Output: "bb" 
            
        brute force
            from each char
            have two pointers start from there and expand one to the left and the other to the right
                until they are different.
                compare on each step if the max length is greater to the lonest we've seen
                if its the longest set is as the longest
                
            runtime: o(n*n)
            memory: o(1)
            
        optimize
            best conceivable runtime: o(n) is it possible? maybe with dp with something similar to kmp
            
        test
            - palindrome is even size
            - palindrome is odd size
            - string is of one char
            This took like 8 min, until this point
        
        */
        
        int n = s.size();
        
        // check edge case: string of size 1
        if(n == 1) return s;
        
        // set variables
        string longestPalindrome = "";
        
        // traverse the string
        for(int i = 0; i < n; i++){
            longestPalindrome = checkLongest(s, longestPalindrome, i, i);
            longestPalindrome = checkLongest(s, longestPalindrome, i, i+1);
        }
        
        return longestPalindrome;// 7 min left and im stuck on how to get the sbtr but all the logic is there. finished with 6 min left
    }    
    
    string checkLongest(string & s, string currentLongest, int left, int right){
        int n = s.size();
        string longest = currentLongest;
        while(left >= 0 && right < n && s[left] == s[right]){
            int current_len = right - left + 1;
            if(current_len > longest.size()){
                longest = s.substr(left, current_len);
            }
            left--;
            right++;
        }
        return longest;   
    }
}; // finished with 1+ min left using a helper function

/*
Me senti muy eficiente al resolver este problema junto con longest substring without repeating characters

Se nota que ya refresque patrones, syntax y temas al comenzar con los easy y luego pasar a los medium
refrescar los temas easy, fortalecerlos y luego ya ver los mediums como una cadena mas larga de los
problemas que ya resolvi es buen approach.

Si hay manera de mejorar mi algoritmo. Estoy regresando de checkLongest una copia de string cada que iteramos
es mas eficiente solo guardar los valores del longest en enteros pasados por referencia, pero de igual manera
me alegra la velociad con los que estan saliendo los problemas. ademas tomando en cuenta que hago el mental framework
escrito por ahora para acostumbrarme a externalizar mi intuicion de problemas

*/
