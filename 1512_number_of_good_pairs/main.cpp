/*
 * 1512. Number of Good Pairs
 *
 * Q: https://leetcode.com/problems/number-of-good-pairs/
 * A: https://leetcode.com/problems/number-of-good-pairs/discuss/731629/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int numIdenticalPairs(VI& A, int cnt = 0) {
        auto N = A.size();
        for (auto i{ 0 }; i < N; ++i)
            for (auto j{ i + 1 }; j < N; ++j)
                cnt += A[i] == A[j];
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
