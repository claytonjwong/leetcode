/*
 * 1602. Find Nearest Right Node in Binary Tree
 *
 * Q: https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/
 * A: https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/discuss/875464/Javascript-Python3-C%2B%2B-BFS-solutions
 */

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

class Solution {
public:
    using Queue = queue<TreeNode*>;
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* T) {
        Queue q{{{ root }}};
        while (q.size()) {
            Queue next;
            while (q.size()) {
                auto node = q.front(); q.pop();
                if (node == T)
                    return q.size() ? q.front() : nullptr;
                if (node->left)  next.push(node->left);
                if (node->right) next.push(node->right);
            }
            q.swap(next);
        }
        return nullptr;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
