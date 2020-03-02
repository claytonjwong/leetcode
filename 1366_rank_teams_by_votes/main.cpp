/*
 * 1366. Rank Teams by Votes
 *
 * Q: https://leetcode.com/problems/rank-teams-by-votes/
 * A: https://leetcode.com/problems/rank-teams-by-votes/discuss/526803/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using VI = vector<int>;
    using VVI = vector<VI>;
    string rankTeams(VS& A, string ans = {}) {
        int M = A.size(),
            N = A[0].size();
        VVI m(26, VI(26 + 1));
        for (auto c: A[0])
            m[c - 'A'][26] = c;
        for (auto i = 0; i < M; ++i)
            for (auto j = 0; j < N; ++j)
                --m[A[i][j] - 'A'][j];
        m.erase(remove_if(m.begin(), m.end(), [](auto& a) { return a[26] == 0; }), m.end());
        sort(m.begin(), m.end());
        transform(m.begin(), m.end(), back_inserter(ans), [=](auto& a) { return a[26]; });
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> A{"ABC","ACB","ABC","ACB","ACB"};
    cout << solution.rankTeams(A) << endl;
    return 0;
}
