/*
 * 590. N-ary Tree Postorder Traversal
 *
 * Q: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
 * A: https://leetcode.com/problems/n-ary-tree-postorder-traversal/discuss/487687/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    using VI = vector<int>;
    using Stack = vector<Node*>;
    VI postorder(Node* root, Stack s = {}, VI ans = {}) {
        if (root)
            s.push_back(root);
        while (!s.empty()) {
            auto cur = s.back(); s.pop_back();
            ans.push_back(cur->val);
            for (auto child: cur->children)
                s.push_back(child);
        }
        return {ans.rbegin(), ans.rend()};
    }
};

int main() {
    auto root = new Node(1);
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(4));
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));
    Solution solution;
    auto ans = solution.postorder(root);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
