/*
 * 1313. Decompress Run-Length Encoded List
 *
 * Q: https://leetcode.com/problems/decompress-run-length-encoded-list/
 * A: https://leetcode.com/problems/decompress-run-length-encoded-list/discuss/479575/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    VI decompressRLElist(VI& A, VI ans = {}) {
        for (auto i = 1; i < A.size(); i += 2)
            fill_n(back_inserter(ans), A[i - 1], A[i]);
        return ans;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
