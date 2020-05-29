/*
 * 1406. Stone Game III
 *
 * Q: https://leetcode.com/problems/stone-game-iii/
 * A: https://leetcode.com/problems/stone-game-iii/discuss/657825/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace TopDown {
    class Solution {
        using VI = vector<int>;
        int INF = 1e9 + 7;
        int go(VI& A, int i = 0) {
            auto N = A.size();
            if (i == N)
                return 0;
            auto max{ -INF };
            for (auto k{ 0 }, score{ 0 }; k < 3 && i + k < N; ++k)
                max = std::max(max, (score += A[i + k]) - go(A, i + k + 1));
            return max;
        }
    public:
        string stoneGameIII(VI& A) {
            return 0 < go(A) ? "Alice" : go(A) < 0 ? "Bob" : "Tie";
        }
    };
}

namespace TopDownMemo {
    class Solution {
        using VI = vector<int>;
        int INF = 1e9 + 7;
        int go(VI& A, VI& m, int i = 0) {
            if (m[i] > -INF)
                return m[i];
            auto N = A.size();
            if (i == N)
                return m[i] = 0;
            for (auto k{ 0 }, score{ 0 }; k < 3 && i + k < N; ++k)
                m[i] = std::max(m[i], (score += A[i + k]) - go(A, m, i + k + 1));
            return m[i];
        }
    public:
        string stoneGameIII(VI& A) {
            VI m(A.size() + 1, -INF);
            return 0 < go(A, m) ? "Alice" : go(A, m) < 0 ? "Bob" : "Tie";
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        int INF = 1e9 + 7;
        string stoneGameIII(VI& A) {
            int N = A.size();
            VI dp(A.size(), -INF);
            for (auto i{ N - 1 }; 0 <= i; --i)
                for (auto k{ 0 }, score{ 0 }; k < 3 && i + k < N; ++k)
                    dp[i] = max(dp[i], (score += A[i + k]) - (i + k + 1 < N ? dp[i + k + 1] : 0));
            return 0 < dp[0] ? "Alice" : dp[0] < 0 ? "Bob" : "Tie";
        }
    };
}

int main() {
    BottomUp::Solution solution;
    BottomUp::Solution::VI A{1,2,3,6};
    cout << solution.stoneGameIII(A) << endl;
    return 0;
}
