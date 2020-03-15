/*
 * https://leetcode.com/contest/weekly-contest-180
 *
 * Rank            Name            Score    Finish Time     Q1 (3)    Q2 (4)       Q3 (4)    Q4 (6)
 * 2895 / 10047    claytonjwong    11       1:02:28         0:06:31   0:57:28 *1   0:23:30
 */

#include <iostream>
#include <vector>

using namespace std;

/*
 * 1380. Lucky Numbers in a Matrix
 *
 * Q: https://leetcode.com/problems/lucky-numbers-in-a-matrix/
 * A: https://leetcode.com/problems/lucky-numbers-in-a-matrix/discuss/539707/Javascript-and-C%2B%2B-solutions
 */

//class Solution {
//public:
//    using VI = vector<int>;
//    using VVI = vector<VI>;
//    VI luckyNumbers (VVI& A, int INF = 1e9 + 7, VI ans = {}) {
//        auto M = A.size(),
//             N = A[0].size();
//        VI min(M,  INF),
//           max(N, -INF);
//        for (auto i = 0; i < M; ++i)
//            for(auto j = 0; j < N; ++j)
//                min[i] = std::min(min[i], A[i][j]),
//                max[j] = std::max(max[j], A[i][j]);
//        for (auto i = 0; i < M; ++i)
//            for(auto j = 0; j < N; ++j)
//                if (min[i] == max[j])  // \U0001f340 lucky number \U0001f340
//                    ans.push_back(A[i][j]);
//        return ans;
//    }
//};

/*
 * 1382. Balance a Binary Search Tree
 *
 * Q: https://leetcode.com/problems/balance-a-binary-search-tree/
 * A: https://leetcode.com/problems/balance-a-binary-search-tree/discuss/540272/Javascript-and-C%2B%2B-solutions
 */

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val) : val{val}, left{nullptr}, right{nullptr} {}
};

class Solution {
public:
    using VI = vector<int>;
    using TN = TreeNode*;
    TN balanceBST(TN root, VI A = {}) {
        go(A, root);
        return bal(A, 0, A.size() - 1);
    }
private:
    void go(VI& A, TN root) {
        if (root->left) go(A, root->left);
        A.push_back(root->val);
        if (root->right) go(A, root->right);
    }
    TN bal(VI& A, int i, int j) {
        auto k = (i + j) / 2;
        auto root = new TreeNode(A[k]);
        root->left  = i < k ? bal(A, i, k - 1) : nullptr;
        root->right = k < j ? bal(A, k + 1, j) : nullptr;
        return root;
    }
};

/*
 * 1381. Design a Stack With Increment Operation
 *
 * Q: https://leetcode.com/problems/design-a-stack-with-increment-operation/
 * A: https://leetcode.com/problems/design-a-stack-with-increment-operation/discuss/539695/Javascript-and-C%2B%2B-solutions
 */

// too complicated and incorrect implementation

//class CustomStack {
//public:
//    CustomStack(int maxSize) : cap{maxSize}, N{0}, inc{0} {}
//
//    void push(int x) {
//        if (N + 1 < cap)
//            A.push_back(x), ++N;
//    }
//
//    int pop() {
//        if (N == 0) {
//            inc = 0;
//            return -1;
//        }
//        --N;
//        auto res = 0;
//        while (!A.empty()) {
//            res = A.back(); A.pop_back();
//            if (res < 0) {
//                inc += -res;
//                continue;
//            }
//            return res + inc;
//        }
//        return -1;
//    }
//
//    void increment(int k, int val) {
//        if (k <= 0)
//            return;
//        size_t pos = max(int(A.size()) - k, 0);
//        auto it = A.begin();
//        while (pos--) ++it;
//        A.insert(it, -val);
//    }
//
//private:
//    list<int> A;
//    int cap, N, inc;
//};

//["CustomStack",[3]      A = []
// "push",[1]             A = [1]
// "push",[2]             A = [1, 2]
// "pop",                 A = [1]
// "push",[2]             A = [1, 2]
// "push",[3]             A = [1, 2, 3]
// "push",[4]             A = [1, 2, 3]
// "increment",[5,100]    A = [1, 2, 3, -100]
// "increment",[2,100]    A = [3, 1, -100, 2, -100]
// "pop",
// "pop",
// "pop",
// "pop"]

//class CustomStack {
//public:
//    CustomStack(int maxSize) : cap{maxSize} {}
//
//    void push(int x) {
//        if (A.size() < cap)
//            A.push_back(x);
//    }
//
//    int pop() {
//        if (A.empty())
//            return -1;
//        auto res = A.back(); A.pop_back();
//        return res;
//    }
//
//    void increment(int k, int val) {
//        auto it = A.begin();
//        while (k-- && it != A.end())
//            *it++ += val;
//    }
//
//private:
//    list<int> A;
//    int cap;
//};

class CustomStack {
public:
    CustomStack(int maxSize) : cap{maxSize} {
    }
    void push(int x) {
        if (A.size() < cap)
            A.push_back(x);
    }
    int pop() {
        if (A.empty())
            return -1;
        auto res = A.back(); A.pop_back();
        return res;
    }
    void increment(int k, int val) {
        for (auto i = 0; i < k && i < A.size(); ++i)
            A[i] += val;
    }
private:
    vector<int> A;
    int cap;
};

int main() {
    CustomStack cs{3};
    cs.push(1);
    cs.push(2);
    cs.pop();
    cs.push(2);
    cs.push(3);
    cs.push(4);
    cs.increment(5, 100);
    cs.increment(2, 100);
    return 0;
}
