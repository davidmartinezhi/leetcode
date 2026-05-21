#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /*
        info
                input
                    - 9x9 matrix 'board'
                    - determine if its valid
                        - only the cells with values are to be evaluated with t he following rules
                            - each row must have numbers 1-9 without repetition
                            - each colujmn must contains 1-9 without repetition
                            - each 3x3 sub boxes must contain 1-9 without repetition
                
                output
                    - bool if a sudoku borad is valid
                
                constraints
                    - range of sized of column? 9
                    - range of sizes of row? 9
                    - range of values a number can have? 1-9 or a .(values are chars)
                
        example
                Input: board = 
                [["5","3",".",".","7",".",".",".","."]
                ,["6",".",".","1","9","5",".",".","."]
                ,[".","9","8",".",".",".",".","6","."]
                ,["8",".",".",".","6",".",".",".","3"]
                ,["4",".",".","8",".","3",".",".","1"]
                ,["7",".",".",".","2",".",".",".","6"]
                ,[".","6",".",".",".",".","2","8","."]
                ,[".",".",".","4","1","9",".",".","5"]
                ,[".",".",".",".","8",".",".","7","9"]]
                Output: true
                
                Input: board = 
                [["8","3",".",".","7",".",".",".","."]
                ,["6",".",".","1","9","5",".",".","."]
                ,[".","9","8",".",".",".",".","6","."]
                ,["8",".",".",".","6",".",".",".","3"]
                ,["4",".",".","8",".","3",".",".","1"]
                ,["7",".",".",".","2",".",".",".","6"]
                ,[".","6",".",".",".",".","2","8","."]
                ,[".",".",".","4","1","9",".",".","5"]
                ,[".",".",".",".","8",".",".","7","9"]]
                Output: false
                
        best conceivable runtime: n*m
        
        walkthrough
            traverse all rows and check that numbers are not repeated
            traverse al cols and check that numbers are not repeated
            travers 3x3 and check that the numbers are not repeated
            
        test
            - row has repeated nums
            - col has repeated nums
            - 3x3 has repeated nums
            - valid matrix
        
        */
        
        return validate_rows_cols(board) && validate_3x3_matrix(board);
        
    }
    
    bool validate_rows_cols(const vector<vector<char>>& board){
        /*
        Traverse rows and cols of board
        */
        unordered_set<char> set_col;
        unordered_set<char> set_row;
        
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                char col_val = board[row][col];
                char row_val = board[col][row];
                
                // found for the first time and not a dot
                if(col_val != '.' && !set_col.contains(col_val)){
                    set_col.insert(col_val);
                }
                else if(set_col.contains(col_val)){
                    return false;
                }
                
                // found for the first time and not a dot
                if(row_val != '.' && !set_row.contains(row_val)){
                    set_row.insert(row_val);
                }
                else if(set_row.contains(row_val)){
                    return false;
                }
            }
            set_col.clear();
            set_row.clear();
        }
        
        return true;
    }
    
    bool validate_3x3_matrix(const vector<vector<char>>& board){
        /*
        Traverse the 9 x 9 matrix in a 3x3 traversal
        */
        unordered_set<char> set;
        
        for(int row = 0; row < 9; row += 3){
            for(int col = 0; col < 9; col += 3){
                
                for(int inner_row = row; inner_row < row+3; inner_row++){
                    for(int inner_col = col; inner_col < col+3; inner_col++){
                        char val = board[inner_row][inner_col];
                        if(val != '.' && !set.contains(val)){
                            set.insert(val);
                        }
                        else if(set.contains(val)){
                            return false;
                        }
                    }
                }
                set.clear();
            }
        }
        return true;
    }
};
