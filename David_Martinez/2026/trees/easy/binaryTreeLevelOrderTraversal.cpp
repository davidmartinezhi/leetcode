 #include <iostream>
 #include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        /*
        15 min left
        
        info
            input
                - root
                
            output
                - level order traversal
                
            constraints
                - range of sizes the tree can have? [0, 2k]
                - range of values it can have? [-1k, 1k]
                
        example
            Input: root = [3,9,20,null,null,15,7]
            Output: [[3],[9,20],[15,7]]     
            
        walkthrough
            use a queue 
            while not empty
            get size, those are the nodes in that level
            for each node
                add to a level vector
                add to queue the children
            
            runtime: o(n) we traverse all nodes
            memory: o(widest level) log n?
        
        test
            - tree of size 0
            - one level
            - more than one level
            
            
            root = [3,9,20,null,null,15,7]
            Output: [[3],[9,20],[15,7]]   
            
                            3
                            
                    9               20
                n       n       15      7
                
                q = 15 7
                lev_by_lev = [[3],[9, 20]]
                level = 9 20
                curr = 20
        
        */
        
        if(!root) return {};
        
        vector<vector<int>> level_by_level;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int sz = q.size();
            vector<int> level;
            
            for(int i = 0; i < sz; i++){
                TreeNode* curr = q.front(); q.pop();
                level.push_back(curr->val);
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            level_by_level.push_back(level);
        }
        
        return level_by_level;   
    }
};// 3 min left, it really helped that the prev problem i did it with this same level by level approach
