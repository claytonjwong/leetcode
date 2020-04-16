/*
 * 678. Valid Parenthesis String
 *
 * Q: https://leetcode.com/problems/valid-parenthesis-string/
 * A: https://leetcode.com/problems/valid-parenthesis-string/discuss/128527/Short-and-Simple-C%2B%2B-(-EASY-to-understand-)
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkValidString(string S) {
        return go(S);
    }
private:
    bool go(string& S, int i = 0, int open = 0) {
        if (i == S.size())
            return open == 0;
        if (open < 0)
            return false;
        if (S[i] == '(') return go(S, i + 1, open + 1);
        if (S[i] == ')') return go(S, i + 1, open - 1);
        return go(S, i + 1, open + 1) || go(S, i + 1, open - 1) || go(S, i + 1, open); // '(' || ')' || ''
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
