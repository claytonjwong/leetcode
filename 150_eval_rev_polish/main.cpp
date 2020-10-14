/*
 * 150. Evaluate Reverse Polish Notation
 *
 * Q: https://leetcode.com/problems/evaluate-reverse-polish-notation/
 * A: https://leetcode.com/problems/evaluate-reverse-polish-notation/discuss/893409/Kt-Js-Py3-Cpp-Stack-(c-a-op-b)
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VS = vector<string>;
    int evalRPN(VS& A, VI S = {}) {
        auto is_number = [](auto& x) { return isdigit(x.front()) || (x[0] == '-' && 1 < x.size()); };
        for (auto& x: A) {
            if (is_number(x)) {
                istringstream stream{ x };
                int i; stream >> i;
                S.push_back(i);
                continue;
            }
            auto b = S.back(); S.pop_back();
            auto a = S.back(); S.pop_back();
            auto c = x == "+" ? a + b : x == "-" ? a - b : x == "*" ? a * b : a / b;
            S.push_back(c);
        }
        return S.back();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
