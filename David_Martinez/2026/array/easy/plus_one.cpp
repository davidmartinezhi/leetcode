#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        /*
        info
                input
                    - large integer represented as an integer array 'digits'
                    - each index in digits is the ith digit of the integer
                    - digits are odered from most to less significant
                    - large int does not contain any leading 0s
                    
                    - add one to the large int and return
                
                output
                    - digit array + 1
                
                
                constraints
                    - ranges of sizes of the array? between 1 and 100
                    - ranges of values on each digit in the array? 0 and 9
                    - can we have a negative number?
                    - no leading 0s
                
                
        example
            Input: digits = [1,2,3]
            Output: [1,2,4]
            
            Input: digits = [4,3,2,1]
            Output: [4,3,2,2]
            
            Input: digits = [9]
            Output: [1,0]
            
            digits = [0,0,0]
            [1,3,0]
            
            states
                last number is 9:
                    - turn to 0, and add 1 to the left. do this until we reach a non 9 number
                    - if we traverse all the array right to left and all numbers were 9
                        `- turn index 0 to 1 and append a 0 at the end
                        
        optimize
            bcr: o(n)
            
            memory, could be o(1) but if i create a new one then it is o(n)
            
        test
            - array of all 9
            - array of one 9 at the end
            - array of two 9 at the end
            - no 9
        */
        
        int n = digits.size();
        vector<int> digits_cp(digits.begin(), digits.end());
        
        // traverse array from right to left
        for(int i = n-1; i >= 0; i--){
            if(digits_cp[i] != 9){
                digits_cp[i]++;
                return digits_cp;
            }
            else{
                digits_cp[i] = 0;
            }
        }
        
        // check if we have a leading 0, that means we had all 9
        if(digits_cp[0] == 0){
            digits_cp[0] = 1;
            digits_cp.push_back(0);
        }
        
        return digits_cp;
    }
};

// 20 min

/*
Este problema recuerdo que cuando lo hice pro p[rimera vez hace unos anios me llevo
algo de tiempo.

me gusto que me siento con una gran intuicion para encontrar soluciones, siento que luego luego
comprendi la naturaleza de por donde buscar la solucion. ademas siento que de tiempo estuvo bien.

*/
