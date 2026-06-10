/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), right(nullptr), left(nullptr){}
    TreeNode(int x): val(x), right(nullptr), left(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), right(left), left(right){}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        /*
        info
            input
                - root of a binary tree
            
            output
                - true if its a mirror of itself
            
            
            constraints
                - how many nodes can the tree have? [1, 1k]
                - ranges of values the tree values can have? [-100, 100]
            
            1 min 30 sec
            
        example
        
        Input: root = [1,2,2,3,4,4,3]
        Output: true
        
                        1
                2               2
            3       4       4       3
            
        Input: root = [1,2,2,null,3,null,3]
        Output: false
        
                    1
            2               2
        n       3       n       3
        
        brute force
            level by level traversal and for each level we'l have an array
            traverse with two pointers from both extremes inwards
            and if the values are different at any point, return false
            
            runtime: o(n)
            memory: o(log n)?
            
            its iterative, so we use the heap and not the stack
            
        optimize
            best conceivable runtime? o(n)
            
            can i do a recursive approach?
                I'm sure it's possible
                
                
        test
            - mirrored tree
            - not mirrored tree
            - tree with only one node
            
        38 min left out of 45
        
        
        Input: root = [1,2,2,3,4,4,3]
        Output: true
        
                        1
                2               2
            3       4       4       3            
            
            queue = [ 3 4 4 3
            sz 4
            level = [ 
            curr 
            i 0
            
        */
        /*
        queue<TreeNode*> q;
        
        // add root
        q.push(root);
        
        // while the queue is not empty
        while(!q.empty()){
            
            // get size, which is the number of nodes in this level
            int sz = q.size();
            
            // declare vector to store all the TreeNodes of this level
            vector<TreeNode*> level;
            
            // get all the nodes from this level
            for(int i = 0; i < sz; i++){
                // get the tree node
                TreeNode* curr = q.front(); q.pop();
                
                // add it to the level vector
                level.push_back(curr);
                
                // add the children to the queue, if we have a node
                if(curr->val != 101){
                    if(curr->left) q.push(curr->left);
                    else q.push(new TreeNode(101));

                    if(curr->right) q.push(curr->right);
                    else q.push(new TreeNode(101)); 
                }
            }
            
            for(int i = 0; i < sz/2; i++){
                if(level[i]->val != level[sz-1-i]->val) return false;
            }
        }
        
        return true;
        */
        
        return isMirror(root->left, root->right);
    }
    
    bool isMirror(TreeNode* left, TreeNode* right){
        // edge case: both are nullptr
        if(!left && !right) return true;
        
        // edge case: one is nullptr
        if(!left || !right) return false;
        
        // compare and call to check 
        return left->val == right->val 
            && isMirror(left->left, right->right) 
            && isMirror(left->right, right->left);
        
    }
}; // 17 min left, i know there must be a more elegant way to solve this, i thought i could use a nullptr instead of the 101 thing

/*
The recursive solution is so simple, but i doubted on even trying to do it.

That was my bad, i should try while on training to approach this type of problems with the best approach i can 
come up with
*/
