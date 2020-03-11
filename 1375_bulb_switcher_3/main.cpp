/*
 * 1375. Bulb Switcher III
 *
 * Q: https://leetcode.com/problems/bulb-switcher-iii
 * A: https://leetcode.com/problems/bulb-switcher-iii/discuss/532580/Javascript-solution
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int numTimesAllBlue(VI& A, int max = 0, int ans = 0) {
        for (auto i = 0; i < A.size(); ++i) {
            max = std::max(max, A[i]);
            if (max == i + 1)
                ++ans;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
