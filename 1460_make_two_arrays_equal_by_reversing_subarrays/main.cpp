/*
 * 1460. Make Two Arrays Equal by Reversing Sub-arrays
 *
 * Q: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/
 * A: https://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/discuss/660539/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace CountFrequency {
    class Solution {
    public:
        using VI = vector<int>;
        using Map = unordered_map<int, int>;
        bool canBeEqual(VI& T, VI& A, Map m = {}) {
            for (auto x: T) ++m[x];
            for (auto x: A) --m[x];
            return all_of(m.begin(), m.end(), [](auto& pair) { return !pair.second; });
        }
    };
}

namespace SortAndCompare {
    class Solution {
    public:
        using VI = vector<int>;
        bool canBeEqual(VI& A, VI& B) {
            sort(A.begin(), A.end());
            sort(B.begin(), B.end());
            return A == B;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
