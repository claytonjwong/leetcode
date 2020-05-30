/*
 * 973. K Closest Points to Origin
 *
 * Q: https://leetcode.com/problems/k-closest-points-to-origin/
 * A: https://leetcode.com/problems/k-closest-points-to-origin/discuss/660332/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VVI kClosest(VVI& A, int K) {
        partial_sort(A.begin(), A.begin() + K, A.end(), [](auto& a, auto& b) {
            return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
        });
        return { A.begin(), A.begin() + K };
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
