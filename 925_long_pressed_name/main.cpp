/*
 * 925. Long Pressed Name
 *
 * Q: https://leetcode.com/problems/long-pressed-name/
 * A: https://leetcode.com/problems/long-pressed-name/discuss/659364/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string A, string B) {
        int M = A.size(),
                N = B.size(),
                i{ 0 },
                j{ 0 };
        while (i < M && j < N) {
            auto cntA{ 0 },
                    cntB{ 0 };
            while (i + 1 < M && A[i] == A[i + 1]) ++i, ++cntA;
            while (j + 1 < N && B[j] == B[j + 1]) ++j, ++cntB;
            if (A[i] != B[j] || cntA > cntB)
                return false;
            ++i, ++j;
        }
        return i == M && j == N;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
