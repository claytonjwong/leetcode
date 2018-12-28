/*

 Q: https://leetcode.com/problems/longest-univalue-path/description/
 A: https://leetcode.com/problems/longest-univalue-path/discuss/128539/Simple-C++
 
 */

#include <iostream>

using namespace std;


struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int v) : val{v},left{nullptr},right{nullptr} {}
};

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans=0;
        if (root)
            go(root,ans);
        return ans;
    }
private:
    int go(TreeNode* node, int& ans){
        int L=node->left ? go(node->left,ans) : 0;
        int R=node->right ? go(node->right,ans) : 0;
        L=(node->left && node->left->val == node->val) ? L+1 : 0;
        R=(node->right && node->right->val == node->val) ? R+1 : 0;
        ans=max(ans,L+R);
        return max(L,R);
    }
};

/*
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int lup = 0;
        if (root) dfs(root, lup);
        return lup;
    }
    
private:
    int dfs(TreeNode* node, int& lup) {
        int l = node->left ? dfs(node->left, lup) : 0;
        int r = node->right ? dfs(node->right, lup) : 0;
        int resl = node->left && node->left->val == node->val ? l + 1 : 0;
        int resr = node->right && node->right->val == node->val ? r + 1 : 0;
        lup = max(lup, resl + resr);
        return max(resl, resr);
    }
};
*/

int main(int argc, const char * argv[]) {
    
    TreeNode* root=new TreeNode(5); //new TreeNode(1);
    root->left=new TreeNode(4);
    root->left->left=new TreeNode(1);
    root->left->right=new TreeNode(1);
    root->right=new TreeNode(5);
    root->right->right=new TreeNode(5);
    
    
    
    Solution s;
    cout << s.longestUnivaluePath(root) << endl;;
    
    return 0;
}


