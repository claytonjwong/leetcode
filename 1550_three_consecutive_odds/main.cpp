/*
 * 1550. Three Consecutive Odds
 *
 * Q: https://leetcode.com/problems/three-consecutive-odds/
 * A: https://leetcode.com/problems/three-consecutive-odds/discuss/794079/Javascript-Python3-C%2B%2B-1-Liners-via-reduce()
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    bool threeConsecutiveOdds(VI& A) {
        return accumulate(A.begin(), A.end(), false, [i = -1, &A](auto found, auto _) mutable {
            return ++i < 2 ? found : found || ((A[i - 2] % 2) && (A[i - 1] % 2) && (A[i] % 2));
        });
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
