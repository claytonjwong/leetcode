/*
 * 1094. Car Pooling
 *
 * Q: https://leetcode.com/problems/car-pooling/
 * A: https://leetcode.com/problems/car-pooling/discuss/857714/Javascript-Python3-C%2B%2B-Map-solutions
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Map = map<int, int>;
    bool carPooling(VVI& A, int K, Map m = {}, int total = 0) {
        for (auto& trip: A) {
            auto [n, i, j] = tie(trip[0], trip[1], trip[2]);
            m[i] += n;
            m[j] -= n;
        }
        for (auto [_, n]: m)
            if (K < (total += n))
                return false;
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
