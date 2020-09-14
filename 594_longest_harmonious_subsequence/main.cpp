/*
 * 594. Longest Harmonious Subsequence
 *
 * Q: https://leetcode.com/problems/longest-harmonious-subsequence/
 * A: https://leetcode.com/problems/longest-harmonious-subsequence/discuss/846353/Javascript-Python3-C%2B%2B-Map-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    int findLHS(VI& A, Map m = {}, int max = 0) {
        for (auto x: A)
            ++m[x];
        for (auto& [x, _]: m)
            if (m.find(x - 1) != m.end())
                max = std::max(max, m[x - 1] + m[x]);
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
