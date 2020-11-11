/*
 * 593. Valid Square
 *
 * Q: https://leetcode.com/problems/valid-square/
 * A: https://leetcode.com/problems/valid-square/discuss/932012/Kt-Js-Py3-Cpp-Map
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Map = unordered_map<int, int>;
    bool validSquare(VI& a, VI& b, VI& c, VI& d, Map m = {}) {
        auto f = [&](auto& a, auto& b) {
            auto [x1, y1] = tie(a[0], a[1]);
            auto [x2, y2] = tie(b[0], b[1]);
            return abs(x1 - x2) + abs(y1 - y2);
        };
        VVI A{ a, b, c, d };
        for (auto i{ 0 }; i < 4; ++i)
            for (auto j{ i + 1 }; j < 4; ++j)
                ++m[f(A[i], A[j])];
        return m.size() <= 2 && all_of(m.begin(), m.end(), [](auto& pair) {
            auto [x, cnt] = pair;
            return 0 < x && (cnt == 2 || cnt == 4 || cnt == 6);
        });
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
