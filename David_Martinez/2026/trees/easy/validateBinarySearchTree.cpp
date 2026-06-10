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
    bool isValidBST(TreeNode* root) {
        /*
        36 min left
        
        info
            input
                - root of a binary tree
            
            output
                - bool if its a valid binary tree, else false
                
A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.
            
            constraints
                - ranges of sizes nodes the tree can have? [1, 10k]
                - ranges of values each node can have? int_min and int_max
                
        34 min left
        
        example
             root = [2,1,3]
                2
            1       3
             -> true
             
            root = [5,1,4,null,null,3,6]
                        5
                1               4
            n       n       3       6
            
        test
            - valid tree
            - left subtree contains node greater than the nodes key
            - right subtree contains node smaller than the nodes key
            
        brute force
        30 min left
        
            recursion
            
            i could do a bottom-up approach and for the left subtree return the biggest number
            we have seen
            
            and for the right subtree return the lesser number we have seen
            
            if any number for lest is greater then we return false
            if any number for right is lesser then we return false
            
            runtime: o(n)
            memory: o(n) stack
            
        optimize
            best conceivable runtime: o(n) we have to traverse all nodes in the tree
            
            i could do an inorder traversal and if the numbers are not sorted then it is false
            
            i know i have to do inorder, but i believe in my other solution as well
            
            ill do the inorder traversal after reviewing the concepts, ill go with my solution first
            
            22 min left
                        5
                1               4
            n       n       3       6   
            
            1
            18 min left, ill do inorder
            
        */
        
        /*
        int currMin = INT_MIN;
        bool first = true;
        
        return inorderComparison(first, currMin, root);
        */
        
        TreeNode* prev = nullptr;
        
        return inorder(prev, root);
        
    }

    bool validate(TreeNode* root, long minVal, long maxVal){
        
        if(!root) return true;
        
        // node has to be within range
        if (root->val <= minVal || root->val >= maxVal) return false;
        
        return validate(root->left, minVal, root->val) && validate(root->right, root->val, maxVal);
    }
    
    bool inorder(TreeNode* &prev, TreeNode* root){
        
        // edge case: root is nullptr
        if(!root) return true;
        
        // if left is false, return false
        if(!inorder(prev, root->left)) return false;
        
        // check current node
        if(prev && prev->val >= root->val) return false;
        
        // prev assigned
        prev = root;
        
        return inorder(prev, root->right);
        
    }
    
    bool inorderComparison(bool& first, int& currMin, TreeNode* root){
        
        // edge case: root is nullptr
        if(!root) return true;
        
        // check left child
        bool left = inorderComparison(first, currMin, root->left);
        
        // check if the value of the currMin is lesser than current node val
        if(currMin < root->val || first){
            currMin = root->val;
            first = false;
        }else{
            return false;
        }
        
        // check right child
        bool right = inorderComparison(first, currMin, root->right);
        
        return left && right;
        
    }
    
    
}; // 5 min left

/*
Almost 31 minutes

Complexity is accurate and both approaches that i came with were the most efficient


*/
