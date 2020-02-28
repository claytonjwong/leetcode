/*
 * 54. Spiral Matrix
 *
 * Q: https://leetcode.com/problems/spiral-matrix/
 * A: https://leetcode.com/problems/spiral-matrix/discuss/521533/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Cell = tuple<int, int>;
    struct hash {
        size_t operator()(Cell c) const { auto [i, j] = c; return i * 123 + j; }
    };
    using Set = unordered_set<tuple<int, int>, hash>;
    VI spiralOrder(VVI& A, int i = 0, int j = 0, Set seen = {}, VI ans = {}) {
        int M = A.size(),
                N = M == 0 ? 0 : A[0].size();
        int dir = 0; VVI dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // clockwise: ( 👉, 👇, 👈, 👆 )
        while (seen.size() < M * N) {
            if (seen.insert({i, j}).second)
                ans.push_back(A[i][j]);
            auto u = i + dirs[dir][0],
                 v = j + dirs[dir][1];
            if (0 <= u && u < M && 0 <= v && v < N && seen.find({u, v}) == seen.end())
                i = u,
                j = v;
            else if (++dir == dirs.size())
                dir = 0;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    Solution::VVI A{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    auto ans = solution.spiralOrder(A);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
