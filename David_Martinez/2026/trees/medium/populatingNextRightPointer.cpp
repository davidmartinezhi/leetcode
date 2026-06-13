#include <iostream>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        /*
        info
            input
                - root of a perfect binary tree
                    - all leaves are on the same level
                    - every parent has 2 children
                    - all next pointers are set to nullptr initially
                    
            todo
                - populate each next pointer to its next right node, if no next, then nullptr
            
            output
                - root
            
            
            constraints
                - range of num of nodes the tree can have? [0, 4096]
                - range of values each node can have? [-1k,1k]
                - guaranteed all leaves are on same level and every parent has 2 children
            4 min
        example
        
            Input: root = [1,2,3,4,5,6,7]
            Output: [1,#,2,3,#,4,5,6,7,#]
            
                                1->n
                        2 ->              3->n
                        
                4 ->          5->   6 ->          7->n
                
        brute force
            we can do a level by level traversal 
            have an array with all the nodes in a level, make nodes from index 0 until second to last
            to point to the one to the right on each level
            
            runtime: o(n) we have to traverse all nodes
            memory: o(widest level) log n?
            
        optimize
            best conceivable runtime: o(n)
            
            it can be done recursively also.
            
            level by level makes this more explicit and can take scenarios where
            the tree is not perfectly balanced
            
        test
            - 0 nodes
            - 1 node
            - 3 nodes
        */
        
        // Edge case: no node
        if(!root) return nullptr;
        
        // level by level traversal
        queue<Node*> q;
        q.push(root);
        /*
        q =  4, 5, 6, 7
        sz = 2
        currNode = 3
        levelNodes = [2, 3
        
                                1->n
                        2 ->n              3->n
                        
                4 ->n          5->n   6 ->n          7->n
        
        */
        /*
        while(!q.empty()){
            int sz = q.size(); // number of nodes in this level
            vector<Node*> levelNodes; // to store nodes in this level
            
            // traverse all nodes in this level
            for(int i = 0; i < sz; i++){
                // add the current node of this level to the array
                Node* node = q.front(); q.pop();
                levelNodes.push_back(node);
                
                // add both children to the queue, this will be the nodes of the next level
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }        
            
            for(int i = 0; i < sz-1; i++){
                levelNodes[i]->next = levelNodes[i+1];
            }
        }
            */

        // Solution without array, only using a prev. makes a lot of sense and is the same pattern as in
        // validate BST. using prev and a nullptr to mark a nonexisten val that will have a value eventually
        // Se podria lograr con memoria o(1) usando el nodo como linked list para ir conectando
        while(!q.empty()){
            int sz = q.size(); // number of nodes in this level
            Node* prev = nullptr;
            
            // traverse all nodes in this level
            for(int i = 0; i < sz; i++){
                // add the current node of this level to the array
                Node* node = q.front(); q.pop();
                
                if(prev) prev->next = node; // if theres a prev, connect it to the curr node
                
                prev = node; // set this node as prev
                
                // add both children to the queue, this will be the nodes of the next level
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }        
            
        }
        
        return root;
    }
}; // 19 minutes with example walkthrough
