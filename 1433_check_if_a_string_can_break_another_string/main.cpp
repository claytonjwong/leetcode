/*
 * 1433. Check If a String Can Break Another String
 *
 * Q: https://leetcode.com/problems/check-if-a-string-can-break-another-string/
 * A: https://leetcode.com/problems/check-if-a-string-can-break-another-string/discuss/613490/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkIfCanBreak(string A, string B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        return all_of(A.begin(), A.end(), [i = 0, &A, &B](auto _) mutable { return A[i] <= B[i++]; })
            || all_of(B.begin(), B.end(), [i = 0, &A, &B](auto _) mutable { return B[i] <= A[i++]; });
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
