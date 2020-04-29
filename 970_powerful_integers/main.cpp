/*
 * 970. Powerful Integers
 *
 * Q: https://leetcode.com/problems/powerful-integers/
 * A: https://leetcode.com/problems/powerful-integers/discuss/601881/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Set = unordered_set<int>;
    VI powerfulIntegers(int x, int y, int T, Set ans = {}) {
        for (auto i{ 0 }; i <= 20; ++i) {
            for (auto j{ 0 }; j <= 20; ++j) {
                auto z = pow(x, i) + pow(y, j);
                if (z <= T)
                    ans.insert(z);
            }
        }
        return { ans.begin(), ans.end() };
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
