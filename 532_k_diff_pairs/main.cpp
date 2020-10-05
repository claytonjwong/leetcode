/*
 * 532. K-diff Pairs in an Array
 *
 * Q: https://leetcode.com/problems/k-diff-pairs-in-an-array/
 * A: https://leetcode.com/problems/k-diff-pairs-in-an-array/discuss/596830/Javascript-Python3-C%2B%2B-Concise-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Seen = unordered_set<int>;
    using Set = unordered_set<string>;
    int findPairs(VI& A, int K, Seen seen = {}, Set pairs = {}) {
        auto pair = [&](auto a, auto b) {
            stringstream stream; stream << min(a, b) << ',' << max(a, b);
            pairs.insert(stream.str());
        };
        for (auto x: A) {
            if (seen.find(x + K) != seen.end()) pair(x, x + K);
            if (seen.find(x - K) != seen.end()) pair(x, x - K);
            seen.insert(x);
        }
        return pairs.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
