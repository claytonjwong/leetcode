/*
 * 1310. XOR Queries of a Subarray
 *
 * Q: https://leetcode.com/problems/xor-queries-of-a-subarray/
 * A: https://leetcode.com/problems/xor-queries-of-a-subarray/discuss/475371/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VI xorQueries(VI& A, VVI& queries, VI ans = {}) {
        auto N = A.size();
        VI X(N + 1);
        for (auto i = 1; i <= N; ++i)
            X[i] = X[i - 1] ^ A[i - 1];
        for (auto& q: queries) {
            auto [i, j] = tie(q[0], q[1]);
            ans.push_back(X[i] ^ X[j + 1]);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    Solution::VI A{1,3,4,8};
    Solution::VVI queries{{0,1},{1,2},{0,3},{3,3}};
    auto ans = solution.xorQueries(A, queries);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
