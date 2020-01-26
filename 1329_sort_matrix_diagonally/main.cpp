/*
 * 1329. Sort the Matrix Diagonally
 *
 * Q: https://leetcode.com/problems/sort-the-matrix-diagonally/
 * A: https://leetcode.com/problems/sort-the-matrix-diagonally/discuss/490185/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Map = unordered_map<int, unordered_map<int, VI>>;
    VVI diagonalSort(VVI& A, Map m = {}) {
        int M = A.size(),
            N = A[0].size();
        auto bucket = [](auto i, auto j) {
            auto offset = min(i, j);
            auto u = i - offset,
                 v = j - offset;
            return make_tuple(u, v);
        };
        for (auto i = 0; i < M; ++i) {
            for (auto j = 0; j < N; ++j) {
                auto [u, v] = bucket(i, j);
                m[u][v].push_back(A[i][j]);
            }
        }
        for (auto i = 0; i < M; ++i) sort(m[i][0].rbegin(), m[i][0].rend());
        for (auto j = 1; j < N; ++j) sort(m[0][j].rbegin(), m[0][j].rend());
        for (auto i = 0; i < M; ++i) {
            for (auto j = 0; j < N; ++j) {
                auto [u, v] = bucket(i, j);
                A[i][j] = m[u][v].back(), m[u][v].pop_back();
            }
        }
        return A;
    }
};

int main() {
    Solution solution;
    Solution::VVI A{
        {3,3,1,1},
        {2,2,1,2},
        {1,1,1,2}
    };
    auto ans = solution.diagonalSort(A);
    for (auto& row: ans)
        copy(row.begin(), row.end(), ostream_iterator<int>(cout, " ")), cout << endl;
    return 0;
}
