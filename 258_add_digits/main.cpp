/*
 * 258. Add Digits
 *
 * Q: https://leetcode.com/problems/add-digits/
 * A: https://leetcode.com/problems/add-digits/discuss/756944/Javascript-Python3-C%2B%2B-1-Liners
 */

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
    int sum(int x, int res = 0) {
        stringstream ss; ss << x;
        for (char c; ss >> c; res += c - '0');
        return res;
    }
public:
    int addDigits(int x) {
        return x < 10 ? x : addDigits(sum(x));
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
