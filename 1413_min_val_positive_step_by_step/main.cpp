/*
 * 1413. Minimum Value to Get Positive Step by Step Sum
 *
 * Q: https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
 * A: https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/discuss/588198/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int minStartValue(VI& A, int sum = 0, int min = 101) {
        for_each(A.begin(), A.end(), [&](auto x) { min = std::min(min, sum += x); });
        return max(1 - min, 1);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
