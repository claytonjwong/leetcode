/*
 * 95. Unique Binary Search Trees II
 *
 * Q: https://leetcode.com/problems/unique-binary-search-trees-ii/
 * A: https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/705421/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val, TreeNode* left, TreeNode* right) : val{ val }, left{ left }, right{ right } {}
};

class Solution {
    using Nodes = vector<TreeNode*>;
    Nodes go(int i, int j, Nodes ans = {}) {
        if (j < i)
            return { nullptr };
        for (auto k{ i }; k <= j; ++k) {
            auto L = go(i, k - 1),
                 R = go(k + 1, j);
            for (auto left: L)
                for (auto right: R)
                    ans.push_back(new TreeNode(k, left, right));
        }
        return ans;
    }
public:
    Nodes generateTrees(int N) {
        return N ? go(1, N) : Nodes{};
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
