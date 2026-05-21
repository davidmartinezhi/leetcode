#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      /*
      info
            input
                - nxn 2d matrix representing an image
                
                -rotate the image by 90 degrees (clockwise)
            
            output
                - void
            
            
            constraints
                - the rotation has to be in-place
                - ranges of values that n can have? between 1 and 20, included
                - ranges of values the int in matrix can have? -1000 and 1000
            
            
      example
                         20 10 00
                         00 01 02 
        Input: matrix = [[1,4,7], 02 00
                         [2,5,8], 12 01
                         [3,6,9]] 22 02
                         
                         0 1 2  (0,0) (0,1) (0,2)
                         0 1 2        (1,1) (1,2)
                           1 2              (2,2)
                             2
                           
                         
                         for each iteration of the cols in a row
                         the size of the row - 1
                         
                         0 to n-1
                            i to n-1
                         
                         
        Output: [[7,4,1],
                 [8,5,2],
                 [9,6,3]]
                 
                 
        best conceivable runtime
            - nxn
            with this approach we have memory of o(1)
            
        test
            - array of size 1
            - array of size bigger than 1
      */  
        
        int n = matrix.size();
        
        if(n == 1) return;
        
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
        return;
    }
};
// 35 minutes
