/*
 * 179. Largest Number
 *
 * Q: https://leetcode.com/problems/largest-number/
 * A: https://leetcode.com/problems/largest-number/discuss/864389/Javascript-Python3-C%2B%2B-Concise-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VS = vector<string>;
    string largestNumber(VI& A, VS S = {}, ostringstream ans = ostringstream()) {
        if (all_of(A.begin(), A.end(), [](auto x) { return !x; }))
            return "0";
        for (auto x: A) S.emplace_back(to_string(x));
        sort(S.begin(), S.end(), [](auto& a, auto& b) { return b + a < a + b; });
        copy(S.begin(), S.end(), ostream_iterator<string>(ans, ""));
        return ans.str();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
