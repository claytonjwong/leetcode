/*
 * 441. Arranging Coins
 *
 * Q: https://leetcode.com/problems/arranging-coins/
 * A: https://leetcode.com/problems/arranging-coins/discuss/714525/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int arrangeCoins(int N, int rows = 0) {
        while (0 <= N - (rows + 1))
            N -= ++rows;
        return rows;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
