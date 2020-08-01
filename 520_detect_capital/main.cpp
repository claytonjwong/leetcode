/*
 * 520. Detect Capital
 *
 * Q: https://leetcode.com/problems/detect-capital/
 * A: https://leetcode.com/problems/detect-capital/discuss/766995/Javascript-Python3-C%2B%2B-1-Liners-%2B-Lambdas
 */

#include <iostream>

using namespace std;

namespace OneLiner {
    class Solution {
    public:
        bool detectCapitalUse(string s) {
            return all_of(s.begin(), s.end(), [](auto c) { return 97 <= c; }) ||
                   all_of(s.begin(), s.end(), [](auto c) { return c <= 90; }) ||
                   (s[0] <= 90 && all_of(s.begin() + 1, s.end(), [](auto c) { return 97 <= c; }));
        }
    };
}

namespace Lambdas {
    class Solution {
    public:
        using fun = function<bool(string)>;
        bool detectCapitalUse(string s) {
            fun lower = [](auto s) { return all_of(s.begin(), s.end(), [](auto c) { return 97 <= c; }); };
            fun upper = [](auto s) { return all_of(s.begin(), s.end(), [](auto c) { return c <= 90; }); };
            return lower(s) || upper(s) || (upper(s.substr(0, 1)) && lower(s.substr(1)));
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
