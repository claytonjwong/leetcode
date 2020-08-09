/*
 * 1545. Find Kth Bit in Nth Binary String
 *
 * Q: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
 * A: https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/discuss/780890/Javascript-Python3-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    using fun = function<string(int)>;
    char findKthBit(int n, int k) {
        fun go = [&](int i) -> string {
            if (!i)
                return "0";
            auto pre = go(i - 1),
                 rev = pre;
            transform(rev.begin(), rev.end(), rev.begin(), [](auto c) { return c == '0' ? '1' : '0'; });
            return pre.append("1").append({ rev.rbegin(), rev.rend() });
        };
        return go(n - 1)[k - 1];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
