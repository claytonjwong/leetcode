/*
 
 270. Closest Binary Search Tree Value
 
 Q: https://leetcode.com/problems/closest-binary-search-tree-value/description/
 A: https://leetcode.com/problems/closest-binary-search-tree-value/discuss/144652/Straightforward-C++-(-EASY-to-understand-)-with-explanation
 
 */

#include <iostream>
#include <cmath>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left,*right;
    TreeNode(int x) : val{x},left{nullptr},right{nullptr} {}
};

class Solution {
public:
    int closestValue(TreeNode* root, double target, int ans=0) {
        if (root==nullptr) return 0;
        go(root,target,abs(target-root->val),ans=root->val);
        return ans;
    }
private:
    void go(TreeNode* root, const double& T, double&& D, int& ans){
        if (abs(T-root->val) < D){
            ans=root->val;
            D=abs(T-ans);
        }
        if (root->left) go(root->left,T,std::move(D),ans);
        if (root->right) go(root->right,T,std::move(D),ans);
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    TreeNode* root=new TreeNode(1);
    root->right=new TreeNode(2);
    cout << s.closestValue(root, 3.714286) << endl;
    
    return 0;
}
