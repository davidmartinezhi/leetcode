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

 # include <iostream>
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
    int kthSmallest(TreeNode* root, int k) {
        /*
        info
            input
                - index of BST
                - k, representing k smallest value. 1-indexed
            
            todo
            
            
            output
                - kth smallest value
            
            
            constraints
                - range of num of nodes the BST can have? [1, 1k]
                - ranges of values the nodes can have? [0, 1k]
                - range of values that k can have? same as num of nodes in BST, always less or equal 
                    - can it exceed the size of the BST? no
                    
            4 min
            
        example
            root = [3,1,4,null,2], 
            k = 1        
            
                        3
                1               4
                    2
                    
            -> 1
            
        brute force
            do an inorder traversal, to get all the values in asc order
            start counting from the first val until we get to k
            
            runtime: o(n) worst case we traverse all nodes in the tree
            memory: o(height of tree)
            
        optimize
            best conceivable runtime: o(n)
            memory: can it be improved? iteratively we would use a stack, so it is the same
                - but to use heap memory would be preferable.
                for our constraints this should not be a concern
                
        test
            - k is 1 (start)
            - k is the biggest value in the list (end)
            - k is a value in between
        */
        
        int counter = 0;
        int result = 0;
        inorder(root, k, counter, result);
        return result;
    }
    
    /*
    k = 2
    counter= 2
    kSmallest = 2
                        3
                1               4
                    2    
    
    */
    bool inorder(TreeNode* node, int & k, int & counter, int & result){
        
        // base case: node is nullptr
        if(!node) return false;
        
        // traverse left
        if(inorder(node->left, k, counter, result)) return true; // already found
        
        // increment k
        counter++;
        if(counter == k){
            result = node->val;
            return true; // just found
        }
        
        return inorder(node->right, k, counter, result); // see if we find it
    }
}; // 17 min aprox. with example walkthrough. el walkthrough si fue util aqui para ver como se omvia la info y resolver unos bugs escondidos. siento que puede ser mas elegante la solucion con el regreso de info. pero estuvo muy entretenido aun asi

/*
No recordaba que podia regresar un valor y no atraparlo, muy util y si tira buen paro el regresar un boolean para
saber cuando es que ya se debe de regresar.
*/
