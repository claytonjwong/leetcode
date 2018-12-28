/*
 
 652. Find Duplicate Subtrees
 
 https://leetcode.com/contest/leetcode-weekly-contest-43/problems/find-duplicate-subtrees/
 
 Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.
 
 Two trees are duplicate if they have the same structure with same node values.
 
 Example 1:
 1
 / \
 2   3
 /   / \
 4   2   4
 /
 4
 The following are two duplicate subtrees:
 2
 /
 4
 and
 4
 Therefore, you need to return above trees' root in the form of a list.
 
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /*
     find all subtrees and add them into the hash,
     where there is a hash collision (i.e. two or more of the same subtree)
     add them onto the return vector
     */
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,vector<TreeNode*>> umap;
        denormalize(root, umap);
        vector<TreeNode*> result;
        typedef typename unordered_map<string,vector<TreeNode*>>::iterator hash_itr;
        for (hash_itr itr=umap.begin(); itr != umap.end(); itr++){
            
//            cout << "Key : " << itr->first << endl;
//            cout << "Value : ";
//            for (auto treenode : itr->second ){
//                cout << treenode << endl;
//            }
//            
            if ((itr->second).size() > 1){
                result.push_back(itr->second[0]);
            }
        }
        return result;
    }
    
private:

    /*
     go through each sub-tree in post-order traversal,
     create a string key from [left/right recursion + current node value]
     return the string key for this recusion and update the hash ref to an unordered map
     */
    string denormalize(TreeNode* root, unordered_map<string,vector<TreeNode*>>& umap){
        if (!root) return "NULL";
        string key = "(left=" +
            denormalize(root->left, umap) + ",right=" +
            denormalize(root->right, umap) + ",root=" +
            to_string(root->val) + ")";
        umap[key].push_back(root);
        return key;
    }
    
};

int main(int argc, const char * argv[]) {
    
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(0);
    root->left->left = new TreeNode(0);
    root->right = new TreeNode(0);
    root->right->right = new TreeNode(0);
    root->right->right->right = new TreeNode(0);
    
    Solution solution;
    vector<TreeNode*> result = solution.findDuplicateSubtrees(root);
    
    
    return 0;
}





