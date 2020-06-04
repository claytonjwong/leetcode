/*
 * 1444. Number of Ways of Cutting a Pizza
 *
 * Q: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/
 * A: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/discuss/670177/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace TopDown {
    class Solution {
        using VS = vector<string>;
        using VI = vector<int>;
        using VVI = vector<VI>;
        VS A;
        int T, M, N;
        VVI dp;
        int go(int i, int j, int t, int cnt = 0) {
            if (!dp[i][j])
                return 0; // no apple 🍎 ❌
            if (!t)
                return 1; // target t cuts 🎯
            for (auto k{ 1 }; i + k <= M; ++k)
                if (dp[i][j] - dp[i + k][j] > 0) // upper piece contains at least one apple 🍏 ✅
                    cnt = (cnt + go(i + k, j, t - 1)) % int(1e9 + 7);
            for (auto k{ 1 }; j + k <= N; ++k)
                if (dp[i][j] - dp[i][j + k] > 0) // left piece contains at least one apple 🍏 ✅
                    cnt = (cnt + go(i, j + k, t - 1)) % int(1e9 + 7);
            return cnt;
        }
    public:
        int ways(VS& pizza, int cuts) {
            A = pizza;
            T = cuts - 1; // -1 per problem statement
            M = A.size();
            N = A[0].size();
            dp = VVI(M + 1, VI(N + 1));
            for (auto i{ M - 1 }; 0 <= i; --i) // 2D prefix sums
                for (auto j{ N - 1 }; 0 <= j; --j)
                    dp[i][j] = int(A[i][j] == 'A') + dp[i + 1][j] + dp[i][j + 1] - dp[i + 1][j + 1];
            return go(0, 0, T);
        }
    };
}

namespace TopDownMemo {
    class Solution {
        using VS = vector<string>;
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Map = unordered_map<string, int>;
        VS A;
        int T, M, N;
        VVI dp;
        Map m;
        int go(int i, int j, int t, Map&& m = {}, int cnt = 0) {
            stringstream key; key << i << ',' << j << ',' << t;
            if (m.find(key.str()) != m.end())
                return m[key.str()];
            if (!dp[i][j])
                return m[key.str()] = 0; // no apple 🍎
            if (!t)
                return 1; // target t cuts 🎯
            for (auto k{ 1 }; i + k <= M; ++k)
                if (dp[i][j] - dp[i + k][j] > 0) // upper piece contains at least one apple 🍏 ✅
                    cnt = (cnt + go(i + k, j, t - 1, move(m))) % int(1e9 + 7);
            for (auto k{ 1 }; j + k <= N; ++k)
                if (dp[i][j] - dp[i][j + k] > 0) // left piece contains at least one apple 🍏 ✅
                    cnt = (cnt + go(i, j + k, t - 1, move(m))) % int(1e9 + 7);
            return m[key.str()] = cnt;
        }
    public:
        int ways(VS& pizza, int cuts) {
            A = pizza;
            T = cuts - 1; // -1 per problem statement
            M = A.size();
            N = A[0].size();
            dp = VVI(M + 1, VI(N + 1));
            for (auto i{ M - 1 }; 0 <= i; --i) // 2D prefix sums
                for (auto j{ N - 1 }; 0 <= j; --j)
                    dp[i][j] = int(A[i][j] == 'A') + dp[i + 1][j] + dp[i][j + 1] - dp[i + 1][j + 1];
            return go(0, 0, T);
        }
    };
}

int main() {
    TopDown::Solution solution;
    vector<string> pizza{
        "A..",
        "AAA",
        "..."
    };
    auto cuts{ 3 };
    cout << solution.ways(pizza, cuts) << endl;
    return 0;
}
