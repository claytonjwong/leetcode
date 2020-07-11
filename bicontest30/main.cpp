/*
 * https://leetcode.com/contest/biweekly-contest-30/ranking/76/
 * https://www.youtube.com/watch?v=ga0jkKfRGDo&feature=youtu.be
 *
 * Rank          Name           Score   Finish Time    Q1 (3)     Q2 (4)     Q3 (5)	      Q4 (6)
 * 1885 / 8174   claytonjwong   12      0:33:31        0:04:41    0:11:16    0:23:31 *2
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

/*
 * 1507. Reformat Date
 *
 * Q: https://leetcode.com/problems/reformat-date/
 * A: https://leetcode.com/problems/reformat-date/discuss/730585/Javascript-and-C%2B%2B-solutions
 */
namespace Question1 {
    class Solution {
    public:
        string reformatDate(string date, string d = {}, string m = {}, string y = {}) {
            istringstream is{ date };
            is >> d >> m >> y;
            d = d.substr(0, d.size() - 2);
            if (d.size() == 1)
                d = "0" + d;
            if (m == "Jan") m = "01";
            if (m == "Feb") m = "02";
            if (m == "Mar") m = "03";
            if (m == "Apr") m = "04";
            if (m == "May") m = "05";
            if (m == "Jun") m = "06";
            if (m == "Jul") m = "07";
            if (m == "Aug") m = "08";
            if (m == "Sep") m = "09";
            if (m == "Oct") m = "10";
            if (m == "Nov") m = "11";
            if (m == "Dec") m = "12";
            return y.append("-").append(m).append("-").append(d);
        }
    };
}

/*
 * 1508. Range Sum of Sorted Subarray Sums
 *
 * Q: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
 * A: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/discuss/730561/Javascript-and-C%2B%2B-solutions
 */
namespace Question2 {
    class Solution {
    public:
        using VI = vector<int>;
        int rangeSum(VI& A, int N, int L, int R, VI sums = {}, int mod = 1e9 + 7, int ans = 0) {
            for (auto i{ 0 }; i < N; ++i) {
                auto sum{ 0 };
                for (auto j{ i }; j < N; ++j)
                    sums.push_back(sum = (sum + A[j]) % mod);
            }
            sort(sums.begin(), sums.end());
            for (auto i{ L - 1 }; i <= R - 1; ++i) // -1 for 1-based indexing to 0-based indexing
                ans = (ans + sums[i]) % mod;
            return ans;
        }
    };
}

/*
 * 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
 *
 * Q: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/
 * A: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/discuss/730531/Javascript-and-C%2B%2B-solutions
 * A: https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/discuss/731233/Similar-to-1423.-Maximum-Points-You-Can-Obtain-from-Cards
 */
namespace Question3_Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        using LL = long long;
        using Deque = deque<LL>;
        int minDifference(VI& nums, LL min = numeric_limits<LL>::max()) {
            Deque A{ nums.begin(), nums.end() };
            auto minDiff = [&](auto i, auto j) {
                if (j < i)
                    return 0LL;
                return *max_element(i, j) - *min_element(i, j);
            };
            sort(A.begin(), A.end());
            for (auto i{ 0 }; i < 3; ++i) {
                min = std::min({ min, minDiff(A.begin(), A.begin() + (A.size() - 3)), minDiff(A.begin() + 3, A.end()) });
                A.push_front(A.back()), A.pop_back();
            }
            return min;
        }
    };
}
namespace Question3_Concise {
    class Solution {
    public:
        using VI = vector<int>;
        static constexpr int INF = 2e9 + 7;
        int minDifference(VI& A, int min = INF) {
            sort(A.begin(), A.end());
            int N = A.size(),
                i = 0,
                j = N - 4;
            while (0 <= j && j < N)
                min = std::min(min, A[j++] - A[i++]); // slide window by 3 👉
            return min < INF ? min : 0;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
