#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        /*
        info
            input
                - 2 strings, "haystack" and "needle"
            
            output
                - index of the first occurence of "needle" in "haystack"
                - return -1 if needle is not in haystack
            
            
            constraints
                - range of sizes that needle can have? between 1 and 10k
                - ranges of sized that haystack can have? same as needle
                    - can we assume that needle will always be smaller than haystack? no
                - of what characters does this consist of lowecase english letters        
        
        example
            Input: haystack = "sadbutsad", needle = "sad" 
            -> 0
            
            Input: haystack = "leetcode", needle = "leeto"
            -> -1
            
        brute force
            from every character in haystack
                traverse needle while the characters following are the same
                    if we traverse till the end, return index
                    
            return -1
            
            complexity
                runtime: o(n*m) n haystack and m needle
                memory: o(1)
                
        optimize
            best conceivable runtime: o(n+m)
            
            i know theres a specific algorithm for this called lms or something like that
            
            minute 7
            
            Ill go ahead with the brute force solution and will look into the bcr after having
            something to show.
            but i know it consists of traversing and having an array of one string
            and then traverse the other string and check prefix
            
        test
            - needle exists in haystack
            - needle does not exists in haystack
        */
        
        /*
            haystack = "butsad", 
                           i
                           j
            
            needle = "sad"
                      k
        */
        
        int n = haystack.size();
        int m = needle.size();
        
        // edge case: needle bigger than haystack
        if(m>n) return -1;
        
        // traverse haystack
        for(int i = 0; i <= n - m; i++){
            
            // set pointers to start traversing both strings for needle
            int j = i;
            int k = 0;
            
            // while not at the end of either string and both chars are the same, continue
            while(j<n && k<m && haystack[j] == needle[k]){
                j++;
                k++;
            }
            
            if(k == m) return i;   // if we traverse the complete needle, we found it
        }
        
        return -1;
    }
}; // 15 min, i need to see the optimized version how to do it
