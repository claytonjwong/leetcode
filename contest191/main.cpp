/*
 * https://leetcode.com/contest/weekly-contest-191
 *
 * Rank           Name            Score   Finish Time   Q1 (3)    Q2 (4)    Q3 (5)    Q4 (7)
 * 1323 / 9597    claytonjwong    12      0:44:22       0:01:54   0:12:44   0:44:22
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

/*
 * 1464. Maximum Product of Two Elements in an Array
 *
 * Q: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
 * A: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/discuss/661624/Javascript-and-C%2B%2B-solutions
 */
namespace Question1 {
    class Solution {
    public:
        using VI = vector<int>;
        int maxProduct(VI& A) {
            sort(A.begin(), A.end());
            return (A[A.size() - 2] - 1) * (A[A.size() - 1] - 1);
        }
    };
}

/*
 * 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
 *
 * Q: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
 * A: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/discuss/661630/Javascript-and-C%2B%2B-solutions
 */
namespace Question2 {
    namespace Verbose {
        class Solution {
        public:
            using VI = vector<int>;
            using LL = long long;
            struct {
                int row{ 0 }, col{ 0 };
            } max;
            int maxArea(int M, int N, VI& row, VI& col) {
                row.push_back(0), row.push_back(M); sort(row.begin(), row.end());
                col.push_back(0), col.push_back(N); sort(col.begin(), col.end());
                for (auto i{ 1 }; i < row.size(); ++i) max.row = std::max(max.row, row[i] - row[i - 1]);
                for (auto j{ 1 }; j < col.size(); ++j) max.col = std::max(max.col, col[j] - col[j - 1]);
                return LL(max.row) * LL(max.col) % int(1e9 + 7);
            }
        };
    }
    namespace STL {
        class Solution {
        public:
            using VI = vector<int>;
            using LL = long long;
            struct {
                VI row, col;
            } max;
            int maxArea(int M, int N, VI& row, VI& col) {
                row.push_back(0), row.push_back(M); sort(row.begin(), row.end());
                col.push_back(0), col.push_back(N); sort(col.begin(), col.end());
                adjacent_difference(row.begin(), row.end(), back_inserter(max.row));
                adjacent_difference(col.begin(), col.end(), back_inserter(max.col));
                return LL(*max_element(max.row.begin() + 1, max.row.end())) * LL(*max_element(max.col.begin() + 1, max.col.end())) % int(1e9 + 7);
            }
        };
    }
}

/*
 * 1466. Reorder Routes to Make All Paths Lead to the City Zero
 *
 * Q: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
 * A: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/discuss/661712/Javascript-and-C%2B%2B-solutions
 */
namespace Question3 {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        using Set = unordered_set<int>;
        using Map = unordered_map<int, Set>;
        using Roads = unordered_set<string>;
        int minReorder(int N, VVI& E, Map m = {}, Roads roads = {}, int ans = 0) {
            auto key = [](auto u, auto v) { stringstream ss; ss << u << "," << v; return ss.str(); };
            auto addRoad = [&](auto u, auto v) { roads.insert(key(u, v)); };
            auto hasRoad = [&](auto u, auto v) { return roads.find(key(u, v)) != roads.end(); };
            for (auto& edge: E) {
                auto [u, v] = tie(edge[0], edge[1]);
                m[u].insert(v);
                m[v].insert(u);
                addRoad(v, u);
            }
            queue<int> q{{ 0 }};
            Set seen{ 0 };
            while (!q.empty()) {
                auto u = q.front(); q.pop();
                for (auto v: m[u]) {
                    if (seen.find(v) != seen.end())
                        continue;
                    if (!hasRoad(u, v))
                        ++ans;
                    q.push(v), seen.insert(v);
                }
            }
            return ans;
        }
    };
}

int main() {
    std::cout << "Hello world" << std::endl;
    return 0;
}
