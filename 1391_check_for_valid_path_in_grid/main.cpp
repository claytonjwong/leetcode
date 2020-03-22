/*
 * 1391. Check if There is a Valid Path in a Grid
 *
 * Q: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
 * A: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/discuss/547872/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

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


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
