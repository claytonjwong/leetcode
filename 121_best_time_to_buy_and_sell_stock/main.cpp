/*
 * 121. Best Time to Buy and Sell Stock
 *
 * Q: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * A: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/507318/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace MonotonicallyDecreasingStack {
    class Solution {
    public:
        using VI = vector<int>;
        int maxProfit(VI& A, VI stack = {}, int max = 0) {
            for (auto x: A) {
                if (stack.empty() || x < stack.back())
                    stack.push_back(x);
                max = std::max(max, x - stack.back());
            }
            return max;
        }
    };
}

namespace TrackMinimum {
    class Solution {
    public:
        using VI = vector<int>;
        int maxProfit(VI& A, int min = 1e9 + 7, int max = 0) {
            for (auto x: A) {
                min = std::min(min, x);
                max = std::max(max, x - min);
            }
            return max;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
