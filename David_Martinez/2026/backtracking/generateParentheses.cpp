#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        /*
        info
            input
                - n pair of parenthesis
            
            
            output
                - generate all combinations of well-formed parentheses
            
            
            constraints
                - range of sizes that n can have [1, 8]
                
        minute 30 sec
        
        example
            Input: n = 3
            Output: ["((()))","(()())","(())()","()(())","()()()"]  
            
            Input: n = 1
            Output: ["()"]
            
        brute force
            we have to do all permutations and keep track of how many open or closed parentheses we
            currently have
            
            runtime: o(k^n) = o(2^(2n)) we have to pick one of two options, 2*n times
            memory: o(n) + o(2^n) of result. n on stack recursively.
            
        optimize
        4 minutes 30 sec
            best conceivable runtime: o(2^(n))
            
            That's the best we can do given the nature of what we are doing
            
        test
            - n = 1
            - n is an odd number
            - n is an even number
            
        6 minutes
        
        walkthrough
        n = 2
        open = 0
        close = 0
        
        "(())"
        ""
        ""
        ()()
        (())
        ((()))
        (())()
        
        if theres an open, we open
        if theres no open, we only close
        close cannot be more than open, if thats the case we return
        
        33 min left, i have the intuition. but not the solid walkthrough
        */
        
        int close = n, open = n;
        string parenthesis = "()";
        vector<string> result;
        // fill(parenthesis, result, open, close, "");
        fillVersion2(result, open, close, "");
        
        return result;
        
    }
    /*
    n = 2
    result = ["(())", 
    open = 1
    close = 1
    ()
    curr = "("
    */
    
    void fillVersion2(vector<string> &result, int open, int close, string currP){
        // base case: we are out of parenthesis to add, this could also be n*2 size
        if(open == 0 && close == 0){
            result.push_back(currP);
            return;
        }
        
        if(open > 0) fillVersion2(result, open - 1, close, currP + '('); // If there's a parentheses to open, open
        if(close > open) fillVersion2(result, open, close - 1, currP + ')'); // If there's a parentheses waiting to be closed, close it
    }
    
    void fill(const string &parenthesis, vector<string> &result, int open, int close, string currP){
        
        // base case: we are out of parenthesis to add, this could also be n*2 size
        if(open == 0 && close == 0){
            result.push_back(currP);
            return;
        }
                
        // base case: we have more close than open. invalid state
        if(currP.size() > 0 && close < open) return;
        
        
        // traverse both options
        for(char p : parenthesis){
            if(p == '(' && open > 0) fill(parenthesis, result, open - 1, close, currP + '(');
            else if(p == ')') fill(parenthesis, result, open, close - 1, currP + ')');
        } // 21 min left and i think im finished.
    }
}; // 13 min left, finished with example walkthrough and submission accepted. i am good at this

/*
La complejidad estuvo casi correcto.

Si es real que O(k^n) con k siendo las posibles variantes y n el tamano de la respuesta
Pero es n*2

Entonces es O(2^(2*n)) pero si estamos haciendo trimming de branches que no aplican como ")("
Entonces es O(2^(2*n)) / n^1.5 Catalan

*/
