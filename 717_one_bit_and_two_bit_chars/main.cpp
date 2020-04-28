/*
 * 717. 1-bit and 2-bit Characters
 *
 * Q: https://leetcode.com/problems/1-bit-and-2-bit-characters/
 * A: https://leetcode.com/problems/1-bit-and-2-bit-characters/discuss/600686/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    bool isOneBitCharacter(VI& A, int i = 0) {
        int N = A.size();
        while (i < N - 1)
            i += !A[i] ? 1 : 2;
        return i == N - 1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
