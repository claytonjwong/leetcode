/*
 * 958. Check Completeness of a Binary Tree
 *
 * Q: https://leetcode.com/problems/check-completeness-of-a-binary-tree/
 * A: https://leetcode.com/problems/check-completeness-of-a-binary-tree/discuss/543844/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <queue>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

namespace Verbose {
    class Solution {
    public:
        bool isCompleteTree(TreeNode* root) {
            queue<TreeNode*> q{{root}};
            while (!q.empty()) {
                auto cur = q.front(); q.pop();
                for (; !cur && !q.empty(); q.pop())
                    if (q.front())
                        return false;
                if (cur) q.push(cur->left), q.push(cur->right);
            }
            return true;
        }
    };
}

namespace Concise {
    class Solution {
    public:
        bool isCompleteTree(TreeNode* root) {
            deque<TreeNode*> q{{root}};
            for (;;) {
                auto cur = q.front(); q.pop_front();
                if (!cur) return all_of(q.begin(), q.end(), [](auto next) { return !next; });
                q.push_back(cur->left), q.push_back(cur->right);
            }
        }
    };
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
