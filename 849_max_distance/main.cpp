/*
 * 849. Maximize Distance to Closest Person
 *
 * Q: https://leetcode.com/problems/maximize-distance-to-closest-person/
 * A: https://leetcode.com/problems/maximize-distance-to-closest-person/discuss/137957/Kt-Js-Py3-Cpp-Distance-from-LeftRight
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int maxDistToClosest(VI& A, int best = 0) {
        int N = A.size();
        VI L(N, N),
           R(N, N);
        if (A[0])
            L[0] = 0;
        if (A[N - 1])
            R[N - 1] = 0;
        for (auto i{ 1 }; i < N; ++i)
            L[i] = A[i] ? 0 : 1 + L[i - 1];  // distance from (L)eft-to-right 👉
        for (auto i{ N - 2 }; 0 <= i; --i)
            R[i] = A[i] ? 0 : 1 + R[i + 1];  // distance from (R)ight-to-left 👈
        for (auto i{ 0 }; i < N; ++i)
            best = max(best, min(L[i], R[i]));
        return best;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
