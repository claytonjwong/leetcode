/*
 * 32. Longest Valid Parentheses
 *
 * Q: https://leetcode.com/problems/longest-valid-parentheses/
 * A: https://leetcode.com/problems/longest-valid-parentheses/discuss/513059/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int longestValidParentheses(string s, VI stack = {}, int ans = 0) {
        int N = s.size();
        VI valid(N);
        for (auto i = 0; i < N; ++i) {
            if (s[i] == '(')
                stack.push_back(i);
            if (s[i] == ')' && !stack.empty()) {
                auto j = stack.back();
                valid[i] = valid[j] = 1;
                stack.pop_back();
            }
        }
        for (auto i = 0; i < N; ++i) {
            if (!valid[i])
                continue;
            auto j = i;
            for (; j < N && valid[j]; ++j);
            ans = max(ans, j - i);
            i = j;
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
