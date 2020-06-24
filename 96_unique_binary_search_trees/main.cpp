/*
 * 96. Unique Binary Search Trees
 *
 * Q: https://leetcode.com/problems/unique-binary-search-trees/
 * A: https://leetcode.com/problems/unique-binary-search-trees/discuss/703865/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>

using namespace std;

namespace BruteForce {
    class Solution {
        int go(int i, int j, int ans = 0) {
            if (j <= i)
                return 1; // 🛑 1 unique way to create: empty tree (if j < i) xor tree with 1 node (if j == i)
            for (auto k{ i }; k <= j; ++k) // for each root node k from i..j inclusive
                ans += go(i, k - 1) * go(k + 1, j); // 🎯 ans = left subtree ans * right subtree ans
            return ans;
        }
    public:
        int numTrees(int N) {
            return go(1, N);
        }
    };
}

namespace Memo {
    class Solution {
        using Map = unordered_map<int, unordered_map<int, int>>;
        int go(int i, int j, Map&& m = {}, int ans = 0) {
            if (m[i][j])
                return m[i][j]; // memo 🤔
            if (j <= i)
                return m[i][j] = 1; // 🛑  1 unique way to create: empty tree (if j < i) xor tree with 1 node (if j == i)
            for (auto k{ i }; k <= j; ++k) // for each root node k from i..j inclusive
                ans += go(i, k - 1, move(m)) * go(k + 1, j, move(m)); // 🎯 ans = left subtree ans * right subtree ans
            return m[i][j] = ans;
        }
    public:
        int numTrees(int N) {
            return go(1, N);
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        int numTrees(int N) {
            VI dp(N + 1);
            dp[0] = dp[1] = 1; // 🛑  1 unique way to create: empty tree xor tree with 1 node
            for (auto j{ 2 }; j <= N; ++j) // unique ways to create a tree of size j
                for (auto k{ 1 }; k <= j; ++k) // for each root node k from i..j inclusive
                    dp[j] += dp[k - 1] * dp[j - k]; // 🎯 ans = left subtree ans * right subtree ans
            return dp[N];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
