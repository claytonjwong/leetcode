/*
 * 1007. Minimum Domino Rotations For Equal Row
 *
 * Q: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
 * A: https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/discuss/252219/Kt-Js-Py3-Cpp-Brute-Force
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int minDominoRotations(VI& A, VI& B, int INF = 1e9 + 7) {
        int N = A.size();
        auto rotate = [=](auto& cur, auto& alt, auto T) {
            auto cnt{ 0 };
            for (auto i{ 0 }; i < N; ++i) {
                if (cur[i] == T)
                    continue;
                if (alt[i] == T)
                    ++cnt;
                else
                    return INF;
            }
            return cnt;
        };
        VI cand{ rotate(A, B, A[0]), rotate(A, B, B[0]),
                 rotate(B, A, A[0]), rotate(B, A, B[0]) };
        return all_of(cand.begin(), cand.end(), [=](auto cnt) { return cnt == INF; }) ? -1 : *min_element(cand.begin(), cand.end());
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
