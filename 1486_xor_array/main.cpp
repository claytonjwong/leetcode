/*
 * 1486. XOR Operation in an Array
 *
 * Q: https://leetcode.com/contest/weekly-contest-194/problems/xor-operation-in-an-array/
 * A: https://leetcode.com/problems/xor-operation-in-an-array/discuss/700800/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

class Solution {
public:
    int xorOperation(int N, int start, int ans = 0) {
        for (auto i{ 0 }; i < N; ++i)
            ans ^= start + 2 * i;
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
