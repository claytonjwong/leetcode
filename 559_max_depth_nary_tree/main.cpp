/*
 * 559. Maximum Depth of N-ary Tree
 *
 * Q: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
 * A: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/discuss/596980/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int val;
    vector<Node*> children;
};

class Solution {
public:
    int maxDepth(Node* root) {
        return !root ? 0 : go(root);
    }
private:
    int go(Node* root, int max = 1) {
        for (auto child: root->children)
            max = std::max(max, 1 + go(child));
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
