/*
 * 1470. Shuffle the Array
 *
 * Q: https://leetcode.com/problems/shuffle-the-array/
 * A: https://leetcode.com/problems/shuffle-the-array/discuss/674389/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

namespace Concise {
    class Solution {
    public:
        using VI = vector<int>;
        VI shuffle(VI& A, int K, int j = 0, VI ans = {}) {
            transform(A.begin(), A.end(), back_inserter(ans), [i = -1, &j, &A, K](auto _) mutable { return !(++i % 2) ? A[j++] : A[j + K - 1]; });
            return ans;
        }
    };
}
namespace Verbose {
    class Solution {
    public:
        using VI = vector<int>;
        VI shuffle(VI& A, int K, VI ans = {}) {
            for (auto i{ 0 }; i < K; ++i)
                ans.push_back(A[i]),
                ans.push_back(A[i + K]);
            return ans;
        }
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
