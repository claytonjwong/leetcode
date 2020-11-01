/*
 * 1640. Check Array Formation Through Concatenation
 *
 * Q: https://leetcode.com/problems/check-array-formation-through-concatenation/
 * A: https://leetcode.com/problems/check-array-formation-through-concatenation/discuss/919391/Kt-Js-Py3-Cpp-Do-we-%22have%22-what-we-%22need%22
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Queue = queue<int>;
    bool canFormArray(VI& need, VVI& have, Queue q = {}) {
        for (auto x: need) {
            if (q.size()) {
                if (x != q.front())
                    return false;
                q.pop();
                continue;
            }
            auto found{ false };
            for (auto& piece: have) {
                if (x == piece[0]) {
                    found = true;
                    for (auto i{ 1 }; i < piece.size(); q.push(piece[i++]));
                    break;
                }
            }
            if (!found)
                return false;
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
