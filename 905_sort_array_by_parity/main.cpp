/*
 * 905. Sort Array By Parity
 *
 * Q: https://leetcode.com/problems/sort-array-by-parity/
 * A: https://leetcode.com/problems/sort-array-by-parity/discuss/172134/Javascript-Python3-C%2B%2B-1-Liners
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Deque = deque<int>;
    VI sortArrayByParity(VI& A, Deque ans = {}) {
        for (auto x: A) !(x & 1) ? ans.push_front(x) : ans.push_back(x);
        return { ans.begin(), ans.end() };
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
