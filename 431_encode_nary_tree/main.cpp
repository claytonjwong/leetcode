/*
 * 431. Encode N-ary Tree to Binary Tree
 *
 * Q: https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree/
 * A: https://leetcode.com/problems/encode-n-ary-tree-to-binary-tree/discuss/920789/Kt-Js-Py3-Cpp-Recursive-Copy
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

struct Node {
    int val;
    vector<Node*> children;
    Node(int val) : val{ val } {}
};

class Codec {
public:
    TreeNode* encode(Node* parent) {
        if (!parent)
            return nullptr;
        TreeNode* copy = new TreeNode(parent->val);
        TreeNode* next = nullptr;
        for (auto child: parent->children)
            if (next)
                next->right = encode(child), next = next->right;
            else
                next = copy->left = encode(child);
        return copy;
    }
    Node* decode(TreeNode* parent) {
        if (!parent)
            return nullptr;
        Node* copy = new Node(parent->val);
        TreeNode* next = parent->left;
        while (next)
            copy->children.push_back(decode(next)), next = next->right;
        return copy;
    }
};

int main() {
    Codec codec;
    Node* orig = new Node(1);
    orig->children.push_back(new Node(3));
    orig->children[0]->children.push_back(new Node(5));
    orig->children[0]->children.push_back(new Node(6));
    orig->children.push_back(new Node(2));
    orig->children.push_back(new Node(4));
    TreeNode* copy = codec.encode(orig);
    Node* back = codec.decode(copy);
    return 0;
}
