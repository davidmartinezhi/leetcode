#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Node {
    public:
        int val;
        vector<Node*> neighbors;
        Node(){
            val = 0;
            neighbors = vector<Node*>();
        }
        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();           
        }
        Node(int _val, vector<Node*> _neighbors){
            val = _val;
            neighbors = _neighbors;
        }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        /*

        45 min left
        info
            input 
                - ref node in a connected uniderected graph

            output
                - deep compy of the graph


            constraints
                - how many nodes can i have? [0,100]
                - range of values i can have in each node value? [1,100]
                - unidrected graph
                - value is unique for each node? yes
                - no self loops in the graph? no
                - graph is connected and all nodes can be visited? yes

        example
            Input: adjList = [
                1: [2,4],
                2: [1,3],
                3: [2,4],
                4: [1,3]
                ]

            Output: [[2,4],[1,3],[2,4],[1,3]]
            Explanation: There are 4 nodes in the graph.
            1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
            2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
            3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
            4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

        41 min left  

        brute force / optimization
            dfs or bfs
            complexity
                runtime o(edge*nodes)  
                space o(edge* nodes)

        walkthough    
            adjList = [
                            1: [2,4],
                            2: [1,3],
                            3: [2,4],
                            4: [1,3]
                    ]         

            

            bfs
            queue 
            visited 1, 2, 4, 3

            print 1, 2, 4, 3

            get from queue and pop
            print

            traverse all adj
                if not in visited, we are seeing this for the first time
                    add to visited
                    add to queue, so we visit after this


            adjList = [
                            1: [2,4],
                            2: [1,3],
                            3: [2,4],
                            4: [1,3]
                    ]  

            adjListClone = [
                            1: [2,4],
                            2: [1,3],
                            4: [1,3],
                            3: [2,,4]
                            
            ]  

            bfs with cloning
            queue  
            visited 1, 2, 4, 3

            get from queue and pop
            create new node

            traverse all adj
                if not in visited, we are seeing this for the first time
                    add to visited
                    add to queue, so we visit after this
                else if in cloned
                    append adj to current
                    append current to adj
        */

        if(!node) return node;

        queue<Node*> q;
        unordered_set<Node*> visited;
        unordered_map<int, Node*> clones;

        q.push(node);
        visited.insert(node);

        // 27 min left
        while(!q.empty()){

            // get front
            Node* front = q.front(); q.pop();

            // clone
            int cloneVal = front->val;
            Node* clone = new Node(cloneVal);
            clones[cloneVal] = clone;

            // traverse adj nodes of front
            for(Node* n : front->neighbors){
                if(visited.find(n) == visited.end()){ // add to queue, to visit later
                    visited.insert(n);
                    q.push(n);
                }
                else if(clones.find(n->val) != clones.end()){ // has been visited and exists in clones, connect
                    Node* curr = clones[cloneVal];
                    Node* toConnect = clones[n->val];
                    curr->neighbors.push_back(toConnect);
                    toConnect->neighbors.push_back(curr);
                }
            }
        }

        return clones[node->val]; // 19 min left, i saw it has to be an unordered map the clone ds
        // 8 min left, i have this error Line 154: Char 29: runtime error: member access within null pointer of type 'Node' (solution.cpp) on the return
        // it was correct, my error was that i forgot to add to the initial queeue and visited, the node. also the ds correction was made by minute 14
        // this is a very interesing problem, it helps rationalize both dfs and bfs, it super useful specially now that im revisiting this topics
    }

/*
        if(!node) return node;

        queue<Node*> q;
        unordered_set<Node*> visited;
        unordered_map<int, Node*> clones;
        
        clones[node->val] = new Node(node->val);
        q.push(node);
        visited.insert(node);

        // 27 min left
        while(!q.empty()){

            // get front
            Node* front = q.front(); q.pop();

            // traverse adj nodes of front
            for(Node* n : front->neighbors){
                if(visited.find(n) == visited.end()){ // if not visited
                    visited.insert(n); // mark
                    q.push(n); // push to queue
                    Node* aux = new Node(n->val); // create node with that value
                    clones[n->val] = aux; // insert to clones
                }
                
                Node* clone = clones[n->val];
                clones[front->val]->neighbors.push_back(clone);

            }
        }

        return clones[node->val];

*/
};
