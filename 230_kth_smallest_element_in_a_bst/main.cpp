/*
 * 230. Kth Smallest Element in a BST
 *
 * Q: https://leetcode.com/problems/kth-smallest-element-in-a-bst/submissions/
 * A: https://leetcode.com/problems/kth-smallest-element-in-a-bst/discuss/642139/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

namespace Array {
    class Solution {
    public:
        using VI = vector<int>;
        int kthSmallest(TreeNode* root, int K, VI A = {}) {
            go(root, A);
            return A[K - 1]; // K-th largest 🎯 (-1 for 0-based indexing)
        }
    private:
        void go(TreeNode* root, VI& A) {
            if (root->left) go(root->left, A);
            A.push_back(root->val);
            if (root->right) go(root->right, A);
        }
    };
}

namespace DecrementK {
    class Solution {
        public:
        using VI = vector<int>;
        int kthSmallest(TreeNode* root, int K, int ans = -1e9) {
            go(root, K, ans);
            return ans;
        }
        private:
        void go(TreeNode* root, int& K, int& ans) {
            if (K && root->left) go(root->left, K, ans);
            if (!--K) ans = root->val; // K-th largest 🎯
            if (K && root->right) go(root->right, K, ans);
        }
    };
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
