/*
 
 572. Subtree of Another Tree
 
 Q: https://leetcode.com/problems/subtree-of-another-tree/description/
 A: https://leetcode.com/problems/subtree-of-another-tree/discuss/130364/C++-to_string
 
 */


#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left,*right;
    TreeNode(int v) : val{v},left{nullptr},right{nullptr} {}
};

class Solution {
public:
    bool isSubtree(TreeNode* a, TreeNode* b) {
        return go(a).find(go(b))!=string::npos;
    }
private:
    string go(TreeNode* x) const {
        return x ? "["+to_string(x->val)+",L=("+go(x->left)+"),R=("+go(x->right)+")]" : "N";
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    TreeNode* root=new TreeNode(3);
    root->right=new TreeNode(5);
    root->left=new TreeNode(4);
    root->left->left=new TreeNode(2);
    root->left->right=new TreeNode(1);
    
    TreeNode* target=new TreeNode(4);
    target->left=new TreeNode(2);
    target->right=new TreeNode(1);
    target->right->left=new TreeNode(0);
    
    cout << s.isSubtree(root, target) << endl;
    
    
    return 0;
}


