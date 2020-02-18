/*
 * 1337. The K Weakest Rows in a Matrix
 *
 * Q: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
 * A: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/discuss/513089/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using VVI = vector<VI>;
    VI kWeakestRows(VVI& A, int K, VVI S = {}, VI ans = {}) {
        for (auto i = 0; i < A.size(); ++i)
            S.push_back({accumulate(A[i].begin(), A[i].end(), 0), i});
        sort(S.begin(), S.end(), [](auto& a, auto& b){ return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0]; });
        transform(S.begin(), S.begin() + K, back_inserter(ans), [](auto& a){ return a[1]; });
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
