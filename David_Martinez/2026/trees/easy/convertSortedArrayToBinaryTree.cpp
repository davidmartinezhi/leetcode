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
 
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        /*
        info
            input
                - int array nums, elements sorted in ascending order
                
            todo
                - convert array to height balanced binary search tree
            
            
            output
                - root node of BST
            
            
            constraints
                - how many nodes can the tree have? ranges [1, 10k]
                - range of values that each node value can have [-10k, 10k]
                - sorted strictly in an ascending order
        
        2 min 30 sec
        example
            5/2 = 2.5= 2
            node = 0
            node 0 left child is this function starting from the new values
            same for right side but diff indexes
            
            Input: nums = [-10,-3,0,5,9]
            Output: [0,-3,9,-10,null,5]    
            
                        0
                    -3      9
                    
            ist a binary search pattern
            
        brute force
            do a binary search-esque traversal
            each middle value gets turned into a node and connected to the parent
            
            runtime: o(n) we have to traverse evey num in the array
            memory: o(log n) for tree height in stack if we use recursion
            
        optimize
            best conceivable runtime: o(n)
            
            the approach is optimal.
            
        test
            - odd size array
            - even size array
            38 min and 20 seconds left from original 45 left   
        */
        
        int start = 0;
        int end = nums.size()-1;
        
        return buildBST(nums, start, end);
    }
    
    /*
                         e
                   s
                     m
                   
                   s.  e   
    nums = [-10,-3,0,5,9]
             0   1 2 3 4
             
             0
             
        -10
        
    n         -3  
    */
    TreeNode* buildBST(vector<int>& nums, int start, int end){
        
        if(start <= end){
            
            // get index of mid
            int m = start + (end-start)/2;
            
            // create node with that value
            TreeNode* curr = new TreeNode(nums[m]);
            
            //set childs to recursion
            curr->left = buildBST(nums, start, m-1);
            curr->right = buildBST(nums, m+1, end);
            
            return curr;
        }
        
        return nullptr;
        
    }
    // finished writing the algorithm with 28 30 mins left and im checking the logic on an example
}; // 21 min left, accepted
