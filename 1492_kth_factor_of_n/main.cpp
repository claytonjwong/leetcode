/*
 * 1492. The kth Factor of n
 *
 * Q: https://leetcode.com/problems/the-kth-factor-of-n/
 * A: https://leetcode.com/problems/the-kth-factor-of-n/discuss/708074/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int kthFactor(int N, int K) {
        for (auto i{ 1 }; i <= N; ++i)
            if (!(N % i) && !--K)
                return i;
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
