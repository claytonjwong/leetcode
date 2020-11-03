/*
 * 1481. Least Number of Unique Integers after K Removals
 *
 * Q: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
 * A: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/discuss/686410/Kt-Js-Py3-Cpp-Greedy-Drop-K-Least-Frequent-via-Map
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    using Set = unordered_set<int>;
    int findLeastNumOfUniqueInts(VI& A, int K, Map m = {}) {
        for (auto x: A) ++m[x];
        sort(A.begin(), A.end(), [&](auto a, auto b) { return m[a] == m[b] ? a < b : m[a] < m[b]; });
        return Set{ A.begin() + K, A.end() }.size();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
