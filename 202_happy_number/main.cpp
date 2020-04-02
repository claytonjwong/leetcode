/*
 * 202. Happy Number
 *
 * Q: https://leetcode.com/problems/happy-number/
 * A: https://leetcode.com/problems/happy-number/discuss/560627/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        return go(n);
    }
private:
    using Seen = unordered_set<int>;
    bool go(int x, Seen&& seen = {}) {
        if (x == 1) // target 🎯
            return true;
        if (!seen.insert(x).second) // x has already been seen ❌
            return false;
        auto next{ 0 };
        while (x) {
            auto d = x % 10;
            next += d * d;
            x /= 10;
        }
        return go(next, move(seen));
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
