/*
 * 746. Min Cost Climbing Stairs
 *
 * Q: https://leetcode.com/problems/min-cost-climbing-stairs/
 * A: https://leetcode.com/problems/min-cost-climbing-stairs/discuss/110111/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace TopDownBruteForce {
    class Solution {
        using VI = vector<int>;
        VI A;
        int N;
        int go(int i) {
            if (N <= i)
                return 0; // 🛑  base case: we reached the top floor
            return A[i] + min(go(i + 1), go(i + 2)); // cost of i-th stair plus min of (i + 1)-th and (i + 2)-th solution 🎯
        }
    public:
        int minCostClimbingStairs(VI& A_) {
            A = A_;
            N = A.size();
            return min(go(0), go(1));
        }
    };
}

namespace TopDownMemo {
    class Solution {
        using VI = vector<int>;
        using Map = unordered_map<int, int>;
        VI A;
        int N;
        int go(int i, Map&& m = {}) {
            if (m[i])
                return m[i]; // memo 🤔
            if (N <= i)
                return m[i] = 0; // 🛑  base case: we reached the top floor
            return m[i] = A[i] + min(go(i + 1, move(m)), go(i + 2, move(m))); // cost of i-th stair plus min of (i + 1)-th and (i + 2)-th solution 🎯
        }
    public:
        int minCostClimbingStairs(VI& A_) {
            A = A_;
            N = A.size();
            return min(go(0), go(1));
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;

        int minCostClimbingStairs(VI &A) {
            int N = A.size();
            VI dp(N);
            dp[0] = A[0]; // 🛑  base case: start on first step
            dp[1] = A[1]; // 🛑  base case: start on second step
            for (auto i{2}; i < N; ++i)
                dp[i] = A[i] + min(dp[i - 2], dp[i - 1]); // cost of i-th stair plus min of (i - 2)-th and (i - 1)-th solution 🎯
            return min(dp[N - 2], dp[N - 1]); // N-th stair is reached from min of one or two stairs away
        }
    };
}

namespace BottomUpMemOpt {
    class Solution {
    public:
        using VI = vector<int>;
        int minCostClimbingStairs(VI& A) {
            int N = A.size();
            auto a = A[0], // 🛑  base case: start on first step
                 b = A[1], // 🛑  base case: start on second step
                 c = -1;
            for (auto i{ 2 }; i < N; ++i, a = b, b = c)
                c = A[i] + min(a, b); // cost of i-th stair plus min of (i - 2)-th and (i - 1)-th solution 🎯
            return min(a, b); // N-th stair is reached from min of one or two stairs away
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
