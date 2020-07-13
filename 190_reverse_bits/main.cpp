/*
 * 190. Reverse Bits
 *
 * Q: https://leetcode.com/problems/reverse-bits/
 * A: https://leetcode.com/problems/reverse-bits/discuss/734271/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t x, uint32_t y = 0) {
        for (auto i{ 0 }; i <= 31; ++i)
            if (x & (1 << i))
                y |= 1 << (31 - i);
        return y;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
