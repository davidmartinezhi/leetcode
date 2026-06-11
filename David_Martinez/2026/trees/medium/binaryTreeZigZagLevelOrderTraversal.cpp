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

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        /*
        info
        
            input
                - root of binary tree
            
            
            output
                - zigzag level order traversal of nodes
                - return array with subarrays containing the values of the levels (zig zag order)
            
            
            constraints
                - ranges of number of nodes a tree can have? [0, 2k]
                - ranges of values a node val can have? [-100, 100]
                
        example
            Input: root = [3,9,20,null,null,15,7]
            Output: [[3],[20,9],[15,7]]       
            [3]
                        3
                9               20
            n       n       15      7
            
        brute force
            level by level traversal (BFS) on a binary tree usiing a queue
            
        
        walkthrough
            add root to que
            while queue not empty
                get curr size of queue
                declare an array
                traverse from 0 to size
                    get node on queue
                    add value to declared array
                    if left child, add it to queue
                    if right child, add it to queue
                add declared array to result array
                have a counter to determine if we flip the array before adding it
                
            runtime: o(n) we traverse each node of the tree
            memory: o(widest level, log n?)
            
        optimize
            best conceivable runtime: o(n)
            
        test
            - root is nullptr
            - one node
            - multiple nodes
            
            36 min left, out of 45
        */        
        
        // Edge case: root is nullptr
        if(!root) return {};
        
        // Declare variables
        queue<TreeNode*> q;
        vector<vector<int>> levelByLevel;
        int levelNum = 0;
        
        // add root to queue
        q.push(root);
        
        /*
            [3] [20, 9]
            q =  15 7
            curr = 20
            1
            levelNum = 1
                        3
                9               20
            n       n       15      7        
        
        */
        
        while(!q.empty()){
            
            int sz = q.size(); // num of nodes in current level
            vector<int> level; // to store nodes in this level
            
            for(int i = 0; i < sz; i++){
                
                // get curr node
                TreeNode* node = q.front(); q.pop();
                
                // add value to level vector
                level.push_back(node->val);
                
                // add to next level the children
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            // if odd number, reverse level values
            if(levelNum%2 != 0) reverse(level.begin(), level.end());
            
            // add level traversal to level by level and increase level number
            levelByLevel.push_back(level);
            levelNum++;
        }
        
        return levelByLevel;
    } // 24 min left with example. example takes the most amount of time. 21 min left, forgot to add root to queue and was wondering why i had an emoty array returned
};
