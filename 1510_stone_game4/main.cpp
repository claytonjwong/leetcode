/*
 * 1510. Stone Game IV
 *
 * Q: https://leetcode.com/problems/stone-game-iv/
 * A: https://leetcode.com/problems/stone-game-iv/discuss/737869/Javascript-Python3-C%2B%2B
 */

#include <iostream>
#include <unordered_map>

using namespace std;

namespace TopDown {
    class Solution {
        bool go(int i) {
            if (!i)
                return false; // 🛑 base case: no stones left
            for (int j = sqrt(i); 1 <= j; --j) // ⭐️ take each (j * j) stones
                if (!go(i - (j * j)))
                    return true; // 🎯 if next player lost, then current player wins
            return false;
        }
    public:
        bool winnerSquareGame(int N) {
            return go(N);
        }
    };
}

namespace TopDownMemo {
    class Solution {
        using Map = unordered_map<int, int>;
        bool go(int i, Map&& m = {}) {
            if (m.find(i) != m.end())
                return m[i]; // 🤔 memo
            if (!i)
                return m[i] = false; // 🛑 base case: no stones left
            for (int j = sqrt(i); 1 <= j; --j) // ⭐️ take each (j * j) stones, 💎 avoid TLE by taking largest (j * j) first
                if (!go(i - (j * j), move(m)))
                    return m[i] = true; // 🎯 if next player lost, then current player wins
            return m[i] = false;
        }
    public:
        bool winnerSquareGame(int N) {
            return go(N);
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        bool winnerSquareGame(int N) {
            bitset<100001> dp; // 🤔 memo
            dp[0] = 0; // 🛑 base case: no stones left
            for (auto i{ 1 }; i <= N; ++i)
                for (int j = sqrt(i); 1 <= j; --j) // ⭐️ take each (j * j) stones
                    if (!dp[i - (j * j)])
                        dp[i] = 1; // 🎯 if next player lost, then current player wins
            return dp[N];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
