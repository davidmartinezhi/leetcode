#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        /*
        info
            input
                - 2 integer arrays
            
            output
                - array of the intesections of both arrays
            
            
            constraints
                -we may return in any order the intersection
                -range of sizes that each array can have? between 1 and 1k, included
                -range of values the ints can have? between 0 and 1k, included
            
            
        example
            Input: nums1 = [1,2,2,1], nums2 = [2,2]
            Output: [2,2]
            
            ht = {
                4: 0,
                9:0, 
                5:1
            }
            
            Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]  
            Output: [4,9] 9, 4
            
        brute force
            use hashtable
            - create empty intersections array
            - traverse the first array and add as key the number and increase count
            - then traverse the second array.
                states:
                    - num is in the ht, and counter above 0
                        - add to intersection array
                        - decrease ht count for that number
                    - num is in the ht, and counter is 0
                        - skip
                    - num not in the ht
                        - ht
                        
            runtime: o(n)
            memory: o(n)
            
        optimize
            - best conceivable runtime: o(n)
            - can we improve memory? we could sort the arrays and then use pointers
            
        test
            - array 1 contains numbers found in array 2
            - array 1 has no match with array 2
        
        */
        
        unordered_map<int, int> counter;
        vector<int> intersection(0);
        
        int n = nums1.size();
        int m = nums2.size();
        
        // traverse first array to add numbers to counter ht
        for(int i = 0; i < n; i++){
            if(counter.find(nums1[i]) == counter.end()) counter[nums1[i]] = 1;
            else counter[nums1[i]]++;
        }
        
        // traverse second array to check which numbers exist
        for(auto num: nums2){
            if(counter.find(num) != counter.end()){
                if(counter[num] > 0){
                    intersection.push_back(num);
                    counter[num]--;
                }
            }
        }
        
        return intersection;
        
    }
};
// 15 min
/*
Me agrado que comprendi rapidamente el como solucionarlo y lo hice bastante a prisa.
siento que mi mayor cuello de botella es escribir toda la info al comienzxo pero
siento que genuinamente me ayuda a comprender la solucion y dar a entender mi razonamiento

Maybe en una entrevista pueda hacer platicado una gran parte de esto.

*/
