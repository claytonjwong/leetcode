/*
 * 939. Minimum Area Rectangle
 *
 * Q: https://leetcode.com/problems/minimum-area-rectangle/
 * A: https://leetcode.com/problems/minimum-area-rectangle/discuss/739671/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Map = unordered_map<int, unordered_set<int>>;
    static constexpr auto INF = int(1e9 + 7);
    int minAreaRect(VVI& A, Map m = {}, int min = INF) {
        int N = A.size();
        sort(A.begin(), A.end(), [](auto& a, auto& b) { return a[0] < b[0]; });
        for (auto& point: A) {
            auto [x, y] = tie(point[0], point[1]);
            m[x].insert(y);
        }
        for (auto i{ 0 }; i < N; ++i) {
            auto [x1, y1] = tie(A[i][0], A[i][1]);
            for (auto j{ i + 1 }; j < N; ++j) {
                auto [x2, y2] = tie(A[j][0], A[j][1]);
                if (y1 != y2)
                    continue;
                auto y = y1 = y2; // ⭐️ since y1 == y2, let's denote this same value as y
                for (auto cand: m[x1]) {
                    if (cand == y)
                        continue; // ❌ candidate cannot equal y (otherwise the area would be 0)
                    if (m[x2].find(cand) != m[x2].end())
                        min = std::min(min, (x2 - x1) * abs(cand - y)); // 🎯 minimum area rectangle
                }
            }
        }
        return min < INF ? min : 0;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
