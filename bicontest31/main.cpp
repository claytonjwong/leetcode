/*
 * https://leetcode.com/contest/biweekly-contest-31/ranking/106/
 *
 * Rank          Name           Score   Finish Time    Q1 (3)     Q2 (4)       Q3 (5)    Q4 (7)
 * 2636 / 8677   claytonjwong   12      1:16:49        0:05:09    1:11:49 *1   0:41:05
 *
 * Screenshare: https://www.youtube.com/watch?v=zdqg0ERZk_I&feature=youtu.be
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iterator>
#include <numeric>

using namespace std;

/*
 * 1523. Count Odd Numbers in an Interval Range
 *
 * Q: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
 * A: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/discuss/754764/Javscript-Python3-C%2B%2B-1-Liners
 */
namespace Question1 {
    class Solution {
    public:
        int countOdds(int i, int j) {
            return (j - i - 1) / 2 + (i % 2) + (j % 2) + (!(i % 2) && !(j % 2)) - (i == j);
        }
    };
}

/*
 * 1524. Number of Sub-arrays With Odd Sum
 *
 * Q: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
 * A: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/discuss/754751/Javascript-Python3-C%2B%2B-count-of-evenodd-sums
 */
namespace Question2 {
    class Solution {
    public:
        using VI = vector<int>;
        using LL = long long;
        using VLL = vector<LL>;
        int numOfSubarrays(VI& A, int sum = 0, VLL cnt = VLL{ 1, 0 }) {
            for (auto i{ 0 }; i < A.size(); ++i)
                ++cnt[(sum += A[i]) % 2];
            return (cnt[0] * cnt[1]) % int(1e9 + 7);
        }
    };
}

/*
 * 1525. Number of Good Ways to Split a String
 *
 * Q: https://leetcode.com/problems/number-of-good-ways-to-split-a-string/
 * A: https://leetcode.com/problems/number-of-good-ways-to-split-a-string/discuss/754776/Javascript-Python3-C%2B%2B-count-uniques-from-leftright
 */
namespace Question3 {
    class Solution {
    public:
        using VI = vector<int>;
        using Set = unordered_set<int>;
        struct Unique {
            Set L, R;
        };
        int numSplits(string s, Unique unique = {}, int cnt = 0) {
            int N = s.size(),
                beg = 0,
                end = N - 1;
            VI L(N),
               R(N);
            for (auto i{ beg }; i <  N; ++i) unique.L.insert(s[i]), L[i] = unique.L.size(); // unique counts from Left-to-right 👉
            for (auto j{ end }; 0 <= j; --j) unique.R.insert(s[j]), R[j] = unique.R.size(); // unique counts from Right-to-left 👈
            for (auto i{ 1 }; i < N; ++i)
                if (L[i - 1] == R[i])
                    ++cnt;
            return cnt;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
