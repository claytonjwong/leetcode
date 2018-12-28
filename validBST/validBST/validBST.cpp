/*
 
 98. Validate Binary Search Tree
 
 https://leetcode.com/problems/validate-binary-search-tree/description/
 
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left,*right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        vector<int> v;
        go(root,v);
        set<int> s(v.begin(),v.end());
        return is_sorted(v.begin(),v.end()) && s.size()==v.size();
    }
private:
    void go(TreeNode* root,vector<int>& inorder){
        if (!root) return;
        go(root->left,inorder);
        inorder.push_back(root->val);
        go(root->right,inorder);
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    cout << s.isValidBST(nullptr) << endl;
    
    return 0;
}
