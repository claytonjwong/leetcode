/*
 * 508. Most Frequent Subtree Sum
 *
 * Q: https://leetcode.com/problems/most-frequent-subtree-sum/
 * A: https://leetcode.com/problems/most-frequent-subtree-sum/discuss/780522/Javascript-Python3-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
};

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    using Pair = pair<int, int>;
    using Pairs = vector<Pair>;
    using fun = function<int(TreeNode*)>;
    VI findFrequentTreeSum(TreeNode* root, Map m = {}, int max = 0, Pairs P = {}, VI ans = {}) {
        if (!root)
            return {};
        fun go = [&](TreeNode* root) {
            auto L = root->left  ? go(root->left)  : 0,
                 R = root->right ? go(root->right) : 0,
                 sum = root->val + L + R;
            max = std::max(max, ++m[sum]);
            return sum;
        };
        go(root);
        copy_if(m.begin(), m.end(), back_inserter(P), [=](auto& pair) { return pair.second == max; });
        transform(P.begin(), P.end(), back_inserter(ans), [](auto& pair) { return pair.first; });
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
