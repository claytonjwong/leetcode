/*
 * 449. Serialize and Deserialize BST
 *
 * Q: https://leetcode.com/problems/serialize-and-deserialize-bst/
 * A: https://leetcode.com/problems/serialize-and-deserialize-bst/discuss/93191/Javascript-Python3-C%2B%2B-Recursive-Pre-Order-Traversal
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

class Codec {
public:
    using fun1 = function<void(TreeNode*)>;
    using fun2 = function<TreeNode*()>;
    string serialize(TreeNode* root, vector<int> q = {}) {
        fun1 go = [&](auto root) {
            if (!root) {
                q.push_back(-1);
                return;
            }
            q.push_back(root->val);
            go(root->left);
            go(root->right);
        };
        go(root);
        ostringstream stream; copy(q.begin(), q.end(), ostream_iterator<int>(stream, " "));
        return stream.str();
    }
    TreeNode* deserialize(string data) {
        istringstream stream{ data };
        fun2 go = [&](int x = 0) -> TreeNode* {
            if (!(stream >> x))
                return nullptr;
            auto root = -1 < x ? new TreeNode(x) : nullptr;
            if (root) root->left  = go();
            if (root) root->right = go();
            return root;
        };
        return go();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
