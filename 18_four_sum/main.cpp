/*
 * 18. 4Sum
 *
 * Q: https://leetcode.com/problems/4sum/
 * A: https://leetcode.com/problems/4sum/discuss/506107/Javascript-and-C%2B%2B-solutions
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
    using Seen = unordered_set<string>;
    VVI fourSum(VI& A, int target, Seen seen = {}, VVI ans = {}) {
        int N = A.size();
        sort(A.begin(), A.end());
        for (auto i = 0; i + 3 < N; ++i) {
            for (auto j = i + 3; j < N; ++j) {
                auto u = i + 1,
                        v = j - 1;
                while (u < v) {
                    auto sum = A[i] + A[u] + A[v] + A[j];
                    if (sum == target) {
                        ostringstream key; key << A[i] << "," << A[u] << "," << A[v] << "," << A[j];
                        if (seen.insert(key.str()).second)
                            ans.emplace_back(VI{A[i], A[u], A[v], A[j]});
                        ++u;
                        --v;
                    }
                    else if (sum < target)
                        ++u;
                    else
                        --v;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    Solution::VI A{-2,-1,0,0,1,2};
    auto target = 0;
    auto ans = solution.fourSum(A, target);
    for (auto& row: ans)
        copy(row.begin(), row.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
