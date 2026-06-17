#include <iostream>
using namespace std; 

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        /*
        info
            input
                - n, number of versions. starting from 1
            
            
            output
                - number of the first bad version
            
            
            constraints
                - range of values that 'n' can have? [1,INT_MAX]
                - bad version is alwas less or equal to n and more or equal to 1
                
        exmple
            2 minutes
            
            n = 5, bad = 4
            
            Explanation:
            call isBadVersion(3) -> false
            call isBadVersion(5) -> true
            call isBadVersion(4) -> true
            Then 4 is the first bad version.
            
        brute force
            if we have no idea were the last bas version could be
            we could do a binary search until we find the wrong version right?
            
            runtime: o(log n)
            memory: o(log n in stack)
            
        optimize
            best conceivable runtime: o(log n) we have to traverse and the best way is going from
            middle to middle to middle
            
        test
            - bad verion is n
            - bad version is 1
            - bad version is in between
            
            5 minutes
                g b
            1 2 3 4 5
                  i
                  j
                  m
                
                m is good, i moves to m + 1
                m is bad, j moves to m
                
                34 min left after figuring out with the walkthrough the behaviour
        */
        
        int start = 0;
         while(start < n){
             int m = start + (n-start) / 2;
             if(isBadVersion(m)) n = m;
             else start = m + 1;
             // this binary search is when we need an exact value, same with findig pivot
             // when we pass mid + 1 or end mid - 1 is when value could or could not exist
         }
        
        return start;
        
        /*
        int badVersion = 0;
        binarySearchOfBadVersion(badVersion, 1, n);
        return badVersion;
        */
    }
    
    void binarySearchOfBadVersion(int & badVersion, int start , int end){
        //base case: start and end have crossed
        if(start == end){
            badVersion = start;
            return;
        }
        
        int mid = start + (end-start) / 2;
        
        if(isBadVersion(mid)){
            binarySearchOfBadVersion(badVersion, start, mid);
        }else{
            binarySearchOfBadVersion(badVersion, mid+1, end);
        }
    }
    // 26 min left
    
    
}; // completed, everything passed, 25 min left
