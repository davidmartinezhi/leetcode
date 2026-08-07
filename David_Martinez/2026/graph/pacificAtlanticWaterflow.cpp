#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        /*
        30 min left
        info
            input
                - m x n rectangular island "heights"
                - pacific ocean touches left and top edges
                - atlantic ocean touches right and bottom edges

                heights[i][j] represents height above sea level

                rain water flows if neighboring cell's height is less than or equal to the current cell's height


            output
                - 2d list of grid coordinates wehre result[i] = [ii, ji]
                rain water can flow from that cell to both oceans

            contraints
                - range of sizes in the matrix n or m? [1, 200]
                - range of values we can have in the matrix? [0, 100k]


        example

            heights = [
                [1,2,2,3,5],
                [3,2,3,4,4],
                [2,4,5,3,1],
                [6,7,1,4,5],
                [5,1,1,2,4]
                ]

        
        24 min 30 sec left

            heights = [
                [1,2,2,3,5],
                [3,2,3,4,4],
                [2,4,5,3,1],
                [6,7,1,4,5],
                [5,1,1,2,4]
                ]

        brute force
            do a dfs on every cell we visit
                base case
                    out of bounds on west or north
                    and out of bounds on east or south

                    could have flags for both of them

                    move to all 4 directions and have a return that indicates
                    if we reached the ocean

            runtime o(n*m*n*m) we have to traverse the complete matrix
                                and on each cell we traverse the rest of the matrix

            memory: o(n*m) recursive calls

        optimize
            best conceivable runtime: o(n*m) we have to traverse all celds at least once
            and we have to traverse from each one

            the approach could be considered optimal

            we could improve performance having a cache indicating from wchich cells we know
            we can get to an ocean.

            ill start with brute force and then implement the cache

        test
            - no possiblity of getting to the ocean
            - only atlantic ocean
            - only pacific ocean
            - can reach both oceans

            18 min 26 sec left
        */

        // get size
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> result;

        // traverse the matrix
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                int value = heights[row][col];
                bool atlantic = false;
                bool pacific = false;
                reachesBothOceans(heights, rows, cols, atlantic, pacific, row, col, value);
                if(atlantic && pacific){
                    result.push_back({row, col});
                }
            }
        }

        return result;

    }

    // 15 min 15 sec left, about to implement dfs function
    void reachesBothOceans(
        vector<vector<int>>& heights, 
        int & rows, 
        int & cols, 
        bool & atlantic,
        bool & pacific, 
        int row, 
        int col,
        int prevValue){
            /*
            heights = [
                [1,2,2,3,5],
                [3,2,3,4,4],
                [2,4,5,3,1],
                [6,7,1,4,5],
                [5,1,1,2,4]
                ]            
            */

            // check if we have reached west or north ocean
            if(row < 0 || col < 0) {pacific = true; return;}

            // check if we have reached east ot south ocean
            if(row >= rows || col >= cols) {atlantic = true; return;}

            if(atlantic && pacific) return;

            // check if current value is greater than pervious value
            int curr = heights[row][col];
            if(curr > prevValue) return;

            heights[row][col] = INT_MAX;

            reachesBothOceans(heights, rows, cols, atlantic, pacific, row-1, col, curr);
            reachesBothOceans(heights, rows, cols, atlantic, pacific, row+1, col, curr);
            reachesBothOceans(heights, rows, cols, atlantic, pacific, row, col-1, curr);
            reachesBothOceans(heights, rows, cols, atlantic, pacific, row, col+1, curr);

            heights[row][col] = curr;

        } // 5 min 32 sec remaining, finished first version, ill check if i have any typo

        // times up
};
