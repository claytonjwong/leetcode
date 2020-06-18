/*
 * 108. Convert Sorted Array to Binary Search Tree
 *
 * Q: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * A: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/discuss/694149/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{ val }, left{ nullptr }, right{ nullptr } {}
};
class Solution {
    using VI = vector<int>;
    VI A;
    TreeNode* go(int i, int j) {
        if (j < i)
            return nullptr;
        auto k = (i + j) / 2;
        auto root = new TreeNode(A[k]);
        root->left = go(i, k - 1);
        root->right = go(k + 1, j);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(VI& A_) {
        A = A_;
        int N = A.size();
        return go(0, N - 1);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
