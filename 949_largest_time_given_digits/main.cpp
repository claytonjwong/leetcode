/*
 * 949. Largest Time for Given Digits
 *
 * Q: https://leetcode.com/problems/largest-time-for-given-digits/
 * A: https://leetcode.com/problems/largest-time-for-given-digits/discuss/666302/Javascript-and-C%2B%2B-solutions
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    using VI = vector<int>;
    string largestTimeFromDigits(VI& A, string max = {}) {
        sort(A.begin(), A.end());
        do {
            string h, m, _{" "};
            stringstream ss;
            ss << A[0] << A[1] << _; ss >> h;
            ss << A[2] << A[3] << _; ss >> m;
            if ("23" < h || "59" < m)
                continue;
            auto cand = h.append(":").append(m);
            if (max < cand)
                max = cand;
        } while (next_permutation(A.begin(), A.end()));
        return max;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
