/*
 * 1041. Robot Bounded In Circle
 *
 * Q: https://leetcode.com/problems/robot-bounded-in-circle/
 * A: https://leetcode.com/problems/robot-bounded-in-circle/discuss/294269/Javascript-Python3-C%2B%2B-Traverse-4x-%2B-Return-to-Origin
 */

#include <iostream>

using namespace std;

class Solution {
public:
    enum Dir { U, R, D, L };                                    // 🗺 clockwise directions
    bool isRobotBounded(string A, int K = 4, int dir = U) {
        auto [ x, y ] = make_tuple(0, 0);                       // 🌎 origin
        while (K--) {                                           // 🔍 can we return to 🌎 origin within 4 traversals?
            for (auto c: A) {
                if (c == 'G') {                                 // 🚀 step forward
                    if (dir == U) --x; if (dir == D) ++x;
                    if (dir == L) --y; if (dir == R) ++y;
                }
                if (c == 'L' && --dir < 0) dir = L;             // 👈 turn left
                if (c == 'R' && L < ++dir) dir = U;             // 👉 turn right
            }
            if (!x && !y)
                return true;                                    // 🎯 returned to 🌎 origin after 1, 2, or 4 traversals
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
