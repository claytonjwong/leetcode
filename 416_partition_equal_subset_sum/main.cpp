/*
 * 416. Partition Equal Subset Sum
 *
 * Q: https://leetcode.com/problems/partition-equal-subset-sum/
 * A: https://leetcode.com/problems/partition-equal-subset-sum/discuss/617275/Kt-Js-Py3-Cpp-The-ART-of-Dynamic-Programming
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

namespace TopDown {
    class Solution {
    public:
        using VI = vector<int>;
        using fun = function<bool(int, int)>;
        bool canPartition(VI& A) {
            auto total = accumulate(A.begin(), A.end(), 0);
            if (total & 1)                                   // ❌ odd total cannot be evenly divided by 2
                return false;
            auto target = total / 2;
            fun go = [&](auto i, auto t) {
                if (i == A.size() || target < t)             // 🛑 base case: target not reached
                    return false;
                if (t == target)                             // 🎯 target reached
                    return true;
                return go(i + 1, t + A[i]) || go(i + 1, t);  // 🚀 explore ✅ with xor 🚫 without A[i]
            };
            return go(0, 0);
        }
    };
}
namespace Memo {
    class Solution {
    public:
        using VI = vector<int>;
        using fun = function<bool(int, int)>;
        using Map = unordered_map<string, bool>;
        bool canPartition(VI& A, Map m = {}) {
            auto total = accumulate(A.begin(), A.end(), 0);
            if (total & 1)                                                  // ❌ odd total cannot be evenly divided by 2
                return false;
            auto target = total / 2;
            fun go = [&](auto i, auto t) {
                stringstream key; key << i << ',' << t;
                if (m.find(key.str()) != m.end())                           // 🤔 memo
                    return m[key.str()];
                if (i == A.size() || target < t)                            // 🛑 base case: target not reached
                    return m[key.str()] = false;
                if (t == target)                                            // 🎯 target reached
                    return m[key.str()] = true;
                return m[key.str()] = go(i + 1, t + A[i]) || go(i + 1, t);  // 🚀 explore ✅ with xor 🚫 without A[i]
            };
            return go(0, 0);
        }
    };
}
namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        bool canPartition(VI& A) {
            auto total = accumulate(A.begin(), A.end(), 0);
            if (total & 1)      // ❌ odd total cannot be evenly divided by 2
                return false;
            auto target = total / 2;
            VI dp(target + 1);  // 🤔 memo
            dp[0] = 1;          // 🛑 base case: we can reach target 0
            for (auto x: A)     // 🤔 if we can reach t 🚫 without x, then we can reach t ✅ with x
                for (auto t{ target }; x <= t; --t)
                    if (dp[t - x])
                        dp[t] = 1;
            return dp[target];  // 🎯 target reached?
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
