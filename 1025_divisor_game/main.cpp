/*
 * 1025. Divisor Game
 *
 * Q: https://leetcode.com/problems/divisor-game/
 * A: https://leetcode.com/problems/divisor-game/discuss/292472/C%2B%2B-solutions%3A-Top-Down-and-Bottom-Up
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

namespace BruteForce {
    class Solution {
    public:
        using fun = function<bool(int)>;
        bool divisorGame(int N) {
            fun go = [&](int i) {
                if (i == 1)           // 🛑 base case
                    return false;
                for (auto j = int(sqrt(i)); 1 <= j; --j)
                    if (!(i % j) && !go(i - j))
                        return true;  // 🎯  I win if I play j and you lose
                return false;
            };
            return go(N);
        }
    };
}

namespace TopDown {
    class Solution {
    public:
        using fun = function<bool(int)>;
        using VI = vector<int>;
        static constexpr auto INF = int(1e9 + 7);
        bool divisorGame(int N) {
            VI m(N + 1, INF);
            fun go = [&](int i) {
                if (m[i] < INF)             // 🤔 memo
                    return m[i];
                if (i == 1)                 // 🛑 base case
                    return m[i] = false;
                for (auto j = int(sqrt(i)); 1 <= j; --j)
                    if (!(i % j) && !go(i - j))
                        return m[i] = true;  // 🎯  I win if I play j and you lose
                return m[i] = false;
            };
            return go(N) < INF ? go(N) : false;
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using fun = function<bool(int)>;
        using VI = vector<int>;
        bool divisorGame(int N) {
            VI dp(N + 1);              // 🤔 memo with implicit 🛑 base case: dp[1] = false
            for (auto i{ 2 }; i <= N; ++i)
                for (auto j = int(sqrt(i)); 1 <= j; --j)
                    if (!(i % j) && !dp[i - j])
                        dp[i] = true;  // 🎯  I win if I play j and you lose
            return dp[N];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
