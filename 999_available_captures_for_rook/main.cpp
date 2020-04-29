/*
 * 999. Available Captures for Rook
 *
 * Q: https://leetcode.com/problems/available-captures-for-rook/
 * A: https://leetcode.com/problems/available-captures-for-rook/discuss/602385/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VC = vector<char>;
    using VVC = vector<VC>;
    int numRookCaptures(VVC& A, int i = -1, int j = -1, int cnt = 0) {
        for (auto u{ 0 }; u < 8; ++u)
            for (auto v{ 0 }; v < 8; ++v)
                if (A[u][v] == 'R')
                    i = u, j = v;
        auto ok = [](auto x) { return 0 <= x && x < 8; };
        for (auto d: VVC{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}) { // // clockwise directions {👆, 👉, 👇, 👈}
            for (auto u = i + d[0], v = j + d[1]; ok(u) && ok(v); u += d[0], v += d[1]) {
                if (A[u][v] == 'p')
                    ++cnt; // black pawn 🎯
                if (A[u][v] != '.')
                    break; // non-empty square
            }
        }
        return cnt;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
