/*
 * 300. Longest Increasing Subsequence
 *
 * Q: https://leetcode.com/problems/longest-increasing-subsequence/
 * A: https://leetcode.com/problems/longest-increasing-subsequence/discuss/385203/C%2B%2B-and-Javascript-solutions
 */

/*

 A = 10 9 2 5 3 4
      0 1 2 3 4 5 6
      j           => 1
      i j         => 1
      i i j       => 1
      i i i j     => 2
      i i i i j   => 2
      i i i i i j => 3

 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace BruteForce {
    class Solution {
    public:
        using VI = vector<int>;
        int lengthOfLIS(VI& A) {
            return go(A);
        }
    private:
        int go(VI& A, int i = -1, VI&& seq = {}) {
            int max = seq.size();
            for (auto j{ i + 1 }; j < A.size(); ++j) {
                if (seq.empty() || seq.back() < A[j]) {
                    seq.push_back(A[j]);
                    max = std::max(max, go(A, j, move(seq)));
                    seq.pop_back();
                }
            }
            return max;
        }
    };
}

namespace BruteForceOptimized {
    class Solution {
    public:
        using VI = vector<int>;
        int lengthOfLIS(VI& A) {
            return go(A);
        }
    private:
        static constexpr auto INF = 1e9 + 7;
        int go(VI& A, int i = -1, int last = -INF, int len = 0) {
            int max = len;
            for (auto j{ i + 1 }; j < A.size(); ++j)
                if (last < A[j])
                    max = std::max(max, go(A, j, A[j], len + 1));
            return max;
        }
    };
}

namespace BruteForceOptimizedFurther {
    class Solution {
    public:
        using VI = vector<int>;
        int lengthOfLIS(VI& A) {
            return go(A);
        }
    private:
        static constexpr auto INF = 1e9 + 7;
        int go(VI& A, int i = -1, int last = -INF) {
            auto max{ 0 };
            for (auto j{ i + 1 }; j < A.size(); ++j)
                if (last < A[j])
                    max = std::max(max, 1 + go(A, j, A[j]));
            return max;
        }
    };
}

namespace TopDown {
    class Solution {
    public:
        using VI = vector<int>;
        using Memo = unordered_map<int, int>;
        int lengthOfLIS(VI& A, Memo m = {}, VI best = {}) {
            int N = A.size();
            if (N == 0)
                return 0;
            for (auto j{ 0 }; j < N; ++j)
                go(A, j, m);
            transform(m.begin(), m.end(), back_inserter(best), [](auto& pair) { return pair.second; });
            return *max_element(best.begin(), best.end());
        }
    private:
        int go(VI& A, int j, Memo& m) {
            if (m.find(j) != m.end())
                return m[j];
            m[j] = 1;
            for (auto i{ 0 }; i < j; ++i)
                if (A[i] < A[j])
                    m[j] = max(m[j], 1 + go(A, i, m));
            return m[j];
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        using VI = vector<int>;
        int lengthOfLIS(VI& A, int max = 1) {
            int N = A.size();
            if (N == 0)
                return 0;
            VI dp(N, 1);
            for (auto j{ 1 }; j < N; ++j)
                for (auto i{ 0 }; i < j; ++i)
                    if (A[i] < A[j])
                        max = std::max(max, dp[j] = std::max(dp[j], 1 + dp[i]));
            return max;
        }
    };
}

int main() {
    BruteForceOptimized::Solution solution;
    BruteForceOptimized::Solution::VI A{10,9,2,5,3,7,101,18};
    cout << solution.lengthOfLIS(A) << endl;
    return 0;
}
