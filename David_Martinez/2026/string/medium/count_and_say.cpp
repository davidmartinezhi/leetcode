#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        /*
        info
                input
                    - a positive integer 'n'
                
                output
                    - nth element of the count and say sequence
                
                
                constraints
                    - range of sizes the int can have? 1 and 30 included both
                    - it will fit a 32 bit int? I can assume it does
                
                
        example
        
            Input: n = 4 3 2
            Output: "1211" 
            old "1"
            new "11"
            
            1 -> "1" 3
            2 -> "11" 2
            3 -> "21" 1
            4 -> "1211" 0
            
            
            Input: n = 1
            Output: "1"
            1 -> "1"
            
            "11"
            "21" counter =0 ,number=1
            "1211"
            
        brute force
            recursive function
                empty string reference  or 2
                
                    while not at the end of string
                        while same number, add to counter
                        once we find new number
                            set string reference to the string + counter + number
                            set new number
                            set counter to 0
                                
                    add last counter and number
                    
            runtime: o(n*m) n being n and m being the largest string to traverse
            
        optimize
            best conceivable runtime: o(n*m) we have to traverse n strings and each is m
            we could improve memory by making this iterable
            
        test
            - 1
            - 2
            - 3
            - 4 
        */
                
        // edge case: n is 1
        if(n == 1) return "1";
        
        string str = "1";
        
        for(int i = 1; i < n; i++){
            
            string newStr = "";
            char currNum = str[0];
            int counter = 0;
            
            int j = 0;
            while(j < str.size()){
                while(j < str.size() && str[j] == currNum){
                    counter++;
                    j++;
                }
                newStr += '0' + counter;
                newStr += currNum;
                
                if(j < str.size()){
                    currNum = str[j];
                    counter = 0;
                }
            }
            
            str = newStr;    
        }
        
        return str;
        
        
        // string str = "1";
        
        // countAndSayHelper(str, n-1);
        
        // return str;
    }
    
    /*
             i
        "1211"
        currNum = 1
        counter = 2
        
        newS = "111221"
        
    */
    
    // 29 min left and im about to start the help function
    void countAndSayHelper(string & str, int n ){
        
        // edge case: n is 0, we reached the end
        if(n == 0) return;
        
        // set variables to start counting
        char currNum = str[0];
        int counter = 0;
        int i = 0;
        string newStr = "";
        
        while(i < str.size()){
            
            // while not at the end and new num is the same as prev
            // move and increase counter
            while(i < str.size() && str[i] == currNum) {
                counter++;
                i++;
            }
            
            // in this state we are at the end or in a new num
            // add the number and counter
            newStr += to_string(counter);
            newStr += currNum;
            
            // if not at the end, we have a new number
            if(i < str.size()){
                currNum = str[i];
                counter = 0;                
            }else{
                break;
            }
        }
        
        str = newStr;
        
        countAndSayHelper(str, n-1);   
    }
    // 12 min left and just finished the helper function
    
}; // 45 min. mi error fuer la conversion del counter a char. lo hice mal era '0' + counter en lugar de counter - '0' <- este es para convertir digit to int (we get dist from dig to 0 tipo '3' - '0' = 51 - 48 = 3)
/*
Si es bueno ver la naturaleza del tipo de problema para ver como seria mas simple escribirlo

si era mucho mas sencillo resolverlo con iteracion, ahi me complique la vida al querer hacerlo recursivo

igual muy buen aprendizaje sobre la distribuicion del tiempo.


Igual debo de incluir en las sesiones de estudio checar syntax de c++ para estar mas comodo con el lenguaje, 
ya que ahora no lo uso tanto como antes y uso mucho python o typescript en el trabajo.

*/
