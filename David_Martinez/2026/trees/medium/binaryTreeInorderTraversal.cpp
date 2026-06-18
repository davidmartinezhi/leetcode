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
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        /*
        info
        21 min left
            input
                - root of binary tree
            
            output
                - inorder traversal of its nodes values
            
            
            constraints
                - range of sizes it can have? [0, 100]
                - range of values each node can have? [-100, 100]
                
        walkthrough
            runtime: o(n) we are traversing all nodes
            memory: o(n) if all nodes are only left children or only right children
            
        test
            - root is null
            - root is not null
        
        17 min left
        */
        
        // Edge case: root is nullptr
        if(!root) return {};
        
        // Vector to store all values
        vector<int> inorderTraversal;
        
        /*
        recursive traversal
        fillInorderTraversal(inorderTraversal, root);
        */
        /*
        result = [ 1, 2, 3, 4, 5
        stack = [  
        root= n
                        3
                    1       4
                        2       5
        */
        
        // iterative traversal
        stack<TreeNode*> stack;
        
        while(!stack.empty() || root){
            
            // while root is not a nullptr
            while(root){
                //add the corrent node, which we will travers in a future, to the stack
                stack.push(root);
                
                // move to the left
                root = root->left;
            }
            
            // if we are out, it means we are at the limit
            // get the node out
            root = stack.top(); stack.pop();
            inorderTraversal.push_back(root->val);
            
            // set root to be the right child
            root = root->right;
        }
        
        return inorderTraversal;
    }
    
    /*
        v= 2 1 3
            
            1
            
        2       3
    
    
    */
    
    void fillInorderTraversal(vector<int> & v, TreeNode* node){
        // Base case: node is a nullptr
        if(!node) return;
        
        // If we have a valid node 
        // Call function on left child
        fillInorderTraversal(v, node->left);
        
        // Add current node to the vector
        v.push_back(node->val);
        
        // Call function on right child
        fillInorderTraversal(v, node->right);
    }
    // 12 min left, just finished writing everything, ill do the example
    
}; // 8 min 20 sec left. passed all and did example. maybe i should try to do this iteratively just to practice
