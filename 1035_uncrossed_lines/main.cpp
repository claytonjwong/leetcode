/*
 * 1035. Uncrossed Lines
 *
 * Q: https://leetcode.com/problems/uncrossed-lines/
 * A: https://leetcode.com/problems/uncrossed-lines/discuss/652184/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace TopDown {
    class Solution {
    public:
        using VI = vector<int>;
        int maxUncrossedLines(VI& A, VI& B) {
            return go(A, B);
        }
    private:
        int go(VI& A, VI& B, int i = 0, int j = 0) {
            auto M = A.size(),
                 N = B.size();
            if (i == M || j == N)
                return 0;
            return max({
                go(A, B, i + 1, j + 1) + int(A[i] == B[j]), // match 🎯 / mismatch
                go(A, B, i, j + 1), go(A, B, i + 1, j)      // insertion / deletion
            });
        }
    };
}

namespace TopDownMemo {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int maxUncrossedLines(VI& A, VI& B) {
            return go(A, B);
        }
    private:
        int go(VI& A, VI& B, int i = 0, int j = 0, VVI&& m = VVI(501, VI(501, -1))) {
            if (m[i][j] > -1)
                return m[i][j];
            auto M = A.size(),
                 N = B.size();
            if (i == M || j == N)
                return m[i][j] = 0;
            return m[i][j] = max({
                go(A, B, i + 1, j + 1, move(m)) + int(A[i] == B[j]),     // match 🎯 / mismatch
                go(A, B, i, j + 1, move(m)), go(A, B, i + 1, j, move(m)) // insertion / deletion
            });
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        int maxUncrossedLines(VI& A, VI& B) {
            auto M = A.size(),
                 N = B.size();
            VVI dp = VVI(M + 1, VI(N + 1, 0));
            for (auto i{ 1 }; i <= M; ++i)
                for (auto j{ 1 }; j <= N; ++j)
                    dp[i][j] = max({
                        dp[i - 1][j - 1] + int(A[i - 1] == B[j - 1]), // match 🎯 / mismatch
                        dp[i][j - 1], dp[i - 1][j]                    // insertion / deletion
                    });
            return dp[M][N];
        }
    };
}

namespace BottomUpMemOpt {
    class Solution {
    public:
        using VI = vector<int>;
        int maxUncrossedLines(VI& A, VI& B) {
            auto M = A.size(),
                 N = B.size();
            VI pre(N + 1, 0),
               cur{ pre };
            for (auto i{ 1 }; i <= M; ++i) {
                for (auto j{ 1 }; j <= N; ++j)
                    cur[j] = max({
                        pre[j - 1] + int(A[i - 1] == B[j - 1]), // match 🎯 / mismatch
                        cur[j - 1], pre[j]                      // insertion / deletion
                    });
                swap(pre, cur);
            }
            return pre[N];
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
