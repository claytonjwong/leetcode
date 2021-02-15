/*
 * 1437. Check If All 1's Are at Least Length K Places Away
 *
 * Q: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
 * A: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/discuss/613577/Kt-Js-Py3-Cpp-Last-Seen-Index
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    bool kLengthApart(VI& A, int K, int last = -1e5) {
        for (auto i{ 0 }; i < A.size(); ++i) {
            if (!A[i])
                continue;
            auto ok = K < i - last; last = i;
            if (!ok)
                return false;
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
