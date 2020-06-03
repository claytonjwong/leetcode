/*
 * 27. Remove Element
 *
 * Q: https://leetcode.com/problems/remove-element/
 * A: https://leetcode.com/problems/remove-element/discuss/667292/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int removeElement(VI& A, int T, int j = 0) { // let j be the write index
        for (auto i{ 0 }; i < A.size(); ++i)
            if (A[i] != T)
                A[j++] = A[i];
        return j;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
