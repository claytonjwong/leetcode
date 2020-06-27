/*
 * 1490. Clone N-ary Tree
 *
 * Q: https://leetcode.com/problems/clone-n-ary-tree/
 * A: https://leetcode.com/problems/clone-n-ary-tree/discuss/707049/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    vector<Node*> children;
    Node(int val) : val{ val } {}
};

class Solution {
    Node* go(Node* root) {
        if (!root)
            return nullptr;
        auto copy = new Node(root->val);
        for (auto child: root->children)
            copy->children.push_back(go(child));
        return copy;
    }
public:
    Node* cloneTree(Node* root) {
        return go(root);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
