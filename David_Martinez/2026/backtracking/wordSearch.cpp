#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        /*
        21 minutes left
        
        info
            input
                - mxn grid, board. and a string word
            
            output
                - true if word exists in borad
                - else false
            
            
            constraints
                - range of sizes in n? [1,6]
                - range of sizes in m? [1,6]
                - type of chars to expect? lower and upper case english letters
                - ragne of sizes the word has? [1, 15]
            
            
        example
            Input: board = [
            ["A","B","C","E"],
            ["S","F","C","S"],
            ["A","D","E","E"]], 
            word = "ABCCED"
            Output: true  
        
        brute force
            - DFS on a 2d matrix
            - backtracking
            
            runtime: o(n*m*word) for each cell we look for the word? might need to double check this
            memory: o(n*m) traversal on stack
            
        optimize
            bcr: o(n*m*word) we have to traverse all cells, and for each cell the word in all 4 directions
            
        test
            - word exists
            - word does not exist
        */
        
        int rows = board.size();
        int cols = board[0].size();
        
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(board[row][col] == word[0]){
                    bool wordFound = searchWordInBoard(board, word, rows, cols, row, col, 0);
                    if(wordFound) return true;
                }
            }
        }
        
        return false;
    }
    
    bool searchWordInBoard(vector<vector<char>>& board, 
                           const string &word, 
                           int rows,
                           int cols,
                           int row, 
                           int col, 
                           int wordIdx){
        
        // base case: we have finished, out of bounds in word
        if(wordIdx == word.size()) return true;
        
        // base case: out of bounds on traversal
        if(row < 0 || row >= rows) return false;
        if(col < 0 || col >= cols) return false;
        
        // base case: no match
        if(board[row][col] != word[wordIdx]) return false;
        
        // mark current cell as visited
        char currChar = board[row][col];
        board[row][col] = '#';
        
        // traverse in all 4 directions 
        bool found = searchWordInBoard(board, word, rows, cols, row+1, col, wordIdx+1)
                    || searchWordInBoard(board, word, rows, cols, row-1, col, wordIdx+1)
                    || searchWordInBoard(board, word, rows, cols, row, col+1, wordIdx+1) 
                    || searchWordInBoard(board, word, rows, cols, row, col-1, wordIdx+1); 
        
        board[row][col] = currChar;
        
        return found;
        
    } // ran out of time, i thought the logic wsa excelent but theres a case failing
}; // i was missing the part were i mark were i've been and then remove the mark. its the essence of backtracking, but somehow i forgot about it. i assumed it was the same pattern as numOfIslands. and it is, but i fifnt stop to think about the nature of the problem where after visiting a cell, i could visit a previous cell again, and that's not what we want. and in numOfIslands i still mark the cells that we have traversed, but i forgot to do so here. the only difference is that in numOfIslands i dont care about unmarking the viisted cells and we do here.

/*
real complexity is
runtime: O(n*m) to traverse the board and for each word that begins with the same char as the word its O(4^lenght of word) in 4 directions we are looking for the word lenght. so 4 options to look for word len.

This makes a lot of sense.

the memory complexity is: 
runtime: O(n*m*4^L) L being the length of the word
memory: O(L), with L being the lengths of the word

I have to think during the design face if it´s relevant to keep a path blocked forever or just temporary
this can help me remember to block the paths behind me

*/
