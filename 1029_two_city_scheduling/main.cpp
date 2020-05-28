/*
 * 1029. Two City Scheduling
 *
 * Q: https://leetcode.com/problems/two-city-scheduling/
 * A: https://leetcode.com/problems/two-city-scheduling/discuss/655880/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int twoCitySchedCost(VVI& A) {
        sort(A.begin(), A.end(), [](auto& a, auto& b) {
            return (a[0] - a[1]) - (b[0] - b[1]);
        });
        return accumulate(A.begin(), A.end(), 0, [i = -1, &A](int sum, auto& a) mutable {
            return ++i < A.size() ? a[0] : a[1];
        });
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
