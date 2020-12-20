/*
 * 1694. Reformat Phone Number
 *
 * Q: https://leetcode.com/problems/reformat-phone-number/
 * A: https://leetcode.com/problems/reformat-phone-number/discuss/978502/kt-js-py3-cpp-recursive-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    using fun = function<string(string&&)>;
    string reformatNumber(string s) {
        fun go = [&](auto s) {
            auto N = s.size();
            if (N <= 3) return s;
            if (N == 4) return s.substr(0, 2).append("-").append(s.substr(2));
            return s.substr(0, 3).append("-").append(go(s.substr(3)));
        };
        s.erase(remove_if(s.begin(), s.end(), [](auto c) { return c == ' ' || c == '-'; }), s.end());
        return go(move(s));
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
