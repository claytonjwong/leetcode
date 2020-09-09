/*
 * 165. Compare Version Numbers
 *
 * Q: https://leetcode.com/problems/compare-version-numbers/
 * A: https://leetcode.com/problems/compare-version-numbers/discuss/838238/Javascript-Python3-C%2B%2B-solutions
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Iter = istream_iterator<int>;
    int compareVersion(string v1, string v2, VI A = {}, VI B = {}) {
        transform(v1.begin(), v1.end(), v1.begin(), [](auto c) { return c == '.' ? ' ' : c; });
        transform(v2.begin(), v2.end(), v2.begin(), [](auto c) { return c == '.' ? ' ' : c; });
        istringstream is1{ v1 }; copy(Iter(is1), Iter(), back_inserter(A));
        istringstream is2{ v2 }; copy(Iter(is2), Iter(), back_inserter(B));
        while (A.size() < B.size()) A.push_back(0);
        while (B.size() < A.size()) B.push_back(0);
        for (auto i{ 0 }; i < A.size(); ++i) {
            if (A[i] < B[i]) return -1;
            if (B[i] < A[i]) return  1;
        }
        return 0;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
