/*
 * 1030. Matrix Cells in Distance Order
 *
 * Q: https://leetcode.com/problems/matrix-cells-in-distance-order/
 * A: https://leetcode.com/problems/matrix-cells-in-distance-order/discuss/602624/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI allCellsDistOrder(int R, int C, int x, int y, VVI ans = {}) {
        for (auto a{ 0 }; a < R; ++a)
            for (auto b{ 0 }; b < C; ++b)
                ans.push_back({a, b});
        sort(ans.begin(), ans.end(), [=](auto& a, auto& b) {
            auto [i, j] = tie(a[0], a[1]);
            auto [u, v] = tie(b[0], b[1]);
            return abs(i - x) + abs(j - y) < abs(u - x) + abs(v - y);
        });
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
