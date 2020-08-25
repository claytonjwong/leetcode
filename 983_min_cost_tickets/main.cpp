/*
 * 983. Minimum Cost For Tickets
 *
 * Q: https://leetcode.com/problems/minimum-cost-for-tickets/
 * A: https://leetcode.com/problems/minimum-cost-for-tickets/discuss/811237/Javascript-Python3-C%2B%2B-Top-Down-%2B-Bottom-Up
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace BruteForce {
    class Solution {
    public:
        using VI = vector<int>;
        using fun = function<int(int, int)>;
        int mincostTickets(VI& A, VI& cost, VI days = VI{1, 7, 30}) {
            int N = A.size();
            fun go = [&](auto i, auto day) {
                while (i < N && A[i] < day)
                    ++i;
                if (i == N)
                    return 0;             // 🛑 base case
                auto min = int(1e9 + 7);
                for (auto k{ 0 }; k < 3; ++k)
                    min = std::min(min, cost[k] + go(i, A[i] + days[k]));   // 🎯 min cost
                return min;
            };
            return go(0, 0);
        }
    };
}

namespace Memo {
    class Solution {
    public:
        using VI = vector<int>;
        using fun = function<int(int, int)>;
        using Map = unordered_map<int, int>;
        int mincostTickets(VI& A, VI& cost, VI days = VI{1, 7, 30}, Map m = {}) {
            int N = A.size();
            fun go = [&](auto i, auto day) {
                while (i < N && A[i] < day)
                    ++i;
                if (i == N)
                    return 0;             // 🛑 base case
                if (m[i])
                    return m[i];          // 🤔 memo
                m[i] = int(1e9 + 7);
                for (auto k{ 0 }; k < 3; ++k)
                    m[i] = std::min(m[i], cost[k] + go(i, A[i] + days[k]));   // 🎯 min cost
                return m[i];
            };
            return go(0, 0);
        }
    };
}

namespace DP {
    class Solution {
    public:
        using VI = vector<int>;
        using fun = function<int(int, int)>;
        using Map = unordered_map<int, int>;
        int mincostTickets(VI& A, VI& cost, VI days = VI{1, 7, 30}, Map m = {}) {
            int N = A.size();
            VI dp(N + 1, int(1e9 + 7));  // 🤔 memo
            dp[N] = 0;                   // 🛑 base case
            for (auto i{ N - 1 }; 0 <= i; --i) {
                auto j{ i };
                for (auto k{ 0 }; k < 3; ++k) {
                    while (j < N && A[j] < A[i] + days[k])
                        ++j;
                    dp[i] = min(dp[i], cost[k] + dp[j]);   // 🎯 min cost
                }
            }
            return dp[0];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
