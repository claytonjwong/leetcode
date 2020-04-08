/*
 * 1122. Relative Sort Array
 *
 * Q: https://leetcode.com/problems/relative-sort-array/
 * A: https://leetcode.com/problems/relative-sort-array/discuss/568451/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    using Multiset = multiset<int>;
    VI relativeSortArray(VI& A, VI& order, Map m = {}, Multiset leftovers = {}, VI ans = {}) {
        for (auto x: order)
            m[x] = 0;
        for (auto x: A)
            if (m.find(x) != m.end())
                ++m[x];
            else
                leftovers.insert(x);
        for (auto x: order)
            fill_n(back_inserter(ans), m[x], x);
        copy(leftovers.begin(), leftovers.end(), back_inserter(ans));
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
