/*
 * 198. House Robber
 *
 * Q: https://leetcode.com/problems/house-robber/
 * A: https://leetcode.com/problems/house-robber/discuss/846461/Javascript-Python3-C%2B%2B-The-ART-of-Dynamic-Programming
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace BruteForce {
    class Solution {
    public:
        using VI = vector<int>;
        using fun = function<int(int, int)>;
        int rob(VI& A) {
            fun go = [&](auto pre, auto cur) {
                if (cur == A.size())
                    return 0;                 // 🛑 base case
                else if (pre == cur - 1)
                    return go(pre, cur + 1);  // 🚫 without (due to adjacent neighbor constraint)
                else
                    return max(A[cur] + go(cur, cur + 1), go(pre, cur + 1));  // ✅ with or 🚫 without
            };
            return go(-2, 0);
        }
    };
}
namespace Memo {
    class Solution {
    public:
        using VI = vector<int>;
        using fun = function<int(int, int)>;
        using Map = unordered_map<string, int>;
        int rob(VI& A, Map m = {}) {
            fun go = [&](auto pre, auto cur) {
                stringstream key; key << pre << "," << cur;
                if (m.find(key.str()) != m.end())
                    return m[key.str()];                     // 🤔 memo
                if (cur == A.size())
                    return m[key.str()] = 0;                 // 🛑 base case
                else if (pre == cur - 1)
                    return m[key.str()] = go(pre, cur + 1);  // 🚫 without (due to adjacent neighbor constraint)
                else
                    return m[key.str()] = max(A[cur] + go(cur, cur + 1), go(pre, cur + 1));  // ✅ with or 🚫 without
            };
            return go(-2, 0);
        }
    };
}
namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        int rob(VI& A) {
            int N = A.size();
            VI dp(N + 2);                                  // 🤔 memo +2 for 🛑 base cases
            for (auto i{ N - 1 }; 0 <= i; --i)
                dp[i] = max(A[i] + dp[i + 2], dp[i + 1]);  // ✅ with or 🚫 without
            return max(dp[0], dp[1]);
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
