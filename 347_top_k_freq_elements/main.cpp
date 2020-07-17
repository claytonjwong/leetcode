/*
 * 347. Top K Frequent Elements
 *
 * Q: https://leetcode.com/problems/top-k-frequent-elements/
 * A: https://leetcode.com/problems/top-k-frequent-elements/discuss/740792/Javascript-Python3-C%2B%2B
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    using Pairs = vector<pair<int, int>>;
    VI topKFrequent(VI& A, int K, Map m = {}, VI ans = {}) {
        for (auto x: A) ++m[x];
        Pairs P{ m.begin(), m.end() };
        sort(P.begin(), P.end(), [](auto a, auto b) { return b.second < a.second; });
        transform(P.begin(), P.begin() + K, back_inserter(ans), [](auto& pair) { return pair.first; });
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
