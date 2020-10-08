/*
 * 704. Binary Search
 *
 * Q: https://leetcode.com/problems/binary-search/
 * A: https://leetcode.com/problems/binary-search/discuss/600517/Javascript-Python3-C%2B%2B-Lower-Bound
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Concise {
    class Solution {
    public:
        using VI = vector<int>;
        int search(VI& A, int T) {
            auto it = lower_bound(A.begin(), A.end(), T);
            return it != A.end() && *it == T ? distance(A.begin(), it) : -1;
        }
    };
}

namespace Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        int search(VI& A, int T) {
            int N = A.size(),
                    i = 0,
                    j = N - 1;
            while (i < j) {
                auto k = (i + j) / 2;
                if (A[k] < T)
                    i = k + 1;
                else
                    j = k;
            }
            return A[i] == T ? i : -1;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
