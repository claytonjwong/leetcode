/*
 * 117. Populating Next Right Pointers in Each Node II
 *
 * Q: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
 * A: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/discuss/706949/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int val;
    Node *left, *right, *next;
};

class Solution {
public:
    using Queue = queue<Node*>;
    Node* connect(Node* root) {
        if (!root)
            return nullptr;
        Queue q{{ root }};
        while (q.size()) {
            auto k = q.size();
            while (k--) {
                auto cur = q.front(); q.pop();
                cur->next = k ? q.front() : nullptr;
                if (cur->left)  q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
