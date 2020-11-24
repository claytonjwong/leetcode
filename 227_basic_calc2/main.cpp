/*
 * 227. Basic Calculator II
 *
 * Q: https://leetcode.com/problems/basic-calculator-ii/
 * A: https://leetcode.com/problems/basic-calculator-ii/discuss/947645/Kt-Js-Py3-Cpp-Stack
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    using Stack = vector<int>;
    int calculate(string expr, Stack S = {}, int x = 0, char op = '+') {
        auto N = expr.size();
        for (auto i{ 0 }; i <= N; ++i) {
            if (i < N && expr[i] == ' ')
                continue;
            if (i < N && isdigit(expr[i])) {
                x = 10 * x + (expr[i] - '0');
                continue;
            }
            if (op == '+') S.push_back(x);
            if (op == '-') S.push_back(-x);
            if (op == '*') S.back() *= x;
            if (op == '/') S.back() /= x;
            x = 0, op = i < N ? expr[i] : '?';
        }
        return accumulate(S.begin(), S.end(), 0);
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}
