/*
 * 287. Find the Duplicate Number
 *
 * Q: https://leetcode.com/problems/find-the-duplicate-number/
 * A: https://leetcode.com/problems/find-the-duplicate-number/discuss/705081/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    int findDuplicate(VI& A) {
        sort(A.begin(), A.end());
        for (auto i{ 1 }; i < A.size(); ++i)
            if (A[i - 1] == A[i])
                return A[i];
        return -1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
