/*
 * 735. Asteroid Collision
 *
 * Q: https://leetcode.com/problems/asteroid-collision/
 * A: https://leetcode.com/problems/asteroid-collision/discuss/109683/Kt-Js-Py3-Cpp-Simulate-Collisions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI asteroidCollision(VI& pre, bool ok = true) {
        do {
            ok = true;
            VI cur;
            for (auto i{ 0 }; i < pre.size(); ++i) {
                // ✅ case 1: no collision
                if (cur.empty() || cur.back() < 0 || (0 <= cur.back() && 0 <= pre[i])) {
                    cur.push_back(pre[i]);
                    continue;
                }
                // 🚫 case 2: 💥 collision
                ok = false;
                auto last = cur.back(); cur.pop_back();
                if (abs(last) != abs(pre[i]))
                    cur.push_back(abs(last) < abs(pre[i]) ? pre[i] : last);
            }
            swap(pre, cur);
        } while (!ok);
        return pre;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
