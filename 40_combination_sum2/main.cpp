/*
 * 40. Combination Sum II
 *
 * Q: https://leetcode.com/problems/combination-sum-ii/
 * A: https://leetcode.com/problems/combination-sum-ii/discuss/506360/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI combinationSum2(VI& A, int T, VVI ans = {}) {
        sort(A.begin(), A.end());
        dfs(A, T, ans);
        return ans;
    }
private:
    using Seen = unordered_set<string>;
    void dfs(VI& A, int sum, VVI& ans, int start = 0, VI&& path = {}, Seen&& seen = {}) {
        if (sum == 0) {
            ostringstream key;
            copy(path.begin(), path.end(), ostream_iterator<int>(key, ","));
            if (seen.insert(key.str()).second)
                ans.push_back(path);
            return;
        }
        for (auto i = start; i < A.size(); ++i) {
            if (sum - A[i] >= 0) {
                path.push_back(A[i]);
                dfs(A, sum - A[i], ans, i + 1, move(path), move(seen));
                path.pop_back();
            }
        }
    }
};

int main() {
    Solution solution;
    Solution::VI A{2,5,2,1,2};
    auto target = 5;
    auto ans = solution.combinationSum2(A, target);
    for (auto& row: ans)
        copy(row.begin(), row.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
