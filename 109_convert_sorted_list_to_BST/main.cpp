/*
 * 109. Convert Sorted List to Binary Search Tree
 *
 * Q: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 * A: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/discuss/615013/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    using VI = vector<int>;
    TreeNode* sortedListToBST(ListNode* head, VI A = {}) {
        while (head)
            A.push_back(head->val), head = head->next;
        return go(A, 0, A.size());
    }
private:
    TreeNode* go(VI& A, int i, int j) {
        if (i == j)
            return nullptr;
        auto k = (i + j) / 2;
        auto root = new TreeNode(A[k]);
        root->left = go(A, i, k);
        root->right = go(A, k + 1, j);
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
