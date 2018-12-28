/*
 
 250. Count Univalue Subtrees
 
 https://leetcode.com/problems/count-univalue-subtrees/description/
 
 Given a binary tree, count the number of uni-value subtrees.
 
 A Uni-value subtree means all nodes of the subtree have the same value.
 
 For example:
 Given binary tree,
    5
   / \
  1   5
 / \   \
5   5   5
 return 4.
 
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left,*right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};


 // AC
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) return 0;
        int cnt=0;
        go(cnt,root);
        return cnt;
    }
private:
    int go(int& res, TreeNode* node){
        int l=(node->left) ? go(res,node->left) : INT_MAX;
        int r=(node->right) ? go(res,node->right) : INT_MAX;
        if (l==INT_MAX) l=r;
        if (r==INT_MAX) r=l;
        if (l==r && (l==node->val || l==INT_MAX)){
            ++res;
            return node->val;
        }
        return INT_MIN;
    }
};

/*
 //AC
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int cnt=0;
        go(cnt,root);
        return cnt;
    }
private:
    bool go(int& res, TreeNode* node){
        if (!node) return true;
        bool l=go(res,node->left);
        bool r=go(res,node->right);
        if (l && r){
            bool unival=true;
            if (node->left && node->left->val!=node->val) unival=false;
            if (node->right && node->right->val!=node->val) unival=false;
            if (unival) ++res;
            return unival;
        }
        return false;
    }
};
*/


int main(int argc, const char * argv[]) {
    
    
    Solution s;
    TreeNode* root=new TreeNode(5);
    root->left=new TreeNode(1);
    root->right=new TreeNode(5);
    root->left->left=new TreeNode(5);
    root->left->right=new TreeNode(5);
    root->right->right=new TreeNode(5);
    
    cout << s.countUnivalSubtrees(root) << endl;
    
    
    return 0;
}



