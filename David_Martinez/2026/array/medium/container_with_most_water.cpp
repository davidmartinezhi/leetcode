#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
        info
            input
                - integer array "height" of length 'n'
                - There are 'n' vertical lines so in the ith position we go from height 0 to height[i]

                - we have to find that togetherwith the x axis for m a container, the ccoontainer
                    must contain the most water

            output
                - max amount of water a container can store

            constraints
                - what ranges of size can the array have? 2 and 100k, beoth included
                - what ranges of values can height[i] have? 0 and 10k, both included
                - what if all heights are 0? return 0? ill assume yes

        example
        max = 49
                                             j
                               i
            Input: height = [1,8,6,2,5,4,8,3,7]
                            [0,0,0,0,0,0,0,0,0]
            Output: 49 


            start from the extremes
                multiply
                set max capacity
                look for min height
                move that pointer to its corresponding direction
                if they are both the same, check for the next number,
                    whichever has the next smallest, move that one

            


        brute force
            for each element, traverse the rest of numbers
                multiply length of distance between bboth points times the min height
                
            at the end return de max amount a container can store

            runtime o(n^2)
            memory o(1)

        optimize
        best conceivable runtime o(n) we have to traverse the array at least once

        test
            biggest capacity container is in the extremes
            biggest capacity container is leaned right or left
            biggest capacity container is in the indexes in the middle
        */

        // get n
        int n = height.size();

        // declare initial variables
        int start = 0;
        int end = n-1;
        int max_capacity = 0;

        /*  
            49
                             j
               i
            [1,8,6,2,5,4,8,3,7]
        */

        // traverse two pointers -> <-
        while(start < end){
            // set max capacity
            int min_height = min(height[start], height[end]);
            max_capacity = max(max_capacity, (end - start) * min_height);

            // move pointers
            if(height[start] == height[end]){
                int next_start = height[start+1];
                int next_end = height[end-1];

                if(next_start < next_end) start++;
                else end--;
            }
            else if(height[start] < height[end]){
                start++;
            }
            else{
                end--;
            }
        }

        return max_capacity;

    }
};

/*
34 minutes

buena solucion y buen approach la verdad.

fue buena decision el centrarme en buscar cual es el recorrido correcto.
Una vez que supe el recorrdido, el resto fue muy sencillo y en una entrevista incluso
creo que lo podria hacer aun mas rapido.

*/ 
