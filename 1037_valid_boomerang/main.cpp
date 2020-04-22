/*
 * 1037. Valid Boomerang
 *
 * Q: https://leetcode.com/problems/valid-boomerang/
 * A: https://leetcode.com/problems/valid-boomerang/discuss/591227/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        bool isBoomerang(VVI& A) {
            auto [x1, y1] = tie(A[0][0], A[0][1]);
            auto [x2, y2] = tie(A[1][0], A[1][1]);
            auto [x3, y3] = tie(A[2][0], A[2][1]);
            return (x1 - x2) * (y1 - y3) != (x1 - x3) * (y1 - y2);
        }
    };
}
namespace OneLiner {
    class Solution {
    public:
        using VI = vector<int>;
        using VVI = vector<VI>;
        bool isBoomerang(VVI& A) {
            return (A[0][0] - A[1][0]) * (A[0][1] - A[2][1]) != (A[0][0] - A[2][0]) * (A[0][1] - A[1][1]);
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
