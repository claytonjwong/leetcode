/*
 * 589. N-ary Tree Preorder Traversal
 *
 * Q: https://leetcode.com/problems/n-ary-tree-preorder-traversal/
 * A: https://leetcode.com/problems/n-ary-tree-preorder-traversal/discuss/486422/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <queue>

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

/*
class Solution {
public:
    using VI = vector<int>;
    VI preorder(Node* root) {
        go(root);
        return ans;
    }
private:
    VI ans = {};
    void go(Node* root) {
        if (!root)
            return;
        ans.push_back(root->val);
        for (auto child: root->children)
            go(child);
    }
};
*/

class Solution {
public:
    using VI = vector<int>;
    using Queue = deque<Node*>;
    VI preorder(Node* root, VI ans = {}) {
        Queue q({root});
        while (!q.empty()) {
            auto cur = q.front(); q.pop_front();
            if (!cur)
                continue;
            ans.push_back(cur->val);
            for (auto it = cur->children.rbegin(); it != cur->children.rend(); ++it)
                q.push_front(*it);
        }
        return ans;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
