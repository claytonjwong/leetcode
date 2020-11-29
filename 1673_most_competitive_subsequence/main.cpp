/*
 * 1673. Find the Most Competitive Subsequence
 *
 * Q: https://leetcode.com/problems/find-the-most-competitive-subsequence/
 * A: https://leetcode.com/problems/find-the-most-competitive-subsequence/discuss/952775/Kt-Js-Py3-Cpp-Monotonic-Queue
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI mostCompetitive(VI& A, int K, VI S = {}) {
        int N = A.size(),
            i = 0;
        while (i < N)
            if (!S.empty() && A[i] < S.back() && i + K - S.size() < N)  // 📈 maintain monotonic queue invariant
                S.pop_back();
            else
                S.push_back(A[i++]);
        return { S.begin(), S.begin() + K };
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
