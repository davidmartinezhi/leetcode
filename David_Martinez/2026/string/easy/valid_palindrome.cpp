#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        /*
        info
        
            input
                - string 's'
            
            output
                - bool true if 's' is a palindrome
                - else, false
            
            constraints
                - range of sizes that 's' can have? between 1 and 20k, 1 and 20k included
                - type of characters it can have? 
                    - ascii? 
                    - only english letters
                        - lower only?
                        - uppercase only?
                        - both?
                        
            
            a palindrome is a string that can be read the same left-right as well as right-left
            - this when all non alpha numerical chars are ignored and all letters are lowercase
            
            
        example
            Input: s = "A man, a plan, a canal: Panama"
            Output: true     
            
            
            Input: s = "race a car"
            Output: false
            
        brute force
            have two strings leftRight and rightLeft
            traverse left to tight the string and only add to that string the alphanumerical values
            traverse right to left and do the same for the other string
            compare both of them
            
            runtime: o(n)
            memory: o(n)
            8 min into the problem
            
        optimize
            bcr: o(n)
            can memory be improved? yes, i could use pointers
            
            one pointer at the start and another at the end.
            if the pointer is not pointing at a alpha numerivcal value we traverse until it is or it
            passes the other pointer
            
            if the alphanumerical character is uppercase then we make it lowercase for comparison.
                or is it efficient to just convert everything to lowercase if applicable?
                
                memory: o(1)
                
        test
            - non palindrome
                - has non-alphanumerical values
                - does not have non-alphanumerical
            - palindrome
                - same for alphanumerical
                
                3 min
        */
        
        /*
            "A man, a plan, a canal: Panama"
            "nam a n"
             0123456
        
        */
        
        int n = s.size();
        
        // create pointers
        int start = 0;
        int end = n-1;
        
        while(start < end){
            while(start < end && !isalnum(s[start])) start++;
            while(start < end && !isalnum(s[end])) end--;            
            if(tolower(s[start]) != tolower(s[end])) return false;
            start++;
            end--;
        }
        
        return true;
    }
}; // 20 mins

/*
I like that Im remembering the isalnum, isdigit, tolowe, toupper methods.
I like the solution its elegant, simple and direct.
*/
