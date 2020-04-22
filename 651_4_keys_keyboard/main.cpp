/*
 * 651. 4 Keys Keyboard
 *
 * Q: https://leetcode.com/problems/4-keys-keyboard/
 * A: https://leetcode.com/problems/4-keys-keyboard/discuss/591314/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>

using namespace std;

namespace TopDownWithoutMemo {
    class Solution {
    public:
        int maxA(int N, int max = 0) {
            go(max, N);
            return max;
        }
    private:
        void go(int& max, int k, int val = 0, int buf = 0) {
            if (!k) {
                max = std::max(max, val);
                return;
            }
            go(max, k - 1, val + std::max(1, buf), buf);
            if (k >= 3)
                go(max, k - 3, 2 * val, val);
        }
    };
}
namespace TopDownWithMemo {
    class Solution {
    public:
        int maxA(int N, int max = 0) {
            go(max, N);
            return max;
        }
    private:
        using Seen = unordered_map<int, unordered_map<int, unordered_map<int, bool>>>;
        void go(int& max, int k, int val = 0, int buf = 0, Seen&& seen = {}) {
            if (!k) {
                max = std::max(max, val);
                return;
            }
            if (seen[k][val][buf])
                return;
            go(max, k - 1, val + std::max(1, buf), buf, move(seen));
            if (k >= 3)
                go(max, k - 3, val * 2, val, move(seen));
            seen[k][val][buf] = true;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
