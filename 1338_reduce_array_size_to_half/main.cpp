/*
 * 1338. Reduce Array Size to The Half
 *
 * Q: https://leetcode.com/problems/reduce-array-size-to-the-half/
 * A: https://leetcode.com/problems/reduce-array-size-to-the-half/discuss/514431/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Map = unordered_map<int, int>;
    using Set = multiset<int, greater<int>>;
    int minSetSize(VI& A, Map m = {}, Set cnt = {}, int del = 0, int ans = 0) {
        for (auto x: A) ++m[x];
        transform(m.begin(), m.end(), inserter(cnt, cnt.begin()), [](auto& pair){ return pair.second; });
        for (auto it = cnt.begin(); del < A.size() / 2; del += *it++, ++ans);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
