/*
 * 1051. Height Checker
 *
 * Q: https://leetcode.com/problems/height-checker/
 * A: https://leetcode.com/problems/height-checker/discuss/603571/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Functional {
    class Solution {
    public:
        using VI = vector<int>;
        int heightChecker(VI& A) {
            VI B{ A };
            sort(B.begin(), B.end());
            return count_if(A.begin(), A.end(), [i = -1, &A, &B](auto x) mutable { ++i; return A[i] != B[i]; });
        }
    };
}

namespace Procedural {
    class Solution {
    public:
        using VI = vector<int>;
        int heightChecker(VI& A, int diff = 0) {
            VI B{ A };
            sort(B.begin(), B.end());
            for (auto i{ 0 }; i < A.size(); ++i)
                diff += A[i] != B[i];
            return diff;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
