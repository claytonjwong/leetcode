/*
 * https://leetcode.com/contest/weekly-contest-181/
 *
 * Rank           Name           Score   Finish Time    Q1 (3)    Q2 (4)      Q3 (5)      Q4 (6)
 * 2072 / 10930   claytonjwong   12      1:13:15        0:04:52   0:17:12 *1  1:03:15 *1
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <numeric>

using namespace std;

/*
 * 1389. Create Target Array in the Given Order
 *
 * Q: https://leetcode.com/problems/create-target-array-in-the-given-order/
 * A: https://leetcode.com/problems/create-target-array-in-the-given-order/discuss/547200/Javascript-and-C%2B%2B-solutions
 */

namespace Question1 {
    class Solution {
    public:
        using VI = vector<int>;
        VI createTargetArray(VI& nums, VI& index, VI ans = {}) {
            for (auto i{ 0 }; i < nums.size(); ++i)
                ans.insert(ans.begin() + index[i], nums[i]);
            return ans;
        }
    };
}


/*
 * 1390. Four Divisors
 *
 * Q: https://leetcode.com/problems/four-divisors/
 * A: https://leetcode.com/problems/four-divisors/discuss/547865/Javascript-and-C%2B%2B-solutions
 */

namespace Question2 {
    class Solution {
    public:
        using VI = vector<int>;
        using Set = unordered_set<int>;
        int sumFourDivisors(VI& A, int sum = 0) {
            auto getDivisors = [](auto x, Set divs = {}) {
                for (auto i{ 1 }; i <= sqrt(x); ++i)
                    if (x % i == 0)
                        divs.insert(i),
                        divs.insert(x / i);
                return divs;
            };
            for (auto x: A) {
                auto divs = getDivisors(x);
                if (divs.size() == 4)
                    sum += accumulate(divs.begin(), divs.end(), 0);
            }
            return sum;
        }
    };
}


/*
 * 1391. Check if There is a Valid Path in a Grid
 *
 * Q: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
 * A: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/discuss/547872/Javascript-and-C%2B%2B-solutions
 */

namespace Question3 {
    class Solution {
    public:
        using Grid = vector<vector<int>>;
        using Tuples = vector<vector<tuple<int, int>>>;
        using Set = unordered_set<string>;
        using Queue = queue<tuple<int, int>>;
        bool hasValidPath(Grid& A) {
            Tuples dir{
                    {},                  // 0 sentinel
                    {{ 0, -1}, { 0, 1}}, // 1 left  👈 / 👉 right
                    {{-1,  0}, { 1, 0}}, // 2 upper 👆 / 👇 lower
                    {{ 0, -1}, { 1, 0}}, // 3 left  👈 / 👇 lower
                    {{ 0,  1}, { 1, 0}}, // 4 right 👉 / 👇 lower
                    {{ 0, -1}, {-1, 0}}, // 5 left  👈 / 👆 upper
                    {{ 0,  1}, {-1, 0}}, // 6 right 👉 / 👆 upper
            };
            auto key = [](auto i, auto j) {
                stringstream ss; ss << i << "," << j;
                return ss.str();
            };
            int M = A.size(),
                N = A[0].size();
            Set seen{{"0,0"}};
            Queue q; q.push({0, 0});
            while (!q.empty()) {
                auto [m, n] = q.front(); q.pop();
                if (m == M - 1 && n == N - 1) // target 🎯
                    return true;
                auto cand = dir[A[m][n]]; // next candidates from current m,n
                for (auto [u, v]: cand) {
                    auto i = u + m, // next i
                         j = v + n; // next j
                    if (i < 0 || i >= M || j < 0 || j >= N || seen.find(key(i, j)) != seen.end())
                        continue;
                    auto next = dir[A[i][j]];
                    for (auto [a, b]: next)
                        if (a + i == m && b + j == n) // next i,j has incoming route from current m,n 👍
                            seen.insert(key(i, j)),
                            q.push({i, j});
                }
            }
            return false;
        }
    };
}

int main() {
    Question3::Solution solution;
    Question3::Solution::Grid A{
        {2,4,3},
        {6,5,2}
    };
    cout << solution.hasValidPath(A) << endl;
    return 0;
}
