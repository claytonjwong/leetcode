/*
 * 1449. Form Largest Integer With Digits That Add up to Target
 *
 * Q: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
 * A: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/discuss/644535/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace TopDown { // TLE
    class Solution {
    public:
        static constexpr auto N{ 9 };
        using VI = vector<int>;
        string largestNumber(VI& A, int T) {
            return go(A, T);
        }
    private:
        string go(VI& A, int t, string max = {}) {
            if (!t)
                return {}; // target sum reached ✅
            for (auto i{ 0 }; i < N; ++i) {
                if (t - A[i] < 0)
                    continue; // A[i] exceeds target sum ❌
                auto cand = go(A, t - A[i]);
                if (cand == "invalid")
                    continue; // target sum not reached ❌
                cand.push_back('0' + i + 1); // +1 for 1-based indexing
                if (max.size() < cand.size() || (max.size() == cand.size() && max < cand))
                    max = cand; // max candidate 🎯
            }
            return max.empty() ? "invalid" : max; // if max is empty, then t > 0 (ie. target sum not reached) ❌
        }
    };
}

namespace TopDownMemo { // AC
    class Solution {
    public:
        static constexpr auto N{ 9 };
        using VI = vector<int>;
        string largestNumber(VI& A, int T) {
            auto max = go(A, T);
            return max != "invalid" ? max : "0";
        }
    private:
        using Memo = unordered_map<int, string>;
        string go(VI& A, int t, Memo&& m = {}, string max = {}) {
            if (m.find(t) != m.end())
                return m[t];
            if (!t)
                return m[t] = {}; // target sum reached ✅
            for (auto i{ 0 }; i < N; ++i) {
                if (t - A[i] < 0)
                    continue; // A[i] exceeds target sum ❌
                auto cand = go(A, t - A[i], move(m));
                if (cand == "invalid")
                    continue; // target sum not reached ❌
                cand.push_back('0' + i + 1); // +1 for 1-based indexing
                if (max.size() < cand.size() || (max.size() == cand.size() && max < cand))
                    max = cand; // max candidate 🎯
            }
            return m[t] = max.empty() ? "invalid" : max; // if max is empty, then t > 0 (ie. target sum not reached) ❌
        }
    };
}

namespace TopDownMemo2 { // TLE
    class Solution {
    public:
        static constexpr auto N{ 9 };
        using VI = vector<int>;
        string largestNumber(VI& A, int T, string path = {}) {
            VI m(T + 1, -1);
            m[0] = 0;
            go(A, T, m);
            if (m[T] == -1)
                return "0"; // target sum not reached ❌
            for (auto i{ N - 1 }, t{ T }; 0 <= i; --i)
                while (0 <= t - A[i] && m[t] == 1 + m[t - A[i]])
                    path.push_back('0' + i + 1), // +1 for 1-based indexing
                    t -= A[i];
            return path; // reconstructed path 🎯
        }
    private:
        int go(VI& A, int t, VI& m) {
            if (m[t] > -1)
                return m[t];
            if (!t)
                return m[t] = 0;  // target sum reached ✅
            for (auto i{ 0 }; i < N; ++i) {
                if (t - A[i] < 0)
                    continue; // A[i] exceeds target sum ❌
                auto cand = go(A, t - A[i], m);
                if (cand > -1)
                    m[t] = max(m[t], 1 + cand);
            }
            return m[t];
        }
    };
}

namespace BottomUp {
    class Solution {
    public:
        static constexpr auto N{ 9 };
        using VI = vector<int>;
        string largestNumber(VI& A, int T, string path = {}) {
            VI dp(T + 1, -1);
            dp[0] = 0; // target sum 0 is reached with 0 digits ✅
            for (auto t{ 1 }; t <= T; ++t)
                for (auto i{ 0 }; i < N; ++i)
                    if (0 <= t - A[i] && dp[t - A[i]] > -1)
                        dp[t] = max(dp[t], 1 + dp[t - A[i]]);
            if (dp[T] == -1)
                return "0"; // target sum not reached ❌
            for (auto i{ N - 1 }, t{ T }; 0 <= i; --i)
                while (0 <= t - A[i] && dp[t] == 1 + dp[t - A[i]])
                    path.push_back('0' + i + 1), // +1 for 1-based indexing
                            t -= A[i];
            return path; // reconstructed path 🎯
        }
    };
}

int main() {
    TopDownMemo2::Solution solution;
    TopDownMemo2::Solution::VI A{4,3,2,5,6,7,2,5,5};
//    BottomUp::Solution solution;
//    BottomUp::Solution::VI A{4,3,2,5,6,7,2,5,5};
    cout << solution.largestNumber(A, 9) << endl;
    return 0;
}
