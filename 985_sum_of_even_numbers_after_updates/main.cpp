/*
 * 985. Sum of Even Numbers After Queries
 *
 * Q: https://leetcode.com/problems/sum-of-even-numbers-after-queries/
 * A: https://leetcode.com/problems/sum-of-even-numbers-after-queries/discuss/602219/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VI sumEvenAfterQueries(VI& A, VVI& updates, VI ans = {}) {
        auto even = [](auto x) { return !(x % 2); };
        auto sum = accumulate(A.begin(), A.end(), 0, [&](auto a, auto b) {
            return even(b) ? a + b : a;
        });
        for (auto& u: updates) {
            auto [x, i] = tie(u[0], u[1]);
            sum -= even(A[i]) ? A[i] : 0;
            A[i] += x;
            sum += even(A[i]) ? A[i] : 0;
            ans.push_back(sum);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    Solution::VI A{1,2,3,4};
    Solution::VVI updates{{1,0},{-3,1},{-4,0},{2,3}};
    auto ans = solution.sumEvenAfterQueries(A, updates);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
