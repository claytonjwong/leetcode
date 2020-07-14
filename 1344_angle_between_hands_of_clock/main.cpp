/*
 * 1344. Angle Between Hands of a Clock
 *
 * Q: https://leetcode.com/problems/angle-between-hands-of-a-clock/
 * A: https://leetcode.com/problems/angle-between-hands-of-a-clock/discuss/509782/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

namespace Concise {
    class Solution {
    public:
        double angleClock(int h, int m) {
            auto ans = abs((h % 12 * 30 + m / 2.0) - (m * 6));
            return min(ans, 360 - ans);
        }
    };
}

namespace Verbose {
    class Solution {
    public:
        double angleClock(int h, int m, double offset = 1e5) {
            if (h == 12)
                h = 0;
            h = offset * (30 * h + 0.5 * m);
            m = offset * (6 * m);
            auto degree = max(h, m) - min(h, m);
            return min(degree / offset, 360 - degree / offset);
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
