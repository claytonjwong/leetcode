/*
 * 1021. Remove Outermost Parentheses
 *
 * Q: https://leetcode.com/problems/remove-outermost-parentheses/
 * A: https://leetcode.com/problems/remove-outermost-parentheses/discuss/275804/Javascript-Python3-C%2B%2B-Stack-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string parens, string s = {}, string x = {}) {
        for (auto c: parens) {
            if (c == ')') s.pop_back();
            if (s.size()) x.push_back(c);
            if (c == '(') s.push_back(c);
        }
        return x;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
