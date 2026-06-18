#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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
    vector<int> preorderTraversal(TreeNode* root) {
        /*
        12 minutes to implement it iterative
        input 
            root bianry tree

        output
            vector with preorder traveersal of its nodes values

        contraints
            range of sizes the tree can have? [0,100]
            range of values a noede can have? [-100, 100]


                1

            2       3

            root = 3
            stack = [
            res = 1, 2, 3

            add root 

            while root or stack not empty

            while node
                add to result val
                add to stack the node
                node is node->left now

            get the node from stack
            set the node as the right value of that node
        
        */

        if(!root) return {};

        stack<TreeNode*> s;
        vector<int> result;

        while(root || !s.empty()){
            while(root){
                result.push_back(root->val);
                s.push(root);
                root = root->left;
            }

            root = s.top(); s.pop();
            root = root->right;
        }

        return result;
    }
}; // 3 min left
