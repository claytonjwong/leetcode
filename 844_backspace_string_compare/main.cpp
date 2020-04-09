/*
 * 844. Backspace String Compare
 *
 * Q: https://leetcode.com/problems/backspace-string-compare/
 * A: https://leetcode.com/problems/backspace-string-compare/discuss/570905/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string A, string B) {
        auto gen = [](auto& S, string s = {}) {
            for (auto c: S)
                if (isalpha(c))
                    s.push_back(c);
                else if (!s.empty())
                    s.pop_back();
            return s;
        };
        return gen(A) == gen(B);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
