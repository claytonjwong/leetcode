/*
 * 1529. Bulb Switcher IV
 *
 * Q: https://leetcode.com/problems/bulb-switcher-iv/
 * A: https://leetcode.com/problems/bulb-switcher-iv/discuss/755780/Javascript-Python3-C%2B%2B-count-bit-flips
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int minFlips(string s, char cur = '0', int cnt = 0) {
        for (auto c: s)
            if (cur != c)
                cur = c, ++cnt;
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
