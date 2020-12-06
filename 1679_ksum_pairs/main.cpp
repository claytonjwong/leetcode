/*
 * 1679. Max Number of K-Sum Pairs
 *
 * Q: https://leetcode.com/problems/max-number-of-k-sum-pairs/
 * A: https://leetcode.com/problems/max-number-of-k-sum-pairs/discuss/962118/Kt-Js-Py3-Cpp-Map
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    int maxOperations(VI& A, int k, Map m = {}, int pairs = 0) {
        for (auto x: A) {
            auto y = k - x;
            if (m.find(y) == m.end()) {
                ++m[x];
                continue;
            }
            ++pairs;
            if (!--m[y])
                m.erase(y);
        }
        return pairs;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
