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

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
 };

class Solution {
public:
    int maxDepth(TreeNode* root) {
        /*
        info
            input
                - root of binary tree
            
            
            output
                - max depth
            
            
            constraints
                - range of nodes the binary tree can have? [0, 10k]
                
        example
            [3,9,20,null,null,15,7]
            
                    3
                9       20
                
                     15      7
                    n.  n.  n.  n.   
            -> 3
            
        brute force
            traverse recursively until we reach the bottom
            then count+1 all the way up and stay with whichever value is greater
            
            runtime: o(n)
            memory: o(n) we are using stack memory
            
        optimize
            i could use a stack but still we would have memory o(n)
            
        4 minute mark
        
        test
        
            - head is nullptr
            - all nodes are left child nodes
                - same with right
                
            - branches have different sizes
                        
        */
        
        // edge case: root is a nullptr
        if(!root) return 0;
        
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        
        
    }
}; // 9 min
