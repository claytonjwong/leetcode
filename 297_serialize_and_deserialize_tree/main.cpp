/*
 * 297. Serialize and Deserialize Binary Tree
 *
 * Q: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
 * A: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/607219/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

class Codec {
public:
    using VI = vector<int>;
    const int INF = 1e9 + 7;
    string serialize(TreeNode* root, VI A = {}, stringstream ans = stringstream()) {
        flat(root, A);
        ans << A[0]; for (auto i{ 1 }; i < A.size(); ans << "," << A[i++]);
        return ans.str();
    }
    TreeNode* deserialize(string s, VI A = {}) {
        transform(s.begin(), s.end(), s.begin(), [](auto c) { return c == ',' ? ' ' : c; });
        stringstream stream{ s };
        copy(istream_iterator<int>(stream), istream_iterator<int>(), back_inserter(A));
        reverse(A.begin(), A.end());
        return obj(A);
    }
private:
    void flat(TreeNode* root, VI& A) {
        if (!root) {
            A.push_back(INF);
            return;
        }
        A.push_back(root->val);
        flat(root->left, A);
        flat(root->right, A);
    }
    TreeNode* obj(VI& A) {
        if (A.back() == INF) {
            A.pop_back();
            return nullptr;
        }
        auto x = A.back(); A.pop_back();
        TreeNode* root = new TreeNode(x);
        root->left = obj(A);
        root->right = obj(A);
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
