#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        /*
        info
            input: string containing digits from 0-9 inclusive
            output: all possible letter combinations that the number could represent
            constraints:
                *digits length is from 0 to 4 inclusive
                *each character in the string is a digint from 2-9 inclusive
                
        example
            digits = "23"
            -> ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
            
            digits = ""
            -> []
            
            digits = "2"
            -> ["a", "b", "c"]
            
        brute force
            backtracking, because we need all possible combinations of letters
            
        optimize
            best case runningtime: O(3^n) exponential
            can we improve memory? use the original string to keep the memory in O(1)
            
        walkthrough
            
            if length is the same as string length, add string to result
        
            for each letter in the string
                for( int i = 0; i < 3; i++){
                    
                    add char to input string = string + string[i] - 'a' + i;
                    
                    backtracking call
                    
                    remove char from input string
                }
                
        test
            * emmpty string
            * single char in string
            * string with multiple chars
            *string with number thsat has 4 characters
        
        */
        
        //check if string has digits
        if(digits.size() == 0) return {};
        
        //declare variables
        string str = "";
        vector<string> digitCombinations;
        unordered_map<char, vector<char>> digitChars;
        int currIdx = 0;
        
        //fill unordered map
        digitChars['2'] = {'a', 'b', 'c'};
        digitChars['3'] = {'d', 'e', 'f'};
        digitChars['4'] = {'g', 'h', 'i'};
        digitChars['5'] = {'j', 'k', 'l'};
        digitChars['6'] = {'m', 'n', 'o'};
        digitChars['7'] = {'p', 'q', 'r', 's'};
        digitChars['8'] = {'t', 'u', 'v'};
        digitChars['9'] = {'w', 'x', 'y', 'z'};

        helperLetterCombinations(digits, digitChars, digitCombinations, str, currIdx);
        
        return digitCombinations;
        
        
    }
    
    void helperLetterCombinations(string & digits, unordered_map<char, vector<char>> & digitChars, vector<string> & digitCombinations, string & str, int & currIdx){
        
        //base case
        //same size as sigits
        if(str.size() == digits.size()){
            digitCombinations.push_back(str);
            return;
        }
        
        //traverse digit characters
        for(int i = 0; i < digitChars[digits[currIdx]].size(); i++){
            
            //add letter
            str.push_back(digitChars[digits[currIdx]][i]);
            currIdx++;
            
            //call backtracking function
            helperLetterCombinations(digits, digitChars, digitCombinations, str, currIdx);
            
            //remove letter
            str.pop_back();  
            currIdx--;
        }
            
            
        return;
    }
};


/*
Notes:
Completion time: 39 minutes (first attempt)

Complexity (I need to double check complexity on backtracking to refresh memory): 
    runtime: O(!n) exponential
    extra space: O(n) wich will be stack calls


I felt comfortable implementing the solution, I notices that I have a good intuition on 
what approach to use and how the information is going to be handled in the code, but
some varibale declarations I only notices I needed them while coding, maybe stopping to
double check the walkthrough could be beneficial.

Overall, I feel proud of myself that I could come up with a good solution as fast as I did.

I discovered I can use pushback and popback on strings, this could be very useful for future solutions
*/
