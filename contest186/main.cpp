/*
 * https://leetcode.com/contest/weekly-contest-186/
 *
 * Rank            Name             Score     Finish Time   Q1 (3)       Q2 (4)        Q3 (5)    Q4 (6)
 * 4671 / 11684    claytonjwong     7         1:54:57       0:05:12 *1   1:29:57 *4
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

/*
 * 1422. Maximum Score After Splitting a String
 *
 * Q: https://leetcode.com/problems/maximum-score-after-splitting-a-string/
 * A: https://leetcode.com/problems/maximum-score-after-splitting-a-string/discuss/598801/Javascript-and-C%2B%2B-solutions
 */
namespace Question1_Count_Zero_and_One {
    class Solution {
    public:
        int maxScore(string S, int max = 0) {
            int N = S.size();
            int zero = S[0] == '0',
                 one = count_if(S.begin() + 1, S.end(), [](auto c) { return c == '1'; });
            for (auto i{ 1 }; i < N; ++i) {
                max = std::max(max, zero + one);
                zero += S[i] == '0';
                 one -= S[i] == '1';
            }
            return max;
        }
    };
}
namespace Question1_Prefix_Sums {
    class Solution {
    public:
        using VI = vector<int>;
        int maxScore(string S, VI A = {}, int max = 0) {
            transform(S.begin(), S.end(), back_inserter(A), [](auto c) { return c - '0'; });
            int N = A.size();
            VI L(N),
               R(N);
            for (auto i{ 0 }; i < N; ++i)
                L[i] = (A[i] == 0) + (i > 0 ? L[i - 1] : 0);     // prefix sums from 👉 (L)eft-to-right
            for (auto i{ N - 1 }; i >= 0; --i)
                R[i] = (A[i] == 1) + (i < N - 1 ? R[i + 1] : 0); // prefix sums from 👈 (R)ight-to-left
            for (auto i{ 1 }; i < N; ++i)
                max = std::max(max, L[i - 1] + R[i]);
            return max;
        }
    };
}

/*
 * 1423. Maximum Points You Can Obtain from Cards
 *
 * Q: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
 * A: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/discuss/597883/Javascript-and-C%2B%2B-solutions
 */
namespace Question2_ForLoop {
    class Solution {
    public:
        using VI = vector<int>;
        int maxScore(VI& A, int K) {
            int N = A.size();
            auto sum = accumulate(A.begin() + N - K, A.end(), 0),
                 max = sum;
            for (auto i{ 0 }, j{ N - K }; K--; max = std::max(max, sum += A[i++] - A[j++])); // slide window by K 👉
            return max;
        }
    };
}
namespace Question2_WhileLoop {
    class Solution {
    public:
        using VI = vector<int>;
        int maxScore(VI& A, int K) {
            int N = A.size(),
                i = 0,
                j = N - K;
            auto sum = accumulate(A.begin() + j, A.end(), 0),
                 max = sum;
            while (K--) max = std::max(max, sum += A[i++] - A[j++]); // slide window by K 👉
            return max;
        }
    };
}

int main() {

    return 0;
}
