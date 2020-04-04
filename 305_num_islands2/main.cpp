/*
 * 305. Number of Islands II
 *
 * Q: https://leetcode.com/problems/number-of-islands-ii/
 * A: https://leetcode.com/problems/number-of-islands-ii/discuss/563274/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VI numIslands2(int M, int N, VVI& lands, int cnt = 0, VI ans = {}) {
        VI P(M * N, -1); // parent representatives: -1 is water and i-th row, j-th col is N * i + j
        for (auto& land: lands) {
            auto i = land[0],
                 j = land[1],
                 x = N * i + j;
            if (P[x] != -1) { // land already exists❗️
                ans.push_back(cnt);
                continue;
            }
            P[x] = x; // parent representative of itself
            ++cnt; // increment islands 👍
            for (auto& dir: VVI{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}) { // clockwise: { 👆, 👉, 👇, 👈 }
                auto u = i + dir[0],
                     v = j + dir[1],
                     y = N * u + v;
                if (u < 0 || u >= M || v < 0 || v >= N || P[y] == -1)
                    continue;
                x = find(P, x);
                y = find(P, y);
                if (x != y) {
                    P[x] = y; // arbitrary choice
                    --cnt; // decrement islands 👎
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
private:
    int find(VI& P, int x) {
        if (P[x] == x)
            return P[x];
        return P[x] = find(P, P[x]);
    }
};

int main() {
    Solution solution;
    Solution::VVI lands{ {0, 0}, {0, 1}, {1, 2}, {2, 1} };
    auto ans = solution.numIslands2(3, 3, lands);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
