/*

 Q: https://leetcode.com/problems/two-sum-bsts/
 A: https://leetcode.com/problems/two-sum-bsts/discuss/401394/Javascript-and-C%2B%2B-Solutions

 */

#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val_) : val{val_}, left{nullptr}, right{nullptr} {}
};

/*
class Solution {
public:
    bool twoSumBSTs(TreeNode* A, TreeNode* B, int t) {
        return go(A, B, t);
    }
private:
    bool go(TreeNode* A, TreeNode* B, int t) {
        if (!A)
            return false;
        return binary_search(B, t - A->val) || go(A->left, B, t) || go(A->right, B, t);
    }
    bool binary_search(TreeNode* root, int t) {
        return !root ? false
             : root->val == t ? true
             : root->val >  t ? binary_search(root->left,  t)
                              : binary_search(root->right, t);
    }
};
*/

class Solution {
public:
    using Seen = unordered_set<int>;
    bool twoSumBSTs(TreeNode* A, TreeNode* B, int t, Seen seen={}) {
        if (!A || !B)
            return false;
        for (queue<TreeNode*> q{{B}}; !q.empty(); q.pop()) {
            auto cur = q.front();
            seen.insert(cur->val);
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        for (queue<TreeNode*> q{{A}}; !q.empty(); q.pop()) {
            auto cur = q.front();
            if (seen.find(t - cur->val) != seen.end())
                return true;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        return false;
    }
};

int main() {
    TreeNode* A = new TreeNode(0);
    A->left = new TreeNode(-10);
    A->right = new TreeNode(10);
    TreeNode* B = new TreeNode(5);
    B->left = new TreeNode(1);
    B->right = new TreeNode(7);
    cout << Solution().twoSumBSTs(A, B, 17) << endl;
    return 0;
}