/*
 * 74. Search a 2D Matrix
 *
 * Q: https://leetcode.com/problems/search-a-2d-matrix/
 * A: https://leetcode.com/problems/search-a-2d-matrix/discuss/605294/Kt-Js-Py3-Cpp-Upper-Bound-(ie.-Binary-Search)
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    bool searchMatrix(VVI& A, int T, VI first = {}) {
        if (A.empty() || A[0].empty())
            return false;
        transform(A.begin(), A.end(), back_inserter(first), [](auto& row) { return row[0]; });
        auto row = int(distance(first.begin(), upper_bound(first.begin(), first.end(), T))) - 1;
        return 0 <= row ? binary_search(A[row].begin(), A[row].end(), T) : false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
