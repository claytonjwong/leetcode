/*
 * 1010. Pairs of Songs With Total Durations Divisible by 60
 *
 * Q: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
 * A: https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/discuss/256716/Kt-Js-Py3-Cpp-Map-of-Buckets
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    int numPairsDivisibleBy60(VI& A, Map m = {}, int pairs = 0) {
        transform(A.begin(), A.end(), A.begin(), [](auto x) { return x % 60; });
        for (auto x: A) {
            auto y = (60 - x) % 60;
            pairs += m[y];
            ++m[x];
        }
        return pairs;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
