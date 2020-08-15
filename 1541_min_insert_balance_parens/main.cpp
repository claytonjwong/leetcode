/*
 * 1541. Minimum Insertions to Balance a Parentheses String
 *
 * Q: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/
 * A: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/discuss/793179/Javascript-Python3-C%2B%2B-double-'))'-or-single-')'
 */

#include <iostream>

using namespace std;

namespace Concise {
    class Solution {
    public:
        int minInsertions(string s, int x = 0, int cost = 0) {
            int N = s.size(),
                i = 0;
            auto doubleEnd = [&](auto i) { return s[i] == ')' && i + 1 < N && s[i + 1] == ')'; };
            while (i < N) {
                if (s[i] == '(') {                      // case '('  -> push to stack 🥞 (increment x count)
                    ++x;
                } else {
                    if (doubleEnd(i))                   // 🍔 🍔 '))' ->  0 penalty if ✅  preceeding '(' on the stack 🥞 (0 < x count)
                        cost += !x;                     //               +1 penalty if 🚫  preceeding '(' on the stack 🥞 (0 < x count)
                    else                                // 🍔    ')'  -> +1 penalty if ✅  preceeding '(' on the stack 🥞 (0 < x count)
                        cost += x ? 1 : 2;              //               +2 penalty if 🚫  preceeding '(' on the stack 🥞 (0 < x count)
                    x = x ? x - 1 : 0;                  // always pop the corresponding '(' from stack 🥞 (decrement x count) if it exists
                }
                i += doubleEnd(i) ? 2 : 1;              // skip past the 🍔 🍔 double '))' or 🍔 single ')'
            }
            return cost + (2 * x);                      // +2 penalty for each stack.length '(' remaining on the stack since each needs a 🍔 🍔 double '))'
        }
    };
}

namespace Verbose {
    class Solution {
    public:
        int minInsertions(string s, string stack = {}, int cost = 0) {
            int N = s.size(),
                i = 0;
            auto doubleEnd = [&](auto i) { return s[i] == ')' && i + 1 < N && s[i + 1] == ')'; };
            while (i < N) {
                if (s[i] == '(') {                      // case '('  -> push to stack 🥞 (increment x count)
                    stack.push_back('(');
                } else {
                    if (doubleEnd(i))                   // 🍔 🍔 '))' ->  0 penalty if ✅  preceeding '(' on the stack 🥞 (0 < x count)
                        cost += !stack.size();          //               +1 penalty if 🚫  preceeding '(' on the stack 🥞 (0 < x count)
                    else                                // 🍔    ')'  -> +1 penalty if ✅  preceeding '(' on the stack 🥞 (0 < x count)
                        cost += stack.size() ? 1 : 2;   //               +2 penalty if 🚫  preceeding '(' on the stack 🥞 (0 < x count)
                    if (stack.size())
                        stack.pop_back();               // always pop the corresponding '(' from stack 🥞 (decrement x count) if it exists
                }
                i += doubleEnd(i) ? 2 : 1;              // skip past the 🍔 🍔 double '))' or 🍔 single ')'
            }
            return cost + (2 * stack.size());           // +2 penalty for each stack.length '(' remaining on the stack since each needs a 🍔 🍔 double '))'
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
