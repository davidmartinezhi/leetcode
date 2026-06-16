#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        /*
        info
        
        
            input
                - nxm 2d grid, representing a map of '1's and '0's
            
            
            todo
            
            
            output
                - number of islands
            
            
            constraints
                - range of sizes that n can have?[1, 300]
                - range of sizes that m can have? same as n
                - only 1 and 0 as characters? yes
                - all four edges of the grid are water
                - land can be connected up/down left/right
                
                
            3 minutes
            
        example
            Input: grid = [
              ["1","1","1","1","0"],
              ["1","1","0","1","0"],
              ["1","1","0","0","0"],
              ["0","0","0","0","0"]
            ]
            Output: 1   
            -> 1
            
            Input: grid = [
              ["2","2","0","0","0"],
              ["2","2","0","0","0"],
              ["0","0","2","0","0"],
              ["0","0","0","2","2"]
            ]
            Output: 3   
            
        brute force
            Do a DFS search on a 2d matrix
            
            Traverse the matrix
            Everytime we see a "1", increase counter by one and do a recursive traversal
            on all 4 directions changing the values from 1 to 2. meaning we have found an island.
            
            by changing the value then we are no longer going to take part of that island into conside-
            ration.
            
            runtime: o(n*m)
            memory: o(n*m) on stack?
            
        optimize
            best conceivable runtime: o(n*m)
            
        test
            - everything is '1's
            - everything is '0's
            - multiple islands
        */
        
        int rows = grid.size();
        int cols = grid[0].size();
        int numIslands = 0;
        /*
            Input: grid = [
              ["2","2","0","0","0"],
              ["2","2","0","0","0"],
              ["0","0","1","0","0"],
              ["0","0","0","1","1"]
            ]
            Output: 1
        */
        
        // traverse
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == '1'){
                    numIslands++;
                    markVisitedIsland(grid, rows, cols, row, col);
                }
            }
        }
        
        return numIslands;
    }
    
    void markVisitedIsland(vector<vector<char>>&grid, int & rows, int & cols, int row, int col){
        
        // Base case: out of bounds
        if(row < 0 || row >= rows) return;
        if(col < 0 || col >= cols) return;
        
        // Base case: different from unexplored land
        if(grid[row][col] != '1') return;
        
        // update to 2, meaning this land is explored
        grid[row][col] = '2';
        
        // go explore adjacent lands
        markVisitedIsland(grid, rows, cols, row+1, col); // down
        markVisitedIsland(grid, rows, cols, row-1, col); // up
        markVisitedIsland(grid, rows, cols, row, col-1); // left
        markVisitedIsland(grid, rows, cols, row, col+1); // right
        
    } // 26 min left, checking that everything is ok

}; // accepted, 22 min left

/*
Felt really comftable implementing this solution, I still have a great understanding of this.

The memory O(n*m) was correct, as well as O(n*m) runtime.
*/
