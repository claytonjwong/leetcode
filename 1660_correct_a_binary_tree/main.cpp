/*
 * 1660. Correct a Binary Tree
 *
 * Q: https://leetcode.com/problems/correct-a-binary-tree/
 * A: https://leetcode.com/problems/correct-a-binary-tree/discuss/943193/Kt-Js-Py3-Cpp-Map-%2B-Seen-solutions
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

namespace Map {
    class Solution {
    public:
        using Map = unordered_map<TreeNode*, TreeNode*>;
        using fun = function<TreeNode*(TreeNode*)>;
        TreeNode* correctBinaryTree(TreeNode* root, Map m = {}, bool found = false) {
            fun go = [&](auto root) {
                if (m.find(root) != m.end()) {
                    auto target = m[root],
                         parent = m[target];
                    if (parent->left  == target) parent->left  = nullptr;
                    if (parent->right == target) parent->right = nullptr;
                    found = true;
                }
                if (!found && root->left)  go(root->left),  m[root->left]  = root;
                if (!found && root->right) go(root->right), m[root->right] = root;
                return root;
            };
            return go(root);
        }
    };
}
namespace Seen {
    class Solution {
    public:
        using Seen = unordered_set<TreeNode*>;
        using fun = function<TreeNode*(TreeNode*)>;
        TreeNode* correctBinaryTree(TreeNode* root, Seen seen = {}, bool found = false) {
            fun go = [&](auto root) -> TreeNode* {
                seen.insert(root);
                if (root->right && seen.find(root->right) != seen.end()) {
                    found = true;
                    return nullptr;
                }
                if (!found && root->right) root->right = go(root->right);
                if (!found && root->left)  root->left  = go(root->left);
                return root;
            };
            return go(root);
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
