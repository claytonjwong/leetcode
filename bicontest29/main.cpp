/*
 * https://leetcode.com/contest/biweekly-contest-29/ranking/63/
 *
 * Rank          Name           Score   Finish Time    Q1 (3)     Q2 (4)       Q3 (5)   Q4 (6)
 * 1567 / 7932   claytonjwong   12      0:21:44        0:01:27    0:05:57 *1   0:16:44
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <numeric>
#include <algorithm>
#include <iterator>

using namespace std;

/*
 * 1491. Average Salary Excluding the Minimum and Maximum Salary
 *
 * Q: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
 * A: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/discuss/708064/Javascript-and-C%2B%2B-solutions
 */
namespace Question1 {
    class Solution {
    public:
        using VI = vector<int>;
        double average(VI& A) {
            sort(A.begin(), A.end());
            return accumulate(A.begin() + 1, A.end() - 1, 0.0) / (A.size() - 2);
        }
    };
}

/*
 * 1492. The kth Factor of n
 *
 * Q: https://leetcode.com/problems/the-kth-factor-of-n/
 * A: https://leetcode.com/problems/the-kth-factor-of-n/discuss/708074/Javascript-and-C%2B%2B-solutions
 */
namespace Question2 {
    class Solution {
    public:
        int kthFactor(int N, int K) {
            for (auto i{ 1 }; i <= N; ++i)
                if (!(N % i) && !--K)
                    return i;
            return -1;
        }
    };
}

/*
 * 1493. Longest Subarray of 1's After Deleting One Element
 *
 * Q: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
 * A: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/discuss/708212/Javascript-and-C%2B%2B-solutions
 */
namespace Question3 {
    class Solution {
    public:
        using VI = vector<int>;
        int longestSubarray(VI& A, int max = 0) {
            int N = A.size();
            VI L(N),
               R(N);
            auto beg = 0,
                 end = N - 1;
            for (auto i{ beg }; i <  N; ++i) L[i] = A[i] ? (beg < i ? L[i - 1] + A[i] : A[i]) : 0; // prefix sums from Left-to-right 👉
            for (auto i{ end }; 0 <= i; --i) R[i] = A[i] ? (i < end ? R[i + 1] + A[i] : A[i]) : 0; // prefix sums from Right-to-left 👈
            for (auto i{ 0 }; i + 2 < N; ++i)
                max = std::max(max, L[i] + R[i + 2]); // maximum with a single gap 🎯
            return max;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
