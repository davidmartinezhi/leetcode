#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        /*
        19 min left
        info
            input
                - n, represents num of steps to reach top of stairs
                
                - each time we can either climb 1 or 2
                
                - in how many distinct ways can we climb the stairs?
            
            
            output
                - number of distinct ways can we climb the stairs
            
            
            constraints
                - range of sizes that n can have? [1, 45]
                
        example
            Input: n = 2
            Output: 2
            
            1+1
            2
            
            n = 3
            1+1+1
            2+1
            1+2
            
            16 min left
        i know this is a dp problem, but it also give off vibes of backtracking with the idea
        of getting all possible ways to do something. 
        
        Maybe it is actually the same but we can store data to avoid processing information multiple times
        
        brute force
            backtracking. on each step we have one of two options. step 2 or 1
            if we reach the exact top, we add 1 to a counter
            
            runtime: o(2^n) exponential
            memory: o(n)
            
        optimize
            best conceivable runtime: o(n)
            we have to travers the n steps at least once, even if that complexity is not possible
            theres nothing better than o(n)
            
        test
            - n is odd
            - n is even
            
        13.5 min left
        
        walkthrough
        n = 3
        [1,2,3,5]
                5  
                
        array of n size, first 2 valuesa are 1
        
        for each i
        if i - 1 exists, we add it
        same thing with i - 2
        
        runtime: o(n)
        memory: o(n)
        
        9.5 min left
        
        n = 3
        [1,2,0]
             1
        */
        
        /*
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        vector<int> dp(n, 0);
        dp[0] = 1; dp[1] = 1;
        
        for(int i = 0; i < n; i++){            
            if(i-1 >= 0) dp[i] += dp[i-1];
            if(i-2 >= 0) dp[i] += dp[i-2];
        }
        
        return dp[n-1];
        */
        
        int steps[2] = {0,1};
        
        for(int i = 0; i < n; i++){
            int newStep = steps[0] + steps[1];
            
            steps[0] = steps[1];
            steps[1] = newStep;
        }
        
        return steps[1];
        
    } // 5 min 20 seconds left.
};

/*
Es bueno poder pensar en los estados que se ocupan y tratar de solo usar esos. 

Me siento muy comodo con estos problemas

*/
