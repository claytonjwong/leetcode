/*
 * 987. Vertical Order Traversal of a Binary Tree
 *
 * Q: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
 * A: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/discuss/778164/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

namespace January_29_2021 {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Map = map<int, map<int, set<int>>>;
        using fun = function<void(TreeNode*, int, int)>;
        VVI verticalTraversal(TreeNode* root, Map m = {}, VVI ans = {}) {
            fun go = [&](auto root, auto x, auto y) {
                if (!root)
                    return;
                m[x][y].insert(root->val);
                if (root->left)  go(root->left,  x - 1, y + 1);
                if (root->right) go(root->right, x + 1, y + 1);
            };
            go(root, 0, 0);
            for (auto& [x, y]: m) {
                ans.emplace_back(VI{});
                for (auto& [_, reps]: y)
                    copy(reps.begin(), reps.end(), back_inserter(ans.back()));
            }
            return ans;
        }
    };
}


namespace August_07_2020 {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Map = unordered_map<int, map<int, VI>>;
        using fun = function<void(TreeNode*, int, int)>;
        VVI verticalTraversal(TreeNode* root, Map m = {}, VVI ans = {}) {
            fun go = [&](TreeNode* root, int x = 0, int y = 0) {
                if (!root)
                    return;
                m[x][y].push_back(root->val);
                go(root->left, x - 1, y + 1);
                go(root->right, x + 1, y + 1);
            };
            go(root, 0, 0);
            for (auto x{ -999 }; x <= 999; ++x) {
                if (m.find(x) == m.end())
                    continue;
                for (auto& [_, nodes]: m[x])
                    sort(nodes.begin(), nodes.end()); // sort nodes with same y by value
                VI cur;
                for (auto& [_, nodes]: m[x])
                    cur.insert(cur.end(), nodes.begin(), nodes.end());
                ans.push_back(cur);
            }
            return ans;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
