/*
 * https://leetcode.com/contest/biweekly-contest-33/ranking
 *
 * Rank            Name            Score    Finish Time    Q1 (3)     Q2 (4)    Q3 (5)    Q4 (6)
 * 4704 / 11366    claytonjwong    7        0:37:57        0:08:07    0:37:57
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

/*
 * 1556. Thousand Separator
 *
 * Q: https://leetcode.com/problems/thousand-separator/
 * A: https://leetcode.com/problems/thousand-separator/discuss/805674/Javascript-Python3-C%2B%2B-1-Liners
 */
namespace Question1 {
    class Solution {
    public:
        string thousandSeparator(int n) {
            return n < 1000 ? to_string(n) : thousandSeparator(n / 1000).append(".").append(string(3 - to_string(n % 1000).size(), '0').append(to_string(n % 1000)));
        }
    };
}

/*
 * 1557. Minimum Number of Vertices to Reach All Nodes
 *
 * Q: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
 * A: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/discuss/805698/Javascript-Python3-C%2B%2B-In-Degree-0
 */
namespace Question2 {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        VI findSmallestSetOfVertices(int N, VVI& E, VI ans = {}) {
            VI deg(N);
            for (auto& edge: E) {
                auto [_, tail] = tie(edge[0], edge[1]);
                ++deg[tail];
            }
            for (auto i{ 0 }; i < N; ++i)
                if (!deg[i])
                    ans.push_back(i);
            return ans;
        }
    };
}
namespace Question2_Simplified {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Set = unordered_set<int>;
        VI findSmallestSetOfVertices(int N, VVI& E) {
            VI nodes(N); iota(nodes.begin(), nodes.end(), 0);
            Set all{ nodes.begin(), nodes.end() };
            for (auto& edge: E) {
                auto [_, tail] = tie(edge[0], edge[1]);
                all.erase(tail);
            }
            return { all.begin(), all.end() };
        }
    };
}

// incorrect algorithm
namespace Question4 {
    class Solution {
    public:
        using Grid = vector<vector<char>>;
        using Seen = unordered_map<int, unordered_map<int, bool>>;
        using Dirs = vector<tuple<int, int>>;
        using fun = function<bool(int, int, int, int)>;
        bool containsCycle(Grid& A, Seen seen = {}) {
            int M = A.size(),
                    N = A[0].size();
            fun go = [&](int i, int j, int beg_i, int beg_j) {
                if (seen[i][j] && i == beg_i && j == beg_j)
                    return true;
                if (seen[i][j])
                    return false;
                seen[i][j] = true;
                for (auto [u, v]: Dirs{{i - 1, j}, {i, j + 1}, {i + 1, j}, {i, j - 1}}) {
                    if (!(u < 0 || u == M || v < 0 || v == N || seen[u][v] || A[u][v] != A[beg_i][beg_j]))
                        if (go(u, v, beg_i, beg_j))
                            return true;
                }
                return false;
            };
            for (auto i{ 0 }; i < M; ++i)
                for (auto j{ 0 }; j < N; ++j)
                    if (go(i, j, i, j))
                        return true;
            return false;
        }
    };
}

int main() {
    Question4::Solution solution;
    Question4::Solution::Grid A{{'a','b','b'},{'b','z','b'},{'b','b','a'}};
    cout << solution.containsCycle(A) << endl;
    return 0;
}
