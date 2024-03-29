#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        /*
        info
            input: string "s" containing only digits
            output: number of ways to decode it
            constraints:
                -string length is between 1 and 100 chars long
                -string contains only digits and may have 0s
                -test cases fit 32-bit integers
                
        example
        
            s = "12"
            -> 2
            
            s = "226"
            -> 3
            
            s = "06"
            -> 0
            
        Brute force
            backtracking to get single digits and composed digits, numbers
            time complexity: O(2^n)
              
        Optimize
            Dynammic Programming, memoization to avoid repeating calculations
            best case running time:
                O(n)
        
        walkthrough
            base cases
                empty string
                digit starts with 0
            recursive call for one digit
            recursive call for 2 digits
        
        test
            empty string
            0 at the beginning
            0 in the middle
            
            check toInt function
            
        */
        /*
        vector<int> dp(s.size()+1, -1);
        return helperDp(s, 0, dp);
        */

                //check we have no leading 0
        if(s[0] == '0') return 0;

        //get size
        int n = s.size();

        //initalize dp vector
        vector<int> dp(s.size()+1, 0);

        //base cases
        dp[0] = 1; //empty string
        dp[1] = 1; //first character

        for(int i = 2; i <= n; i++){

            //if we have no leading 0 by taking two, continue previous count
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1]; //previous 
            }

            //get sum of previous 2 digits
            int twoDigit = stoi(s.substr(i - 2, 2));

            //if sum of both two previous digits, continue that count
            if (twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }

    int helperDp(string & s, int i, vector<int> & dp){
        //base case: empty string
        if(i == s.size()) return 1;

        //base case: starts with 0
        if(s[i] == '0') return 0;

        //base case: cell has already been visited
        if(dp[i] != -1) return dp[i];

        //recursive call
        int result = 0;

        //check with single digit
        result = helperDp(s, i+1, dp);

        //check with double digit
        if(i < s.size()-1 && stoi(s.substr(i,2)) <= 26){
            result += helperDp(s, i+2, dp);
        }

        dp[i] = result;

        return result;
    }
}

/*
Time: 45+ minutes

complexity: 
    time: O(n)
    extra space: O(n)

Es un problem muy relacionado a permutaciones también.
Debería de familiarizarme un poco más con permutaciones


Agregada optimización en logica, pero funcionamiento sigue igual

Agregada solución con tabulacción. Estuvo muy sencilla la logica y si la tuve yo desde el principio pero
por alguna razón batalle en implementarla. Talvez debí pensar en tomar los numeros de atras en lugar 
de los de adelante y eso me hubiera simplificado bastante la logica como para haberlo podido 
implementar por mi propia cuenta rapido desde el principio

También ya sabía que no puedo checar más de 2 numeros atras, ya debo descartar eso una vez que me doy cuenta
que no es util.

Debo de seguír practicando problemas similares
*/