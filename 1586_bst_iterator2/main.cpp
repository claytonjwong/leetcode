/*
 * 1586. Binary Search Tree Iterator II
 *
 * Q: https://leetcode.com/problems/binary-search-tree-iterator-ii/
 * A: https://leetcode.com/problems/binary-search-tree-iterator-ii/discuss/852792/Javascript-Python3-C%2B%2B-Naive-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

class BSTIterator {
    vector<int> A;
    int i;
public:
    using fun = function<void(TreeNode*)>;
    BSTIterator(TreeNode* root) : i{ -1 } {
        fun go = [&](TreeNode* root) {
            if (!root)
                return;
            go(root->left);
            A.push_back(root->val);
            go(root->right);
        };
        go(root);
    }
    bool hasNext() {
        return i + 1 < A.size();
    }
    int next() {
        return A[++i];
    }
    bool hasPrev() {
        return 0 < i;
    }

    int prev() {
        return A[--i];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
