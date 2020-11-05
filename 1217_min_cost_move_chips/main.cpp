/*
 * 1217. Minimum Cost to Move Chips to The Same Position
 *
 * Q: https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
 * A: https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/discuss/399869/Kt-Js-Py3-Cpp-Minimum-Odd-and-Even
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Concise {
    class Solution {
    public:
        using VI = vector<int>;
        int minCostToMoveChips(VI& A) {
            return min(
                count_if(A.begin(), A.end(), [](auto x) { return  (x & 1); }),
                count_if(A.begin(), A.end(), [](auto x) { return !(x & 1); })
            );
        }
    };
}
namespace Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        int minCostToMoveChips(VI& A, int odd = 0, int even = 0) {
            for (auto x: A)
                if (x & 1)
                    ++odd;
                else
                    ++even;
            return min(odd, even);
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
