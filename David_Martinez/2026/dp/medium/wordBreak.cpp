#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*
        45 min left
        info
            input
                - string "s"
                - dict of strings in a vector "wordDict"

            output
                - true if s can be segmented in a space-separated sequence
                    or noe or more dict words

                - else false

                    - the same word may be reused


            constraints
                - range of sizes that s can have? [1, 300]
                - type of chars that each char in s can be? lowercase english letters
                - number of strings the dict can have? [1, 1k]
                - range of sizes the strings in the dictionary can have? [1, 20]
                - are all strings in word dict unique?

            41 min left

            example
                Input: s = "leetcode", wordDict = ["leet","code"]
                Output: true

                Input: s = "applepenapple", wordDict = ["apple","pen"]
                Output: true       

                Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
                Output: false    

            brute force
                Could do a backtracking where we traverse until we find a word,
                if word found, mark that index and look for another word starting from there. 

                do that until we reach the end.   

                runtime: es O(2^n) en el peor caso, porque en cada posición decides si cortas o no, dando 2^n particiones posibles 
                memory: o(dict size) if we do recursive calls

                are the complexities correct?

            optimize
                best conceivable runtime? o(s+(wordDict*longest word))
                O(n² ) o O(n² × m) se debe de considerar cada par de posiciones.
                    un mal bcr puede hacer misguided approach y meter duda.
                    eso es muy optimo sin considerar que se debe de checar todas
                    las combinaciones. Pero bueno, sabemos que no hay nada mejor que eso

                if we can use backtracking and measure states, this means
                this is probably a dynammic programming problem

                how can i store the states?

                s = "applepenapple", wordDict = ["apple","pen"]

                35 min left

                s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]

                  "c a t s a n d o g"
                  [f,f,f,f,f,f,t,f,f,t]
                               s     e

                               we have a word here

                               so we mark the index of d as true
                               but how can we keep track of where a string starts or ends?


                  "c a t s a n d o g"
                  [f,f,f,f,f,f,t,f,f,t]
                               s     e
                   0,1,2,3,4,5,6,7,8,9

                im thinking that from every true, i could traverse and look for every word
                in the dictionary. but is there a more efficient traversal?

                28 min left

                okay, then we traverse until we find a true and repeat from there

                runtime: o(n*(dict size * longest word))

                okay, ill do this approach first

        test:
            - we can form s from words in the dict
            - we cannot

        additional notes:
        
        */

        int n = s.size();

        // create dp avector and set las value as true
        vector<bool> dp(n+1, false);
        dp[n] = true;

        // traverse backwards
        for(int i = n; i >= 0; i--){
            
            // if no connection to the end, skip it
            if(!dp[i]) continue;

            // traverse all words in the dict
            for(string word : wordDict){

                int m = word.size();

                // check that word is not out of bounds
                if(i-m < 0) continue;

                // get chunk of size word from s
                string substring = s.substr(i-m, m);

                // if substring and word match, set idx where word begins to value in i
                if(substring == word) dp[i-m] = dp[i];
            }
        }

        return dp[0]; 
        /*
        // finished first version
        about to check logic before submitting

        accepterd, 12 minutes left.

        It is a great note that when a state depends on future states.
            it is easier to calculate a value starting from the future state.

        It is also good to note that when there's a big problem with sub problems
            and its more important to solve the big problem (making it to the end)
            before the subproblems of knowing if a word is inside a substring
            in that case its better to solve from the end backwards also.

        There´s an unoerdered set O(n^2*m)
        */

/*
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<bool> dp(n+1, false);
    dp[0] = true;   // string vacío al inicio es segmentable

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            // si [0,j) es segmentable Y [j,i) es una palabra
            if(dp[j] && dict.count(s.substr(j, i-j))){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];

*/
    }
};
