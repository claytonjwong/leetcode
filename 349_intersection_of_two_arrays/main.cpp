/*
 * 349. Intersection of Two Arrays
 *
 * Q: https://leetcode.com/problems/intersection-of-two-arrays/
 * A: https://leetcode.com/problems/intersection-of-two-arrays/discuss/614936/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Set = unordered_set<int>;
    VI intersection(VI& A, VI& B, Set ans = {}) {
        Set S{ A.begin(), A.end() };
        copy_if(B.begin(), B.end(), inserter(ans, ans.end()), [&](auto x) {
            return S.find(x) != S.end();
        });
        return { ans.begin(), ans.end() };
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
