/*
 
 652. Find Duplicate Subtrees
 
 https://leetcode.com/problems/find-duplicate-subtrees/description/
 
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
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val{val}, left{NULL}, right{NULL} {}
};


class Solution{
public:
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        vector<TreeNode*> res;
        if (!root) { return res; }
        
        unordered_map<string,vector<TreeNode*>> map{};
        serialize(root->left, map);
        serialize(root->right, map);
        
        typedef typename unordered_map<string,vector<TreeNode*>>::iterator map_itr;
        for (map_itr itr=map.begin(); itr != map.end(); itr++){
            if (itr->second.size() >= 2){
                res.push_back(itr->second[0]);
            }
        }
        return res;
    }
    
private:
    
    string serialize(TreeNode* node, unordered_map<string,vector<TreeNode*>>& m){
        
        if (!node) { return "null"; }
        
        string key =
            "(root=" + to_string(node->val) +
            ",left=" + serialize(node->left, m) +
            ",right=" + serialize(node->right, m) + ")";
        m[key].push_back(node);
        return key;
    }
};


int main(int argc, const char * argv[]) {

    TreeNode* test = new TreeNode(1);
    test->left = new TreeNode(2);
    test->left->right = new TreeNode(0);
    test->right = new TreeNode(2);
    test->right->right = new TreeNode(0);
    
    Solution solution;
    vector<TreeNode*> result = solution.findDuplicateSubtrees(test);
    
    return 0;
}








