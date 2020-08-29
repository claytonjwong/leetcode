/*
 * 969. Pancake Sorting
 *
 * Q: https://leetcode.com/problems/pancake-sorting/
 * A: https://leetcode.com/problems/pancake-sorting/discuss/818425/Javascript-Python3-C%2B%2B-Insertion-Sort
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI pancakeSort(VI& A, VI flip = {}) {
        int N = A.size();
        for (auto i{ N - 1 }; 0 <= i; --i) {
            if (A[i] == i + 1)  // ✅ i-th max value already in i-th position
                continue;
            auto j = distance(A.begin(), find(A.begin(), A.end(), i + 1));
            flip.push_back(j + 1), reverse(A.begin(), A.begin() + j + 1);  // 1. move i-th max value to front
            flip.push_back(i + 1), reverse(A.begin(), A.begin() + i + 1);  // 2. move i-th max value to i-th position
        }
        return flip;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
