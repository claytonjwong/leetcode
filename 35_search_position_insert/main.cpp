/*
 * 35. Search Insert Position
 *
 * Q: https://leetcode.com/problems/search-insert-position/
 * A: https://leetcode.com/problems/search-insert-position/discuss/680361/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int searchInsert(VI& A, int T) {
        int N = A.size(),
            i = 0,
            j = N - 1;
        while (i < j) {
            auto k = (i + j) / 2;
            if (T == A[k])
                return k;
            if (T > A[k]) i = k + 1;
            if (T < A[k]) j = k - 1;
        }
        return !N ? 0 : T <= A[i] ? i : i + 1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
