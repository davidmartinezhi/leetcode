#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        /*
        30 min left
        info
            input
                - array of non overlapping intervals. interval[i] = [starti, endi]
                - sorted in ascending otder

                - newInterval = [start, end]

            output
                - insert newInterval into intervals such that intervals is sill sorted
                    in ascending order.
                
                - return intervals after the insertion

                - we can return a new array


            constraints
                - range of sizes the array can have? [0, 10k]
                - range of values each in can have? [0, 100k]
                - end always lesser than start? yes


        example

            a,b -> c,d

            if c <= b, overlap
            if c > b, insertion is later
            

            while b < c, we add to new array and continue
            while()

            intervals = [
                [1,3],

                  [2,5]

                      [6,9]], 
            
            newInterval = [2,5]

            19 min left

            brute force
                add new interval at the end
                sort

                runtime: o(n log n)
                memory: o(1)

            optimize
                best conceivable runtime: o(n) we have to traverse the list at least once
                memory: o(1)

            test
                - new inserted at beginning of list
                - new inserted at end of list
                - new inserted at some point in between
        */


        int n = intervals.size();
        int i = 0;
        vector<vector<int>> result;

        /*
                                                i
        intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
        new = [3,10]
        result = [[1,2], [3,10], [12, 16]]
        */

        // traverse all the values before insertion
        while(i < n && intervals[i][1] < newInterval[0]){
            result.push_back(intervals[i]);
            i++;
        }

        // traverse the insertion
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        result.push_back(newInterval);

        // traverse the rest of the intervals
        while(i < n){
            result.push_back(intervals[i]);
            i++;
        }

        return result;
        /*
        finished writing the solution with 11 min left

        doing quick walkthrough with an example

        passes, 5 min 15 sec left. 

        walkthrough helped to come up with the logic that stops the merging when
        we jumped to a higher starting number
        
        */
    }
};
