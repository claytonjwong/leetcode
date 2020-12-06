/*
 * 1678. Goal Parser Interpretation
 *
 * Q: https://leetcode.com/problems/goal-parser-interpretation/
 * A: https://leetcode.com/problems/goal-parser-interpretation/discuss/962100/Kt-Js-Py3-Cpp-Linear-Scan-%2B-Last-Seen
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string interpret(string s, char last = 'x', string ans = {}) {
        for (auto c: s) {
            if (c == 'G') ans.push_back('G');
            if (c == ')') ans.append(last == '(' ? "o" : "al");
            last = c;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
