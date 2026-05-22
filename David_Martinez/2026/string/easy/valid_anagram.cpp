#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        /*
        info
            input
                - 2 strings, 's' and 't'
            
            output
                - bool true if 't' is an anagram of 's'
                - else false
            
            constraints
                - ranges of sizes that 's' and 't' can have? 1 and 50k
                - are they only lowercase letters? uppercase? both? ascii? lowercase english
            
        example
            Input: s = "anagram", t = "nagaram"
            Output: true
            
            Input: s = "rat", t = "car"
            Output: false
            
            "abc" "cba" 'a' - 'a' = 0, 'b' - 'a' = 1 ... 'z' - 'a' = 25
            [0,0,0,0]
            
        brute force
            have 2 ht
            traverse one string and for every char increase a counter of how many times it appears
            do the same for the other string
            compare both ht
            
            runtime: o(n)
            memory: o(n)
            
        optimize
            bcr: o(n)
            can memory be improved? yes, we can have an array of size 26 used for counter
            
            set array with all values to 0
            traverse first array and for each char add to that index + 1
            traverse second array and add to each char index to -1
            
            traverse the counters array, if we have anything else than 0, we return false, else true
            
        test
            - string is an anagram
            - string is not an anagram
        */
        
        int counters[26] = {0};
        
        for(char c : t) counters[c - 'a']++;
        for(char c : s) counters[c - 'a']--;
        
        for(int n : counters){
            if(n != 0) return false;
        }
        
        return true;
    }
};

// 15 min

/*
It is good to know how to convert a char into an int.
for capital letters i would do the same but end with a +26

I could also check if they are simply not the same size at first, to avoid
processing information when it is not needed

*/
