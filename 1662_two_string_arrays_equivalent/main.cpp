/*
 * 1662. Check If Two String Arrays are Equivalent
 *
 * Q: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
 * A: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/discuss/948963/Kt-Js-Py3-Cpp-1-Liners
 */

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    using VS = vector<string>;
    bool arrayStringsAreEqual(VS& A, VS& B) {
        ostringstream osA, osB;
        copy(A.begin(), A.end(), ostream_iterator<string>(osA, ""));
        copy(B.begin(), B.end(), ostream_iterator<string>(osB, ""));
        return osA.str() == osB.str();
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
