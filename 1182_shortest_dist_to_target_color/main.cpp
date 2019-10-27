/*

 1182. Shortest Distance to Target Color

 Q: https://leetcode.com/problems/shortest-distance-to-target-color/
 A: https://leetcode.com/problems/shortest-distance-to-target-color/discuss/401165/Javascript-and-C%2B%2B-Solutions

 */


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/*
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    static constexpr int INF = int(5*1e4 + 1);
    VI shortestDistanceColor(VI& colors, VVI& queries, VI ans={}) {
        int N = colors.size();
        VVI L(N+1, VI(3+1, INF)), // N+1 for dp recurrence offset by 1 and 3 colors, +1 since index 0 is unused
            R(N+1, VI(3+1, INF));
        for (auto i=0; i <= N; ++i) {
            for (auto j=1; j <= 3; ++j) {
                if (colors[i] == j)
                    L[i][j] = 0;
                else if (i > 0)
                    L[i][j] = L[i-1][j] < INF ? L[i-1][j] + 1 : INF;
            }
        }
        for (auto i=N-1; i >= 0; --i) {
            for (auto j=1; j <= 3; ++j) {
                if (colors[i] == j)
                    R[i][j] = 0;
                else if (i < N-1)
                    R[i][j] = R[i+1][j] < INF ? R[i+1][j] + 1 : INF;
            }
        }
        transform(queries.begin(), queries.end(), back_inserter(ans), [&](auto& q) {
            auto [i, j] = tie(q[0], q[1]);
            auto ans = min(L[i][j], R[i][j]);
            return ans < INF ? ans : -1;
        });
        return ans;
    }
};
*/

// oddly my "enhanced" version 'using sets to track the indices' results in TLE!
class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using VS = vector<set<int>>;
    VI shortestDistanceColor(VI& colors, VVI& queries, int INF=int(1e5), VI ans={}) {
        int N = colors.size();
        VS L(3+1), // 3 colors: 1,2,3, and index 0 is not used
           R(3+1);
        for (auto i=0; i < N; ++i) {
            auto j = colors[i];
            L[j].insert(i);
            R[j].insert(-i);
        }
        transform(queries.begin(), queries.end(), back_inserter(ans), [&](auto& q) {
            auto res = INF;
            auto [i, j] = tie(q[0], q[1]);
            auto l = lower_bound(L[j].begin(), L[j].end(), i),
                 r = lower_bound(R[j].begin(), R[j].end(), -i);
            if (l == L[j].end() && r == R[j].end() && !L[j].empty()) {
                auto max = max_element(L[j].begin(), L[j].end());
                res = abs(*max - i);
            }
            if (l != L[j].end())
                res = min(res, abs(*l - i));
            if (r != R[j].end())
                res = min(res, abs(*r + i));
            return res < INF ? res : -1;
        });
        return ans;
    }
};

int main() {
    Solution::VI colors1{1,1,2,1,3,2,2,3,3};
    Solution::VVI queries1{{1,3},{2,2},{6,1}};
    auto ans1 = Solution().shortestDistanceColor(colors1, queries1);
    copy(ans1.begin(), ans1.end(), ostream_iterator<int>(cout, " ")); cout << endl;

    Solution::VI colors2{1,2};
    Solution::VVI queries2{{0,3}};
    auto ans2 = Solution().shortestDistanceColor(colors2, queries2);
    copy(ans2.begin(), ans2.end(), ostream_iterator<int>(cout, " ")); cout << endl;

    Solution::VI colors3{1,2,3};
    Solution::VVI queries3{{0,1},{1,1},{2,1}};
    auto ans3 = Solution().shortestDistanceColor(colors3, queries3);
    copy(ans3.begin(), ans3.end(), ostream_iterator<int>(cout, " ")); cout << endl;

    Solution::VI colors4{2,1,2,2,1};
    Solution::VVI queries4{{2,1}};
    auto ans4 = Solution().shortestDistanceColor(colors4, queries4);
    copy(ans4.begin(), ans4.end(), ostream_iterator<int>(cout, " ")); cout << endl;

    return 0;
}
