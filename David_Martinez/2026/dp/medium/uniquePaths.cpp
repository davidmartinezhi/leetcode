#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
        info
            input
                - m x n grid
                - initial position is top left
                - we want to get to bottom right
                - robot can only move down or right at any point in time
                
            output
                - number of possible paths the robot can take to reach the obj
                
            constraints
                - range of values n can have? [1, 100]
                - same for n? [1, 100]
                
        example
            m = 3, n = 7
            [
            [1,1,1,1,1,1,1],
            [1,2,3,4,5,6,7],
            [1,3,6,10,15,21,28]
            ]
        
        brute force
            - create grid of size n * m
            - top left corner has value of one
            - on each new cell, the value of that cell is the value of the top cell + value on left
                if they exist
                
                this is a greedy algorithm
            runtime: o(n*m)
            memory: o(n*m)
            
        optimize
            best conceivable runtime: o(n*m)
            memory: can it be improved? it could be, but ill start with the brute force approach first
        
        36 min left
        */
        
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        grid[0][0] = 1;
        
        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                int currVal = grid[row][col];
                if(row - 1 >= 0) currVal += grid[row-1][col];
                if(col - 1 >= 0) currVal += grid[row][col-1];
                grid[row][col] = currVal;
            }
        }
        
        return grid[m-1][n-1]; // 31 minutes left, forgot to update grid with currval until i clicked on submit, also currVal was first set to 0, which is wrong
    }
};
