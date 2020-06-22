/*
 * 137. Single Number II
 *
 * Q: https://leetcode.com/problems/single-number-ii/
 * A: https://leetcode.com/problems/single-number-ii/discuss/700338/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    int singleNumber(VI& A, Map m = {}) {
        for (auto x: A)
            ++m[x];
        for (auto [x, cnt]: m)
            if (cnt == 1)
                return x;
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
