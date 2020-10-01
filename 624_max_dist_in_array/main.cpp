/*
 * 624. Maximum Distance in Arrays
 *
 * Q: https://leetcode.com/problems/maximum-distance-in-arrays/
 * A: https://leetcode.com/problems/maximum-distance-in-arrays/discuss/104653/Javascript-Python3-C%2B%2B-MinMax-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int maxDistance(VVI& A, int best = 0) {
        int N = A.size();
        auto lo = [&](auto i) { return A[i][0]; };
        auto hi = [&](auto i) { return A[i][A[i].size() - 1]; };
        auto min = lo(0),
             max = hi(0);
        for (auto i{ 1 }; i < N; ++i) {
            best = std::max({ best, abs(min - hi(i)), abs(max - lo(i)) });
            min = std::min(min, lo(i));
            max = std::max(max, hi(i));
        }
        return best;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
