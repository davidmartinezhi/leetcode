#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        /*
        info
            input
                - string with digits 2-9 inclusive
            
            
            output
                - all letter combinations that the number could represent
                - answer can be in any order
            
            
            constraints
                - range of sizes the string can have? [1, 4]
                - range of values the chars in the str can have? ['2','9'] digit in this range
                
        example
        22 minutes left
            Input: digits = "23"
            Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

            Input: digits = "2"
            Output: ["a","b","c"]
            
            
        brute force
            - literally this is a problem where i have to get all posiible permutations
            depending on the order of the numbers
            
            runtime: o(1) if the string van only be of size 4 chars, else exponential or more
            memory: o(n)
            
        optimize
            best conceivable runtime: o(1), factorial if it could be of more than 4 strings
            
        test
            - 1 char
            - 2 char
            - 3 char
        */
        
        unordered_map<char, string> digitsHt = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> result;
        
        fillLetterPermutations(digitsHt, digits, result, 0, "");
        
        return result;
    }
    
    void fillLetterPermutations(const unordered_map<char, string> &digitsHt, 
                                const string &digits, 
                                vector<string> &result, 
                                int i, 
                                string currDigit){
        
        // base case: we are out of bounds
        if(i == digits.size()){
            result.push_back(currDigit);
            return;
        }
        
        // if we are still in bounds
        // traverse curr digit and letter mapping       
        for(char letter : digitsHt[digits[i]]){
            fillLetterPermutations(digitsHt, digits, result, i+1, currDigit + letter);
        }
    } // 9 min left and i just finished the algoritm, even if not that clean or elegant as i would like
};// 4 min left, done with examples passed and all.

/*
I fill like i still remember the logic, but that the implementation was not that elegant. Also i only added the i++ and i-- after i got an error of not being able to pass i++ to a temporary thing. and also i forgot how to declare a unorderded map from scratch with values


factorial si es que hay que buscar todos los posibles ordenes de algo

cartesiano si es que es como en este caso. donde por cada digito podemos tener hasta 4 letras
o(4^n)

Factorial (n!):     reordenar n elementos (permutaciones)
Exponencial (k^n):  elegir 1 de k opciones, n veces (producto cartesiano)
cada digito, este es el posible numero de letras

Espacio: O(n) para el stack de recursión (profundidad = n)
         + O(4^n × n) si cuentas el output
         
¿Reordeno/permuto n cosas?          → factorial O(n!)
  (permutations, anagramas completos)

¿Elijo 1 de k opciones, n veces?    → exponencial O(k^n)
  (letterCombinations, subsets es 2^n)

¿Subconjuntos de n elementos?       → O(2^n)
  (cada elemento: incluido o no, 2 opciones, n veces)
*/
