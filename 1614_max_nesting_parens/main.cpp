/*
 * 1614. Maximum Nesting Depth of the Parentheses
 *
 * Q: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
 * A: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/discuss/888880/Kt-Js-Py3-C%2B%2B-Count-Depth
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int maxDepth(string s, int cnt = 0, int best = 0) {
        for (auto c: s) {
            if (c == '(') ++cnt, best = max(best, cnt);
            if (c == ')') --cnt;
        }
        return best;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
