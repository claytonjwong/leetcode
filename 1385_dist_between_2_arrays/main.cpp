/*
 * 1385. Find the Distance Value Between Two Arrays
 *
 * Q: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
 * A: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/discuss/552420/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int findTheDistanceValue(VI& A, VI& B, int T) {
        return count_if(A.begin(), A.end(), [&](auto a) {
            return all_of(B.begin(), B.end(), [=](auto b) { return abs(a - b) > T; });
        });
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
