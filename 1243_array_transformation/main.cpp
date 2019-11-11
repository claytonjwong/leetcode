/*
 * 1243. Array Transformation
 *
 * Q: https://leetcode.com/problems/array-transformation/
 * A: https://leetcode.com/problems/array-transformation/discuss/421590/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI transformArray(VI& A, bool change=false) {
        int N = A.size();
        do {
            change = false;
            VI B(N, 0);
            for (auto i=1; i + 1 < N; ++i)
                if (A[i-1] < A[i] && A[i] > A[i+1])
                    --B[i], change = true;
                else if (A[i-1] > A[i] && A[i] < A[i+1])
                    ++B[i], change = true;
            for (auto i=1; i + 1 < N; A[i] += B[i], ++i);
        } while (change);
        return A;
    }
};

int main() {
    Solution solution;
    Solution::VI A{6,3,4,4,5};
    auto ans = solution.transformArray(A);
    copy(ans.begin(), ans.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    return 0;
}
