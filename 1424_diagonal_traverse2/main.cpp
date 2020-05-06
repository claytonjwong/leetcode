/*
 * 1424. Diagonal Traverse II
 *
 * Q: https://leetcode.com/problems/diagonal-traverse-ii/
 * A: https://leetcode.com/problems/diagonal-traverse-ii/discuss/615470/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    using Map = map<int, VI>;
    VI findDiagonalOrder(VVI& A, Map m = {}, VI ans = {}) {
        int M = A.size();
        for (auto i = M - 1; i >= 0; --i)
            for (auto j = int(A[i].size()) - 1; j >= 0; --j)
                m[i + j].push_back(A[i][j]);
        for (auto [_, diag]: m)
            ans.insert(ans.end(), diag.begin(), diag.end());
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
