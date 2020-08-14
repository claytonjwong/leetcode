/*
 * 1342. Number of Steps to Reduce a Number to Zero
 *
 * Q: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
 * A: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/discuss/504160/Javascript-Python3-C%2B%2B-1-Liners
 */

#include <iostream>

class Solution {
public:
    int numberOfSteps (int x) {
        return !x ? 0 : 1 + numberOfSteps(x % 2 ? x - 1 : x / 2);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
