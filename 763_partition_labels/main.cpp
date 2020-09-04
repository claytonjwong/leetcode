/*
 * 763. Partition Labels
 *
 * Q: https://leetcode.com/problems/partition-labels/
 * A: https://leetcode.com/problems/partition-labels/discuss/828605/Javascript-Python3-C%2B%2B-Sliding-Window
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    VI partitionLabels(string S, Map m = {}, VI parts = {}) {
        auto N = S.size();
        for (auto i{ 0 }; i < N; m[S[i]] = i, ++i);              // 🚌 linear scan to find each char's right-most index
        for (auto i{ 0 }, j{ 0 }; i < N; i = ++j) {              // 👉 move i, j forward to beginning of next partition
            j = m[S[i]];
            for (auto k = i + 1; k < j; j = max(j, m[S[k++]]));  // 👉 slide window from i..j inclusive (expand j "as needed")
            parts.push_back(j - i + 1);                          // 🎯 partition found: +1 for i..j inclusive
        }
        return parts;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
