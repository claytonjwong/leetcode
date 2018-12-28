/*
 
 230. Kth Smallest Element in a BST
 
 https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 
 Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 
 Note:
 You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 
 Follow up:
 What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 
 */

#include <iostream>

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res=0;
        go(res,root,k);
        return res;
    }
private:
    void go(int& res, TreeNode* node,int& k){
        if (res || !node) return;
        go(res,node->left,k);
        if (--k==0) res=node->val;
        go(res,node->right,k);
    }
};

using namespace std;

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    int k=3;
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(5);
    root->right=new TreeNode(15);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(7);
    
    
    cout << s.kthSmallest(root, k) << endl;
    
    return 0;
}



