/*
 * 1523. Count Odd Numbers in an Interval Range
 *
 * Q: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
 * A: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/discuss/754764/Javscript-Python3-C%2B%2B-1-Liners
 */

#include <iostream>

class Solution {
public:
    int countOdds(int i, int j) {
        return (j - i - 1) / 2 + (i % 2) + (j % 2) + (!(i % 2) && !(j % 2)) - (i == j);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
