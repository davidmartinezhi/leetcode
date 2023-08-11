#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    //atttribute
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r): val(x), left(l), right(r) {}

}

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        /*
            info
                input:  root
                output: string of serialized binary tree
                constraints:    
                    - # of nodes [0, 10000]
                    - node vales in range [-1000, 1000]
            
            example
                root = [1,2,3,null,null,4,5]

                            1
                    2               3
                                4       5

                    preorder traversal: copy bst

            brute force
                    preorder traversal
                    add to string value as character, if we are at a nullptr, we add 'n'

            optimize
                best conceivable runtime: O(n)
                
            test
                tree with just root
                tree with just root and left child
                tree of just root and right child
                tree with both childs
                


        */

        string serializedTree = "";

        //iterative preorder traversal
        stack<TreeNode*> stack;

        /*
                    1
                2       3
                            4

            stack = [
            currentNode = 
            root = 4
        */

        while(!stack.empty() || root != nullptr){
            while(root != nullptr){
                
                //serialize and add to resulting string 10
                
                
                serializedTree += to_string(root->val);
                serializedTree += '.';


                stack.push(root);
                root = root->left;


            }
            serializedTree += "n.";

            root = stack.top();
            stack.pop();

            root = root->right;
        }
        cout << serializedTree << endl;
        return serializedTree;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        /*
            [x,2,3,n,4,4,5]
        */
        if(data.size() == 0) return nullptr;

        //set array of pointers
        vector<TreeNode*> nodes;
        
        for(int i = 0; i < data.size(); i++){
            int number = 0;

            bool negative = false;

            if(data[i] == '-'){
                negative = true;
                i++;
            }

            if(data[i] == 'n'){
                nodes.push_back(nullptr);
            } 
            else if (isdigit(data[i])){

                while(data[i] != '.'){
                    number = (number * 10) + (data[i] - '0');
                    i++;
                }
                if(negative) number *= -1;
                nodes.push_back(new TreeNode(number));
            }

        }

        int i = 0;
        deserializeHelper(nodes, nodes[i], i);

        return nodes[0];

    }


    TreeNode* deserializeHelper(vector<TreeNode*> & nodes, TreeNode* currNode, int & i){
        
        //base case return
        if(i >= nodes.size() || !currNode) return nullptr;

        TreeNode* aux;

        i++;
        if(i >= nodes.size() || !currNode) aux = nullptr;
        else aux = nodes[i];
        currNode->left = deserializeHelper(nodes, aux, i);

        i++;
        if(i >= nodes.size() || !currNode) aux = nullptr;
        else aux = nodes[i];
        currNode->right = deserializeHelper(nodes, aux, i);

        return currNode;

    }
};