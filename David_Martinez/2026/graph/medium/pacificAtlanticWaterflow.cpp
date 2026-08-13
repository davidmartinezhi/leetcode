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

/*
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        // input
        //     - heights matrix representing heights above sea level in an island

        // output
        //     - return vector of coordinates of cells were if it rains we can make it
        //         to both oceans
        //     - we can make it to both oceans when all the cells until the ocean are less 
        //         or equal to the current cell.


        // constraints
        //     - range of sizes of m and n? [1, 200]
        //     - range of heights each cell can have? [0, 100k]

        // example
        //     heights = [
        //         [1,2,2,3,5],
        //         [3,2,3,4,4],
        //         [2,4,5,3,1],
        //         [6,7,1,4,5],
        //         [5,1,1,2,4]]

        // brute force
        //     the nature of the problem indicates that we have to do a dfs traversal
        //     we could traverse each cell and do a dfs to see if we get to both oceans
        //         if the next cell is greater, we stop that traversal
        //             we traverse to all 4 directions. up down, left, right

        //     complexity: 
        //         runtime: o(n*m)^2
        //         memory: o(n*m) stack calls

        // optimize
        //     best conceivable runtime: o(n*m) we have to traverse all cells at least once

        //     if current status depends on future statuses, its easier to start from the end
        //         we can start from all borders and calculate to where we can get

        //         we can store all possible cells we can reach from each ocean and then
        //         return the union of those cordinates. the ones shared.

        //     runtime: o(n*m)?
        //     memory: o(n*m) if we store all coordinates

        // test
        //     - we can reach both oceans
        //     - we cannot reach any ocean
        

        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        // traverse top and bottom rows
        for(int col = 0; col < cols; col++){
            dfs(heights, rows, cols, pacific, 0, col, heights[0][col]);
            dfs(heights, rows, cols, atlantic, rows-1, col, heights[rows-1][col]);
        }

        // traverse left and right border
        for(int row = 0; row < rows; row++){
            dfs(heights, rows, cols, pacific, row, 0, heights[row][0]);
            dfs(heights, rows, cols, atlantic, row, cols-1, heights[row][cols-1]);
        }

        vector<vector<int>> result;

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(pacific[row][col] && atlantic[row][col]) result.push_back({row, col});
            }
        }

        return result;
    }


    void dfs(
        vector<vector<int>>& heights, 
        int& rows,
        int&cols,
        vector<vector<bool>> & visited,
        int row,
        int col,
        int prev
        ){

            // base cases: 
            // rows out of bounds
            if(row < 0 || row == rows) return;

            // cols out of bounds
            if(col < 0 || col == cols) return;

            // coordinate in visited
            if(visited[row][col]) return;

            // current value less than prev
            if(heights[row][col] < prev) return;

            // mark as visited
            visited[row][col] = true;

            // visit adj cells
            dfs(heights, rows, cols, visited, row+1, col, heights[row][col]);
            dfs(heights, rows, cols, visited, row-1, col, heights[row][col]);
            dfs(heights, rows, cols, visited, row, col+1, heights[row][col]);
            dfs(heights, rows, cols, visited, row, col-1, heights[row][col]);
        }
};
complexity 
    runtime: o(n*m)
    memory; o(n*m)

I did this problem yesterrday, but its good to remember that when my current status depends
on a future status. It´s better to start from the end and walk backwards.



*/
