#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

/*
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val_) : val{val_}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    using DepthSum = unordered_map<int, int>;
    int maxLevelSum(TreeNode* root, DepthSum depthSum={}, int max_sum=int(-1e6), int ans=0) {
        go(root, depthSum);
        for (auto& pair: depthSum) {
            auto depth = pair.first,
                sum = pair.second;
            if (max_sum < sum) {
                max_sum = sum;
                ans = depth;
            }
        }
        return ans;
    }
private:
    void go(TreeNode* root, DepthSum& depthSum, int depth=0) {
        if (!root)
            return;
        depthSum[depth] += root->val;
        go(root->left, depthSum, depth + 1);
        go(root->right, depthSum, depth + 1);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(7);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);
    root->right = new TreeNode(0);
    auto ans = Solution().maxLevelSum(root);
    cout << ans << endl;
    return 0;
}
 */

int main() {
    set<int> s{2,3,4};
    auto it = s.upper_bound(1);
    if (it == s.begin())
        cout << "begin!" << endl;
    return 0;
}