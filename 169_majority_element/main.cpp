/*
 * 169. Majority Element
 *
 * Q: https://leetcode.com/problems/majority-element/
 * A: https://leetcode.com/problems/majority-element/discuss/618622/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    int majorityElement(VI& A, Map m = {}) {
        for (auto x: A) ++m[x];
        for (auto [x, cnt]: m)
            if (cnt > A.size() / 2)
                return x;
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
