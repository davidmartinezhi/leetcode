#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        /*
        info
        
            input
                - string 's'
                
            - i have to imlpement the myAtoi function, converts a str to a 32 bit int
            algorith
                - ignore any leading whitespace
                - determine sign by checking if the next char is a - or +
                - skip leading 0s, if no digits then return 0
                - rounding, if digit passes int_min or int_max return int_min or int_max
            
            output
                - integer as final restult
                
            constraints
                - ranges of sizes the string can have? between 0 and 200 included
                - what type of characters can the string contain?
                    - can we have multiple plus or minus signs?
                    - can we have letters or unicode or ascii?
                    
                    it contains english letters, digits 0 - 9, whitespace, plus, minus and dot
            
        example
            Input: s = "42"
            Output: 42        
        
            res = 0
            res = 0 * 10 + (0 * -1) = 0
            res = 0 * 10 + (4*-1) = -4
            res = -4 * 10 + (2 * -1) = -42
                            i
            Input: s = " -042"
            Output: -42        
        
            res = 0
            res = 0 * 10 + (1*1) = 1
            res = 1 * 10 = 10 + (3*1) = 13
            res = 13 * 10 = 130 + (3*1) = 133
            res = 133 * 10 = 1330 + (7*1) = 1337
                          i
            Input: s = "1337c0d3"
            Output: 1337
            
            Input: s = "words and 987"
            Output: 0
            
            Input: s = "0-1"
            Output: 0
            
        brute force
            traverse
            while whitespace, continue.
            
            once a none whitespace char is found
                if we find a letter or a dot, return 0
                if we find a - or +, assign the symbol for the return value and i++
                while char is a digit, add it to answer and i++
                
            runtime: o(n)
            memory: o(1)
            
        optimize
            bcr: o(n)
            
        test
            - positive num
            - negative num
            - leading 0
            - leading letter
            - has + sign
            - has - sign
            - grater than int max
            - greater than int min
        */
        
        int n = s.size();
        int i = 0;
        int sign = 1;
        int res = 0;
        
        // traverse all the white space
        while(i < n && s[i] == ' ') i++;
        
        // check if we have reached an invalid state
        if(i == n || isalpha(s[i]) || s[i] == '.') return 0;
        
        // check if we have found a sign
        if(s[i] == '+' || s[i] == '-'){
            if(s[i] == '-') sign = -1;
            i++;
        }
        
        // traverse digits until we reach an invalid state
        while(i < n && isdigit(s[i])){
            // extract number to add
            int num = s[i] - '0';
            num *= sign;
            
            // check if we are not passing any limit
            // int_max
            if(res > INT_MAX/10 || (res == INT_MAX/10 && num > 7)) return INT_MAX;
            
            // int_min
            if(res < INT_MIN/10 || (res == INT_MIN/10 && num < -8)) return INT_MIN;
            
            // add number to result
            res = res * 10 + num;
            
            // move pointer
            i++;
        }
        
        return res;
        
    }
};
// 34 min

/*
Im proud of the elegance in my solution
I took a lot of time just to write the information, in a in-person interview i would mention most
of that info verbally so its okay if it took a little longer here.

Still im glad that i remember how to handle int overflow and conversion of chat to int, as
well as int to char

This is good progress and I can feel my leetcode skills coming back 
and entering flow state while answering the question

*/
