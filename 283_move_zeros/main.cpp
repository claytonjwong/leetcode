/*
 * 283. Move Zeroes
 *
 * Q: https://leetcode.com/problems/move-zeroes/
 * A: https://leetcode.com/problems/move-zeroes/discuss/563206/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    void moveZeroes(VI& A) {
        int N = A.size();
        for (auto i{ 0 }, j{ 0 }; i < N; ++i) {
            if (A[i] == 0 && A[j] != 0) j = i; // j-th write index with value 0
            if (A[j] == 0 && A[i] != 0) swap(A[i], A[j++]); // set i-th value to j-th write index
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
