/*
 * 1409. Queries on a Permutation With Key
 *
 * Q: https://leetcode.com/problems/queries-on-a-permutation-with-key/
 * A: https://leetcode.com/problems/queries-on-a-permutation-with-key/discuss/575943/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI processQueries(VI& queries, int N, VI ans = {}) {
        VI A(N); iota(A.begin(), A.end(), 1);
        for (auto j: queries) {
            auto i = distance(A.begin(), find(A.begin(), A.end(), j));
            for (ans.push_back(i); i > 0; --i)
                swap(A[i - 1], A[i]); // 👈 "bubble up" A[i] to the front of A
        }
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
