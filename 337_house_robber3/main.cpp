/*
 * 337. House Robber III
 *
 * Q: https://leetcode.com/problems/house-robber-iii/
 * A: https://leetcode.com/problems/house-robber-iii/discuss/946524/Kt-Js-Py3-Cpp-The-ART-of-Dynamic-Programming
 */

#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{ val }, left{ nullptr }, right{ nullptr } {}
};

namespace DFS {
    class Solution {
    public:
        using fun = function<int(TreeNode*, bool)>;
        int rob(TreeNode* root, int INF = 1e9 + 7) {
            fun go = [&](auto root, auto isRobbable) {
                if (!root)
                    return 0;
                auto include = go(root->left, false) + go(root->right, false) + root->val,
                     exclude = go(root->left, true)  + go(root->right, true);
                return max(isRobbable ? include : -INF, exclude);
            };
            return go(root, true);
        }
    };
}
namespace Memo {
    class Solution {
    public:
        using fun = function<int(TreeNode*, bool)>;
        using Map = unordered_map<string, int>;
        int rob(TreeNode* root, Map m = {}, int INF = 1e9 + 7) {
            fun go = [&](auto root, auto isRobbable) {
                stringstream key; key << root << "," << isRobbable;
                if (m.find(key.str()) != m.end())
                    return m[key.str()];
                if (!root)
                    return m[key.str()] = 0;
                auto include = go(root->left, false) + go(root->right, false) + root->val,
                     exclude = go(root->left, true)  + go(root->right, true);
                return m[key.str()] = max(isRobbable ? include : -INF, exclude);
            };
            return go(root, true);
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
