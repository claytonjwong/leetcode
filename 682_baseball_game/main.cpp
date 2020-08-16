/*
 * 682. Baseball Game
 *
 * Q: https://leetcode.com/problems/baseball-game/
 * A: https://leetcode.com/problems/baseball-game/discuss/107929/C%2B%2B-and-Javascript-solutions
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    using VI = vector<int>;
    int calPoints(VS& ops, VI s = {}) {
        for (auto& op: ops) {
            int n = s.size();
            if (op == "+")
                s.push_back(s[n - 2] + s[n - 1]);
            else if (op == "D")
                s.push_back(2 * s[n - 1]);
            else if (op == "C")
                s.pop_back();
            else
                s.push_back(stoi(op));
        }
        return accumulate(s.begin(), s.end(), 0);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
