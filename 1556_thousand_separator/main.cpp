/*
 * 1556. Thousand Separator
 *
 * Q: https://leetcode.com/problems/thousand-separator/
 * A: https://leetcode.com/problems/thousand-separator/discuss/805674/Javascript-Python3-C%2B%2B-1-Liners
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string thousandSeparator(int n) {
        return n < 1000 ? to_string(n) : thousandSeparator(n / 1000).append(".").append(string(3 - to_string(n % 1000).size(), '0').append(to_string(n % 1000)));
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
