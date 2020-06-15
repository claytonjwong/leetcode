/*
 * 1480. Running Sum of 1d Array
 *
 * Q: https://leetcode.com/problems/running-sum-of-1d-array/
 * A: https://leetcode.com/problems/running-sum-of-1d-array/discuss/686233/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI runningSum(VI& A, int sum = 0, VI ans = {}) {
        transform(A.begin(), A.end(), back_inserter(ans), [&](auto x) { return sum += x; });
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
