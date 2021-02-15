/*
 * 1758. Minimum Changes To Make Alternating Binary String
 *
 * Q: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
 * A: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/discuss/1064549/Kt-Js-Py3-Cpp-Explore-2-Candidates
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int minOperations(string s, int odd = 0, int a = 0, int b = 1, int first = 0, int second = 0) {
        for (auto c: s) {
            if (c - '0' == a) ++first;
            if (c - '0' == b) ++second;
            a ^= 1, b ^= 1;
        }
        return min(first, second);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
