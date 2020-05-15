/*
 * 22. Generate Parentheses
 *
 * Q: https://leetcode.com/problems/generate-parentheses/
 * A: https://leetcode.com/problems/generate-parentheses/discuss/632525/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    VS generateParenthesis(int N, VS ans = {}) {
        go(ans, N);
        return ans;
    }
private:
    void go(VS& ans, int N, int open = 0, int close = 0, string&& path = {}) {
        if (path.size() == 2 * N) // target 🎯
            ans.push_back(path);
        if (open < N)     go(ans, N, open + 1, close, move(path + "("));
        if (open > close) go(ans, N, open, close + 1, move(path + ")"));
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
