/*
 * 1291. Sequential Digits
 *
 * Q: https://leetcode.com/problems/sequential-digits/
 * A: https://leetcode.com/problems/sequential-digits/discuss/455969/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using fun = function<void(int)>;
    VI sequentialDigits(int lo, int hi, VI ans = {}) {
        fun go = [&](int x) {
            if (hi < x)
                return;
            if (lo <= x)                 // 🎯 lo <= x <= hi
                ans.push_back(x);
            auto last = x % 10,
                    next = last + 1;
            if (next < 10)
                go(x * 10 + next);
        };
        for (auto i{ 1 }; i < 10; go(i++));
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
