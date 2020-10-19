/*
 * 1620. Coordinate With Maximum Network Quality
 *
 * Q: https://leetcode.com/problems/coordinate-with-maximum-network-quality/
 * A: https://leetcode.com/problems/coordinate-with-maximum-network-quality/discuss/898691/Kt-Js-Py3-Cpp-Brute-Force
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VI bestCoordinate(VVI& A, int radius) {
        int N = A.size();
        VI quality(N);
        sort(A.begin(), A.end(), [](auto& a, auto& b) {       // lexicographical order
            auto [x1, y1, q1] = tie(a[0], a[1], a[2]);
            auto [x2, y2, q2] = tie(b[0], b[1], b[2]);
            return x1 == x2 ? y1 < y2 : x1 < x2;
        });
        auto dist = [](auto x1, auto x2, auto y1, auto y2) {  // euclidean distance
            auto x = abs(x1 - x2),
                 y = abs(y1 - y2);
            return sqrt(x * x + y * y);
        };
        for (auto i{ 0 }; i < N; ++i) {
            auto [x1, y1, q1] = tie(A[i][0], A[i][1], A[i][2]);
            quality[i] = q1;
            for (auto j{ 0 }; j < N; ++j) {
                if (i == j)
                    continue;
                auto [x2, y2, q2] = tie(A[j][0], A[j][1], A[j][2]);
                auto d = dist(x1, x2, y1, y2);
                if (radius < d)
                    continue;
                quality[i] += q2 / (1 + d);
            }
        }
        auto best = max_element(quality.begin(), quality.end());
        auto i = distance(quality.begin(), best);
        return { A[i].begin(), A[i].begin() + 2 };
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
