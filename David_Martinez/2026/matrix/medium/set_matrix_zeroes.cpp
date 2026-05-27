#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
        info
        
            input
                - m x n integer matrix 'matrix'
                
                
            - if an element is 0, set the entire column and row to 0
            
            
            output
                - void
            
            
            constraints
                - the update of the matrix must be in place
                - what ranges of values can m have? 1 and 200, included
                - what ranges of values can n have? 1 and 200, included
                - what ranges of values can each cell have? int_min to int_max, included
            
            
        example
        
            Input: matrix = [
                [1,1,0,1],
                [1,1,1,1],
                [0,1,1,1],
                [0,1,0,1]]      
            Output: [
                [1,0,1],
                [0,0,0],
                [1,0,1]]
                
                
            Input: matrix = [
                [0,1,2,0],
                [3,4,5,2],
                [1,3,1,5]]
            Output: [
                [0,0,0,0],
                [0,4,5,0],
                [0,3,1,0]]
                
            
            brute force
                have an array of size m and one of size n
                traverse the matrix and if we reach a 0, store a bool to mark
                    the column and array that will be later transfprmed to 0
                    or I could use a queue for the rows and one for cols to turn into 0
                    
                    
                    runtime: o(m*n)
                    memory: o(n+m)
                    
            optimize
                best conceivable runtime: o(n*m) 7 min
                
                do we even need arrays at all? 
                i can use col 0 and row 0 to mark the lines and rows that will haeve 0
                then traverse just that row and col and convert everything after

            
            test
                - first row is 0
                - first col is 0
                - a cell in the middle is 0
        */
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        bool firstRowZero = false;
        bool firstColZero = false;
        
        // check if first element is 0
        if(matrix[0][0] == 0) {
            firstRowZero = true;
            firstColZero = true;
        }
        
        // check if first row or col will need to be 0
        else{
            for(int col = 1; col < cols; col++){
                if(matrix[0][col] == 0) firstRowZero = true;
            }
            for(int row = 1; row < rows; row++){
                if(matrix[row][0] == 0) firstColZero = true;
            }          
        }
        

        // traverse everything that isnt first row or col, to mark 0s to convert
        for(int row = 1; row < rows; row++){
            for(int col = 1; col < cols; col++){
                if(matrix[row][col] == 0){
                    matrix[row][0] = 0;
                    matrix[0][col] = 0;
                }
            }
        }
        
        // traverse everything to convert if row or col is marked for 0
        for(int row = 1; row < rows; row++){
            for(int col = 1; col < cols; col++){
                if(matrix[row][0] == 0 || matrix[0][col] == 0){
                    matrix[row][col] = 0;
                }
            }
        }
        
        
        // check if first row or col needs to be 0
        if(firstRowZero){
            for(int col = 0; col < cols; col++){
                matrix[0][col] = 0;
            }
        }
        if(firstColZero){
            for(int row = 0; row < rows; row++){
                matrix[row][0] = 0;
            }
        }
        
        
        return;
    }
};

// 29 min
/*

It took me 15 minutes to write everything down, in real life if I just talk through a lot of the implementation
then i can get it even faster.

It is true that when you see a pattern or something being done for the first time it sticks.
This was definitely easier to resolve once I was aware that the first col and row could be used as marks
    it was way easier than the first time i implemented this.

*/
