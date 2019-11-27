/*
 * 1261. Find Elements in a Contaminated Binary Tree
 *
 * Q: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/
 * A: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/discuss/433166/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_set>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 *
 */

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val_) : val{val_}, left{nullptr}, right{nullptr} {}
};

class FindElements {
public:
    FindElements(TreeNode* root) {
        go(root);
    }

    bool find(int target) {
        return seen.find(target) != seen.end();
    }
private:
    unordered_set<int> seen;
    void go(TreeNode* root, int val=0) {
        seen.insert(val);
        root->val = val;
        if (root->left) go(root->left, 2*val+1);
        if (root->right) go(root->right, 2*val+2);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
