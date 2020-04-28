/*
 * 704. Binary Search
 *
 * Q: https://leetcode.com/problems/binary-search/
 * A: https://leetcode.com/problems/binary-search/discuss/600517/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int search(VI& A, int T) {
        int N = A.size(),
            i = 0,
            j = N - 1;
        while (i < j) {
            auto k = (i + j) / 2;
            if (A[k] < T)
                i = k + 1;
            else
                j = k;
        }
        return A[i] == T ? i : -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
