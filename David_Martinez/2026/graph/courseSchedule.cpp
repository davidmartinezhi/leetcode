#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /*
        30 min left

        info
            input
                - int total of numCourses, labeled from 0 to numCourses - 1
                - array prerequisites, prer...[i] = [ai, bi] <- we have to take b first if we want to take a

            output
                - true if we can finish all courses, else false


            constraints
                - number of nodes in the graph? [1, 2k]
                - size of prerequisites? [0, 5k]
                - are all node values from 0 to numcourses-1? or can they be diff? the first

        example
            [0,1] indicates i has to take course 0, first to take course 1

            so 1 -> 0

            25 min 32 sec left

            numCourses = 2, prerequisites = [[1,0]]
            Output: true

            1 -> 0

            if we count all courses in order, with no cycles -> true

            Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
            Output: false   
            1 -> 0
              <-     

            we need courses that are the start, with no other courses pointing to them.
                this has to be true all the time, for each node when we are visiting them}
                when we visit a node, it needs to have no other nodes pointing to them.

            how do i know when graphs is a good approach to model somehting?

        brute force/optimize
            topological sort
            1. get the count from each node, how many other nodes are pointing there
            2. add them to the queue
            3. start traversing with bfs
                - each node we process we increase count
                - we visit adjacent nodes and reduce the indegree number
                - if that adj node indegree is 0, add to queue
            4. if numCourses is different from all the courses we have seen from the starts, false.
          
            complexity: o(n+v) + o(n) n being the prerequisites
            memory: o(n+v)

        test
            - not directed acyclic graph
            - directed acyclic graph

        18 min and 18 sec left


        1 -> 0
        */

        if(prerequisites.size() == 0) return true;

        unordered_map<int, vector<int>> adjList; // to store courses and adjacencies
        unordered_map<int, int> indegreeCounts; // course: indegree (prerequisites count)
        unordered_set<int> allCourses;
        queue<int> q; // courses to traverse in bfs
        int counter = 0; // store how many courses we have processed

        // fill the adj list
        for(vector<int> pre : prerequisites){
            adjList[pre[1]].push_back(pre[0]); // 1 -> 0
            indegreeCounts[pre[0]]++; // 0 is pointed at by the prerequisite
            allCourses.insert(pre[0]);
            allCourses.insert(pre[1]);
        }

        // look for values in adj list with no prerequisite and add to queue, first courses
        for(int course: allCourses){
            if(indegreeCounts[course] == 0) q.push(course);
        }

        // do a bfs
        while(!q.empty()){
            // get course and increase counter
            int course = q.front(); q.pop();
            counter++;

            // traverse adj
            for(int adj : adjList[course]){
                indegreeCounts[adj]--;
                if(indegreeCounts[adj] == 0) q.push(adj);
            }
        }

        return counter == numCourses;
        // times over
    }
};

/*
I had a bug that I was trversing the indegree ht to find the one with 0, but the start courses
would not be there because they are the first and i have to traverse all possible courses to find the 0

Still, I remembered pretty fast the algorithm and the logic behind.

I had everything ready in 20-23 minutes if I didn´t had that error in logic.

But very interesting, I should try to see more problems that involve topological sort

*/
