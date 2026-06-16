#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /*
        21 min left
        info
                input
                    - 2 int arrays sorted in non-decreasing order
                    - int m and n, representing the amount of lements each array has
                    
                todo
                    - merge nums 1 and nums 2 into a singles array in asc order
                
                output
                    - nothing
                    - final sorted array should be inside of nums1
                        - nums1 has a length m+n
                        - first m elements are from num1, the rest are set to 0
                        - the other n are set by nums2
                
                
                constraints
                    - range of sizes both arrays can have, meaning n and m possible values?
                        - n + m [1, 200]
                        - n or m [0, 200]
                        - nums1[i] and nums2[i] [-10^9, 10^9]
                        
        17 min left
        
        example
            Input: 
                               i
                nums1 = [1,2,2,0,0,0], m = 3, 
                
                         j 
                nums2 = [3,5,6], n = 3
                Output: [1,2,2,3,5,6] 
                
                
                nums1 = [1], m = 1, 
                nums2 = [], n = 0
                [1]
                
                nums1 = [0], m = 0, 
                nums2 = [1], n = 1  
                [1]
                
                                   k
                             i
                nums1 = [1,5,6,0,0,0], m = 3, 
                
                             j 
                nums2 = [3,4,7], n = 3
                
        brute force
            have a pointer at the start of each array
            have a new array
            add whichever value is smaller and move the pointer of that array
            then replace every value in nums 1 with every value of that array
            
            runtime: o(n)
            memory: o(n)
            
        optimize
            best conceivable runtime: o(n)
            memory: can it be improved? yes with pointers
            
        test
            - empty nums 1
            - empty nums 2
            - nums1 has a value greater 
            - nums2 has a value greater
            
        11 minutes left, have an idea of how 2 pointers solution work
                
                       
        add all nums 2 to the end of nums 1
        have a pointer at beginning of each section
        at i is bigger, continue traversing
        at j is bigger, swap and move j 
        
        ill leave j static, only moving when we swap
        
        */
        
        // Edge case: num1 empty
        if(m == 0){
            nums1 = nums2;
            return;
        }
        
        // Edge case: nums2 empty
        if(n == 0) return;
        
        int k = n+m-1, i = m - 1, j = n - 1;
        
        while(i >= 0 && j >= 0 && k >= 0){
            if(nums1[i] < nums2[j]) nums1[k--] = nums2[j--];
            else nums1[k--] = nums1[i--];
        }
        
        while(j >= 0) nums1[k--] = nums2[j--];

    }
}; // completed


/*
Comenzar por el final es el approach ideal.

Literalmente cuando se trabaja con modificar in-place a mi parecer es ideal el pensar.
"Como es que no puedo pisar datos sin procesar".

Comenzar desde el final a comparar si es ideal y usar expresiones mas semanticas de c++ si puede
ser una gran opcion. asi como el --.


*/
