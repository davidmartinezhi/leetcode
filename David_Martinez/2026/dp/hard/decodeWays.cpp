#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        /*
        45 min left
        info
            input
                - string s
                    - message of numbers encoded
                    
            todo
                - decode the message via the following mapping
                    "1" -> 'A'
                    "2" -> 'B'
                    ...
                    "25" -> 'Y'
                    "26" -> 'Z'     
                    
                not all messages can be decoded
                "AAJF" with the grouping (1, 1, 10, 6)
                "KJF" with the grouping (11, 10, 6)
                
            output
                - number of ways to decode the string
                
                
            constraints
                - range of sizes the string can have? [1, 100]
                - range of numbers each digit can have? 0,26
                - containts only digits and may contain leading zeroes
                
            40 min left
            
            example
                Input: s = "12"

                Output: 2

                Explanation:

                "12" could be decoded as "AB" (1 2) or "L" (12).
                

                Input: s = "226"

                Output: 3

                Explanation:

                "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
                
                Input: s = "06"

                Output: 0

                Explanation:

                "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").                  In this case, the string is not a valid encoding, so return 0.   
                
            brute force
                basically i have to find all possibel permutations of numbers that are between 1 and 26
                and they do not begin with 0s.
                
                runtime: o(2^n) for each number we have the option of taking it or not
                memory: o(n) with n being the recursive calls
            optimize
                best conceivable runtime: its exponential if we need all possible cmbinations
                
            test
                - leading 0
                - no 0s
                - 0s in the body
            
            35 min left
            
            walkthrough
                "226"
                "2" 
                "22"
                "226" no
                
                states:
                    we either continue the "digits concatenation"
                    start the "concatenation" a new
                
                
                
                
                base case, if the number is less than 1 or bigger than 26, return.
                if we reach the end of the string, add + 1 to the combinations counter
                
                do a call concatenating the current number with the previous
                
                do a call starting anew with the new number
                
                29 min left      
        */
        
        /*
        226
        [1,1,1,0]
        
        */
        
        int n = s.size();
        if(s[0] == '0') return 0;
        
        vector<int>dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            int oneDigit = (s[i-1] - '0');
            if(oneDigit >= 1 && oneDigit <= 9) dp[i] += dp[i-1];
            
            int twoDigits = ((s[i-2] - '0')*10) + ((s[i-1] - '0'));
            if(twoDigits >= 10 && twoDigits <= 26) dp[i] += dp[i-2];
        }
        
        return dp[n];
        /*
        int count = 0;

        decode(s, count, 0, "");
        
        return count;
        */
        
    }
    
    void decode(const string & s, int &count, int idx, string currStr){
                        
        // invalid states
        if(currStr != "" && (stoi(currStr) < 1 || stoi(currStr) > 26)) return;
        
        // we have reached the end, found a way to decode
        if(idx == s.size()) {count++; return;}
        
        currStr += s[idx];
        
        // keep the digits concatenation going
        decode(s, count, idx + 1, currStr);
        
        // start the digits concatenation anew if currStr has more than 1 digit
        if(currStr.size() > 1) decode(s, count, idx + 1, string(1, s[idx]));
        
        // finished writing the first version, 21 min left
        /*
        prove of logic
        
        s = "12"
        count = 0
        idx 1
        currStr = "1"
        
        
            currStr = "12"
            idx 2
            counter 1
            
            currStr = "2"
            idx 2
            counter 2
            
            
        10 min left. i have an error in the logic
        
        6 min left, it worked with everything but i got a time limit exceeded. for the following input: "111111111111111111111111111111111111111111111"
        
        I think i just commited the error of solving this problem with backtracking instead of actually using dp so we dont have to recompute operations
        
        "1 2"
        [1,2]
        
        okay, for eaach digit i could check if the number by itself applies and also if the 
        previous number concatenated with the current number is valid, then we sum again
        
         2 2 6
        [1,2,3]
        
        okay, thats the answer
        
        2 2 0 6
       [1,2,0,3]
        
            
       I ran of time because of this mistake
        */
        
    
    }
};
