/*
 * 1351. Count Negative Numbers in a Sorted Matrix
 *
 * Q: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
 * A: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/discuss/510845/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    int countNegatives(VVI& A, int ans = 0) {
        for (auto& row: A)
            ans += count_if(row.begin(), row.end(), [](auto x){ return x < 0; });
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
