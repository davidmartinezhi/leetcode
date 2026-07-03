#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        /*
        25 min left
        info
            input
                - array of intervals where interval[i] = [starti, endi]
            
            output
                - array of the non-overlaping that covers all intervals in the array
            
            
            constraints
            
                - range of sizes that the array can have? [1, 10k]
                - range of values that the numbers can have? [0, 10k]
                - is it guaranteed that start is always less than end? yes
                
        22 min 30 sec left
        
        example
            Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
            Output: [[1,6],[8,10],[15,18]]    
            
            Input: intervals = [[1,4],[4,5]]
            Output: [[1,5]]
            
            Input: intervals = [[4,7],[1,4]]
            Output: [[1,7]]
            
            [a,b]
            [c,d]
            
            b >= c
        
            [1,3],
            [2,6]
            
            3 >= 2, overlap
            
        brute force
            traverse all the array
            compare b >= c if it overlaps, merge them. else add the interval to the solution array
            
            runtime: o(n)
            memory: o(answer)
            
            considering that we have to sort the intervals
            the answer is automatically a o(n log n) runtime
            
        optimize
            best conceivable runtime: o(n) we have to traverse all the intervals at least once
            the approach is optimal
            
        test
            - no overlaps exist
            - two intervals overlap
            - 2+ intervals overlap
        
            16 min 40 sec left
            
        walkthrough
         [[1,4],[4,5]]
         
         result = [[1,4]
         
         
         [4,5]
         
         on the index n-1 in result check if end is greater or equal to first in i
         if its greater or equal we merge. else we append
         
        */
        
        /*
        [
        [1,4],
        [4,5]
        ]
        
        result = [[1,5]
        
        */
        /*
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        
        for(int i = 1; i < intervals.size(); i++){
            int n = result.size();
            
            int prevEnd = result[n-1][1];
            int currStart = intervals[i][0];
            
            if(prevEnd >= currStart){
                result[n-1][1] = max(intervals[i][1], result[n-1][1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        
        return result; // accepted, 7 minutes left. both exercise of the day have been resolved. i can clean the code a little
        
        */
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        int start = 0, end = 1;
        
        for(int i = 1; i < intervals.size(); i++){
            int n = result.size();
            
            vector<int> prev = result[n-1];
            vector<int> curr = intervals[i];
            
            if(prev[end] >= curr[start]){
                result[n-1][end] = max(intervals[i][end], result[n-1][end]);
            }
            else{
                result.push_back(curr);
            }
        }
        
        return result; // cleaned, 3 min left
    }
};
