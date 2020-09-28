/*
 * 453. Minimum Moves to Equal Array Elements
 *
 * Q: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
 * A: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/discuss/492864/Javascript-Python3-C%2B%2B-Min-Element
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int minMoves(VI& A) {
        auto low = *min_element(A.begin(), A.end());
        return accumulate(A.begin(), A.end(), 0, [=](auto total, auto x) { return total + x - low; });
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
