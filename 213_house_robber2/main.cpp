/*
 * 213. House Robber II
 *
 * Q: https://leetcode.com/problems/house-robber-ii/
 * A: https://leetcode.com/problems/house-robber-ii/discuss/894504/Kt-Js-Py3-Cpp-The-ART-of-Dynamic-Programming
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
        using fun = function<int(int, int, int)>;
        int rob(VI& A) {
            int N = A.size();
            fun go = [&](int i, int first, int last) {
                if (i == N)                                                      // 🛑 base case
                    return 0;
                if (last + 1 == i || (first && i + 1 == N && 1 < N))             // 🚫 without i-th house (due to adjacent neighbor constraint)
                    return go(i + 1, first, last);
                return max(A[i] + go(i + 1, first, i), go(i + 1, first, last));  // ✅ with i-th house xor 🚫 without i-th house
            };
            return max(go(0, true, -123), go(1, false, -123));                   // ✅ with first house xor 🚫 without first house
        }
    };
}

namespace TopDownMemo {
    class Solution {
    public:
        using VI = vector<int>;
        using fun = function<int(int, int, int)>;
        using Map = unordered_map<string, int>;
        int rob(VI& A, Map m = {}) {
            int N = A.size();
            fun go = [&](int i, int first, int last) {
                stringstream key; key << i << ',' << first << ',' << last;
                if (m.find(key.str()) != m.end())                                               // 🤔 memo
                    return m[key.str()];
                if (i == N)                                                                     // 🛑 base case
                    return m[key.str()] = 0;
                if (last + 1 == i || (first && i + 1 == N && 1 < N))                            // 🚫 without i-th house (due to adjacent neighbor constraint)
                    return m[key.str()] = go(i + 1, first, last);
                return m[key.str()] = max(A[i] + go(i + 1, first, i), go(i + 1, first, last));  // ✅ with i-th house xor 🚫 without i-th house
            };
            return max(go(0, true, -123), go(1, false, -123));                                  // ✅ with first house xor 🚫 without first house
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int rob(VI& A) {
            int N = A.size();
            if (N == 1)                                                    // 💎 corner case
                return A[0];
            auto best = [&](auto start) {
                VI dp(N + 2);                                              // 🤔 memo + 🛑 base cases (ie. dp[N] = 0 and dp[N + 1] = 0)
                for (auto i{ N - 1 - (start ? 0 : 1) }; start <= i; --i)
                    dp[i] = max(A[i] + dp[i + 2], dp[i + 1]);              // ✅ with i-th house xor 🚫 without i-th house
                return dp[start];
            };
            return max(best(0), best(1));                                  // ✅ with first house xor 🚫 without first house
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
