/*
 * 1485. Clone Binary Tree With Random Pointer
 *
 * Q: https://leetcode.com/problems/clone-binary-tree-with-random-pointer/
 * A: https://leetcode.com/problems/clone-binary-tree-with-random-pointer/discuss/700881/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int val;
    Node *left, *right, *random;
    Node(int val) : val{ val }, left{ nullptr }, right{ nullptr }, random{ nullptr } {}
};

struct NodeCopy {
    int val;
    NodeCopy *left, *right, *random;
    NodeCopy(int val) : val{ val }, left{ nullptr }, right{ nullptr }, random{ nullptr } {}
};

class Solution {
    using Map = unordered_map<Node*, NodeCopy*>;
    Map m;
    NodeCopy* go(Node* root) {
        if (!root)
            return nullptr;
        m[root] = new NodeCopy(root->val);
        m[root]->left = go(root->left);
        m[root]->right = go(root->right);
        return m[root];
    }
    NodeCopy* fix(Node* root, NodeCopy* copy, int i = 0) {
        if (!root)
            return nullptr;
        if (root->random)
            copy->random = m[root->random];
        fix(root->left, copy->left);
        fix(root->right, copy->right);
        return copy;
    }
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        return fix(root, go(root));
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
