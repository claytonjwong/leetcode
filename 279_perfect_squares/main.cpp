/*
 * 279. Perfect Squares
 *
 * Q: https://leetcode.com/problems/perfect-squares/
 * A: https://leetcode.com/problems/perfect-squares/discuss/708644/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <numeric>

using namespace std;

namespace TopDownBruteForce {
    class Solution {
        int go(int i, int min = 1e9 + 7) {
            if (i <= 3)
                return i; // base cases 🛑
            for (int x = sqrt(i); 0 < x; --x)
                if (0 <= i - x * x)
                    min = std::min(min, 1 + go(i - x * x)); // min squares x*x to reach sum i 🎯
            return min;
        }
    public:
        int numSquares(int N) {
            return go(N);
        }
    };
}

namespace TopDownMemo {
    class Solution {
        using Map = unordered_map<int, int>;
        int go(int i, Map&& m = {}, int min = 1e9 + 7) {
            if (m.find(i) != m.end())
                return m[i]; // memo 🤔
            if (i <= 3)
                return m[i] = i; // base cases 🛑
            for (int x = sqrt(i); 0 < x; --x)
                if (0 <= i - x * x)
                    min = std::min(min, 1 + go(i - x * x, move(m))); // min squares x*x to reach sum i 🎯
            return m[i] = min;
        }
    public:
        int numSquares(int N) {
            return go(N);
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        int numSquares(int N, int INF = 1e9 + 7) {
            VI dp(N + 1, INF);
            for (auto i{ 0 }; i <= N && i <= 3; dp[i] = i, ++i); // base cases 🛑
            for (auto i{ 4 }; i <= N; ++i)
                for (int x = sqrt(i); 0 < x; --x)
                    if (0 <= i - x * x)
                        dp[i] = std::min(dp[i], 1 + dp[i - x * x]); // min squares x*x to reach sum i 🎯
            return dp[N];
        }
    };
}

namespace BottomUpOptimized {
    class Solution {
    public:
        using VI = vector<int>;
        int numSquares(int N) {
            VI dp(N + 1);
            iota(dp.begin(), dp.end(), 0); // implicit base cases 🛑
            for (auto i{ 4 }; i <= N; ++i)
                for (int x = sqrt(i); 0 < x; --x)
                    if (0 <= i - x * x)
                        dp[i] = std::min(dp[i], 1 + dp[i - x * x]); // min squares x*x to reach sum i 🎯
            return dp[N];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
