/*
 * 1367. Linked List in Binary Tree
 *
 * Q: https://leetcode.com/problems/linked-list-in-binary-tree/
 * A: https://leetcode.com/problems/linked-list-in-binary-tree/discuss/527789/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val{val}, next{nullptr} {}
};

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        return go(head, root);
    }
private:
    bool go(ListNode* head, TreeNode* root) {
        if (root == nullptr)
            return false;
        if (step(head, root))
            return true;
        return go(head, root->left) || go(head, root->right);
    }
    bool step(ListNode* head, TreeNode* root) {
        if (head == nullptr)
            return true;
        if (root == nullptr || head->val != root->val)
            return false;
        return step(head->next, root->left) || step(head->next, root->right);
    }
};

//class Solution {
//public:
//    bool isSubPath(ListNode* head, TreeNode* root) {
//        return go(head, root);
//    }
//private:
//    bool go(ListNode* head, TreeNode* root) {
//        return !root ? false : step(head, root) ? true : go(head, root->left) || go(head, root->right);
//    }
//    bool step(ListNode* head, TreeNode* root) {
//        return !head ? true : !root || head->val != root->val ? false : step(head->next, root->left) || step(head->next, root->right);
//    }
//};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
