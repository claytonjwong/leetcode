/*
 * 20. Valid Parentheses
 *
 * Q: https://leetcode.com/problems/valid-parentheses/
 * A: https://leetcode.com/problems/valid-parentheses/discuss/9214/Kt-Js-Py3-Cpp-Stack
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string A, string s = {}) {
        for (auto c: A)
            if      (c == '(') s.push_back(')');
            else if (c == '[') s.push_back(']');
            else if (c == '{') s.push_back('}');
            else if (s.empty() || c != s.back())
                return false;
            else
                s.pop_back();
        return s.empty();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
