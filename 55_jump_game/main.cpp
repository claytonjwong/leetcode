/*
 * 55. Jump Game
 *
 * Q: https://leetcode.com/problems/jump-game/
 * A: https://leetcode.com/problems/jump-game/discuss/143388/2-liner-C%2B%2B-(-EASY-to-understand-)-via-iterative-refactoring
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    bool canJump(VI& A, int max = 0) {
        int N = A.size(),
            T = N - 1; // target 🎯
        for (auto i{ 0 }; i < N && i <= max; ++i)
            max = std::max(max, i + A[i]);
        return T <= max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
