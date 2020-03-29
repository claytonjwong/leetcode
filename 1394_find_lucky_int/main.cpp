/*
 * 1394. Find Lucky Integer in an Array
 *
 * Q1: https://leetcode.com/problems/find-lucky-integer-in-an-array/
 * A1: https://leetcode.com/problems/find-lucky-integer-in-an-array/discuss/554794/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    using Map = map<int, int>;
    using VI = vector<int>;
    int findLucky(VI& A, Map m = {}) {
        for (auto x: A)
            ++m[x];
        for (auto it = m.rbegin(); it != m.rend(); ++it) {
            auto [k, v] = tie(it->first, it->second);
            if (k == v)
                return v; // 🍀 lucky number 🍀
        }
        return -1;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
