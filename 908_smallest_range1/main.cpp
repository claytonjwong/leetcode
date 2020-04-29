/*
 * 908. Smallest Range I
 *
 * Q: https://leetcode.com/problems/smallest-range-i/
 * A: https://leetcode.com/problems/smallest-range-i/discuss/601852/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int smallestRangeI(VI& A, int K) {
        auto min = *min_element(A.begin(), A.end()) + K,
             max = *max_element(A.begin(), A.end()) - K;
        return max < min ? 0 : max - min;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
