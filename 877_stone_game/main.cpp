/*
 * 877. Stone Game
 *
 * Q: https://leetcode.com/problems/stone-game/
 * A: https://leetcode.com/problems/stone-game/discuss/706734/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace TopDownBruteForce {
    class Solution {
        using VI = vector<int>;
        VI A;
        int go(int i, int j) {
            if (i == j)
                return A[i]; // first == last 🛑
            return max(A[i] - go(i + 1, j), A[j] - go(i, j - 1)); // max(first, last) 🎯
        }
    public:
        bool stoneGame(VI& A_) {
            A = A_;
            return 0 < go(0, int(A.size()) - 1);
        }
    };
}

namespace TopDownMemo {
    class Solution {
        using VI = vector<int>;
        using Map = unordered_map<int, unordered_map<int, int>>;
        VI A;
        Map m;
        int go(int i, int j) {
            if (m[i][j])
                return m[i][j]; // memo 🤔
            if (i == j)
                return m[i][j] = A[i]; // first == last 🛑
            return m[i][j] = max(A[i] - go(i + 1, j), A[j] - go(i, j - 1)); // max(first, last) 🎯
        }
    public:
        bool stoneGame(VI& A_) {
            A = A_;
            return 0 < go(0, int(A.size()) - 1);
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        bool stoneGame(VI& A) {
            int N = A.size();
            VVI dp(N, VI(N)); // memo 🤔
            for (auto i{ N - 1 }; 0 <= i; --i)
                dp[i][i] = A[i]; // first == last 🛑
            for (auto i{ N - 1 }; 0 <= i; --i) // i-th first stone
                for (auto j = i + 1; j < N; ++j) // j-th last stone
                    dp[i][j] = max(dp[i][i] - dp[i + 1][j], dp[j][j] - dp[i][j - 1]); // max(first, last) 🎯
            return dp[0][N - 1];
        }
    };
}

namespace BottomUpOptimized {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        bool stoneGame(VI& A) {
            int N = A.size();
            VVI dp(N, VI(N)); // memo 🤔
            for (auto i{ N - 1 }; 0 <= i; --i) // i-th first stone
                for (auto j = i + 1; j < N; ++j) // j-th last stone
                    dp[i][j] = max(A[i] - dp[i + 1][j], A[j] - dp[i][j - 1]); // max(first, last) 🎯
            return dp[0][N - 1];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
