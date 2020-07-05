/*
 * 461. Hamming Distance
 *
 * Q: https://leetcode.com/problems/hamming-distance/
 * A: https://leetcode.com/problems/hamming-distance/discuss/721144/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

class Solution {
public:
    int hammingDistance(int a, int b) {
        return __builtin_popcount(a ^ b);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
