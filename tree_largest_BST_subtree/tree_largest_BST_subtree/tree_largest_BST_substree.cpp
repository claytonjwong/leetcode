/*
 
 333. Largest BST Subtree
 
 Q: https://leetcode.com/problems/largest-bst-subtree/description/
 
 A: https://leetcode.com/problems/largest-bst-subtree/discuss/125509/Concise-C++-with-explanation-(-EASY-to-understand-)
 
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left,*right;
    TreeNode(int val) : val{val},left{nullptr},right{nullptr} {}
};

struct X {
    bool isBST; int minv,maxv,size;
    X(bool isBST,int minv,int maxv,int size) : isBST{isBST},minv{minv},maxv{maxv},size{size} {}
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        return root ? go(root).size : 0;
    }
private:
    X go(TreeNode* i){
        X L=i->left ? go(i->left) : X(true,INT_MAX,INT_MIN,0),R=i->right ? go(i->right) : X(true,INT_MAX,INT_MIN,0);
        if (L.isBST && R.isBST && L.maxv < i->val && i->val < R.minv)
            return X(true,min({L.minv,i->val,R.minv}),max({L.maxv,i->val,R.maxv}),L.size + 1 + R.size);
        return X(false,0xDEAD,0xBEEF,max(L.size,R.size));
    }
};

int main(int argc, const char * argv[]) {
    
    /*
        10
       / \
      5   15
     / \   \
    1   8   7
     */
    Solution s;
    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(5);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(8);
    root->right=new TreeNode(15);
    root->right->right=new TreeNode(7);
    
    cout << s.largestBSTSubtree(root) << endl;
    
    
    return 0;
}


