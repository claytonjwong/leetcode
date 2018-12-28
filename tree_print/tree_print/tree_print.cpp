/*

 655. Print Binary Tree
 
 https://leetcode.com/problems/print-binary-tree/description/
 
 
 Print a binary tree in an m*n 2D string array following these rules:
 
 The row number m should be equal to the height of the given binary tree.
 The column number n should always be an odd number.
 The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
 Each unused space should contain an empty string "".
 Print the subtrees following the same rules.
 Example 1:
 Input:
 1
 /
 2
 Output:
 [["", "1", ""],
 ["2", "", ""]]
 
 
 d = 1
 
 w = 2^(d+1) - 1
 
 Example 2:
 Input:
 1
 / \
 2   3
 \
 4
 Output:
 [["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
 
 d = 2
 
 w = 2^(d+1) - 1
 
 
 Example 3:
 Input:
 1
 / \
 2   5
 /
 3
 /
 4
 Output:
 
 [["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
 Note: The height of binary tree is in the range of [1, 10].
 
 d = 3
 
 w = 2^(d+1) - 1
 
 */


#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val{val}, left{NULL}, right{NULL} {}
};

class Solution{
public:
    vector<vector<string>> printTree(TreeNode* root){
        
        vector<vector<string>> res;
        
        //
        // create table of empty strings ""
        // based on the tree height/width
        //
        int depth = maxDepth(root);
        int width = pow(2, depth+1) - 1;
        vector<string> row (width, "");
        for (int i=0; i <= depth; i++){
            res.push_back(row);
        }
        
        //
        // traverse the tree and fill in table values for non-NULL nodes
        //
        fillTable(root, 0, 0, width-1, res);
        return res;
    }
    
private:
    int maxDepth(TreeNode* node){
        if (!node) { return -1; }
        
        int leftDepth = -1;
        if (node->left) { leftDepth = maxDepth(node->left); }
        
        int rightDepth = -1;
        if (node->right) { rightDepth = maxDepth(node->right); }
        
        return 1 + max( leftDepth, rightDepth );
    }
    
    void fillTable(TreeNode* node, int depth, int start, int end, vector<vector<string>>& table){
        if (!node) { return; }
        
        int mid = (int)(start+end)/2;
        table[depth][mid] = to_string(node->val);
        
        if (node->left)  { fillTable(node->left,  depth+1, start, mid-1, table); }
        if (node->right) { fillTable(node->right, depth+1, mid+1, end,   table); }
    }
};


int main(int argc, const char * argv[]) {

    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->left->right->left = new TreeNode(4);
    
    Solution solution;
    vector<vector<string>> result = solution.printTree(root);
    
    for (auto row : result){
        cout << "[";
        for (auto col : row){
            cout << col << ",";
        }
        cout << "]" << endl;
    }
    
    return 0;
}












