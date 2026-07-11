/*
27 min left
info
    operations:
        - serialize
            serialize a binary tree into a string
            
        - deserialize
            deserialize the string to a binary tree
            
    constraints
        - num of nodes the tree can have? [0, 10k]
        - range of values that each node value can have? [-1k, 1k]
        
    22 min left
    
    walkthrough
        - a binary tree can be copied with preorder traversal.
        - i could do a preorder traversal, get the values in the tree in preorder order
            and whenever we hit nullptr add a char 'n' indicating null.
            
        - i could also do a level by level order traversal, and construct based on each level
        
            1
        3       2
    n     n    n  n
    
    "1|3,4|2,n,n,n"
            1
        3       4

            1
        3       
    2     n    
    
    "1|3|2,n"
    
    yeah, for every node in one level, i take from a fixed sized window of 2 from the other level
    and that gives me for the father, both children.


*/

#include <iostream>
#include <string>
#include <sstream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        /*
        vector<string> strs;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty() || root){
            
            int n = q.size(); // number of nodes in this level
            string level = "";
            
            // traverse nodes in this level
            for(int i = 0; i < n; i++){
                TreeNode* curr = q.front(); q.pop();
                
                if(!curr){
                    level += "n";
                }else{
                    level += to_string(curr->val);
                }
                if(curr){
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
            strs.push_back(level);
        }
        
        string result = "";
        for(string str : strs){
            result += str;
            result += "|";
        }
        
        return result;
        */
        
        if(!root) return "n,"; // if nullptr, return n
        
        return to_string(root->val) + "," 
            + serialize(root->left) 
            + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        /*TreeNode* result;
        vector<string> levels;
        
        stringstream ss(data);
        string item;
        
        while(getline(ss, item, '|')){
            levels.push_back(item);
        }
        
        // now we traverse
        for(string s : levels){
            // time is over
        }
        */
        
        queue<string> nodes; // queue to store values in a first in first out manner
        stringstream ss(data); // 
        string item;
        
        while(getline(ss, item, ',')){
            nodes.push(item);
        }
        
        return build(nodes);
    }
    
    TreeNode* build(queue<string>& nodes){
        string val = nodes.front(); nodes.pop();
        
        if(val == "n") return nullptr; // return nullptr
        
        TreeNode* node = new TreeNode(stoi(val)); // create node
        node->left = build(nodes); // set left node
        node->right = build(nodes); // set right node
        
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
