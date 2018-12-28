/*
 
 298. Binary Tree Longest Consecutive Sequence
 
 Q: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/description/
 A: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/discuss/153880/C++-simple-solution-with-explanation
 
 */



#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left,*right;
    TreeNode(int x) : val{x},left{nullptr},right{nullptr} {}
};

/*
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        int ans=0;
        if (root)
            traverse(root,ans);
        return ans;
    }
private:
    void traverse(TreeNode* root, int& ans){
        go(root,ans);
        if (root->left) traverse(root->left,ans);
        if (root->right) traverse(root->right,ans);
    }
    void go(TreeNode* root, int& ans, int&& len=1){
        ans=max(ans,len);
        if (root->left && 1+root->val==root->left->val) go(root->left,ans,len+1);
        if (root->right && 1+root->val==root->right->val) go(root->right,ans,len+1);
    }
};
*/


class Solution {
public:
    int longestConsecutive(TreeNode* root, int ans=0) {
        if (root) go(root,ans);
        return ans;
    }
private:
    void go(TreeNode* root, int& ans, int&& len=1){
        ans=max(ans,len);
        if (root->left) go(root->left,ans,root->left->val==root->val+1 ? len+1 : 1);
        if (root->right) go(root->right,ans,root->right->val==root->val+1 ? len+1 : 1);
    }
};


int main(int argc, const char * argv[]) {
    
    Solution s;
    
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(3);
    cout << s.longestConsecutive(root) << endl;
    
    return 0;
}
