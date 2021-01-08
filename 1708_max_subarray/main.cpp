/*
 * 1708. Largest Subarray Length K
 *
 * Q: https://leetcode.com/problems/largest-subarray-length-k/
 * A: https://leetcode.com/problems/largest-subarray-length-k/discuss/1007617/Kt-Js-Py3-Cpp-Sliding-Window
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    using Queue = deque<int>;
    VI largestSubarray(VI& A, int K) {
        Queue cand{ A.begin(), A.begin() + K },
              best{ cand };
        for (auto i{ K }; i < A.size(); ++i) {
            cand.pop_front(), cand.push_back(A[i]);
            if (best < cand)
                best = cand;
        }
        return { best.begin(), best.end() };
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
